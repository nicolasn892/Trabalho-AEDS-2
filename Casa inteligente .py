import sounddevice as sd
import queue
import json
import serial
import vosk
import time
import os
import pyttsx3
import difflib

voz = pyttsx3.init()

def falar(mensagem):
    print("IA:", mensagem)
    voz.say(mensagem)
    voz.runAndWait()

vosk_model_path = os.path.expanduser("~/Área de trabalho/Teste1_Voz_ultimo/vosk-model-small-pt-0.3")
if not os.path.exists(vosk_model_path):
    falar("Modelo Vosk não encontrado. Encerrando.")
    exit()

model = vosk.Model(vosk_model_path)
q = queue.Queue()

print("Dispositivos de entrada de áudio disponíveis:")
devices = sd.query_devices()
for i, device in enumerate(devices):
    if device['max_input_channels'] > 0:
        print(f"{i}: {device['name']} - entradas: {device['max_input_channels']}")

indice_microfone = int(input("Digite o índice do microfone desejado: "))

# Testa taxas comuns
taxa_ok = None
for sr in [16000, 44100, 48000]:
    try:
        sd.InputStream(samplerate=sr, channels=1, dtype='int16', device=indice_microfone).close()
        taxa_ok = sr
        print(f"Taxa suportada: {sr}")
        break
    except Exception as e:
        print(f"Taxa NÃO suportada: {sr} ({e})")

if taxa_ok is None:
    falar("Nenhuma taxa de amostragem comum suportada pelo microfone.")
    exit()
else:
    sample_rate = taxa_ok

try:
    arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    time.sleep(2)
except serial.SerialException as e:
    falar(f"Erro ao conectar na porta serial: {e}")
    exit()

def callback(indata, frames, time, status):
    q.put(bytes(indata))

def ouvir(timeout=10):
    try:
        with sd.InputStream(samplerate=sample_rate, blocksize=8000, dtype='int16',
                            channels=1, callback=callback, device=indice_microfone):
            rec = vosk.KaldiRecognizer(model, sample_rate)
            start_time = time.time()
            while True:
                data = q.get()
                if rec.AcceptWaveform(data):
                    resultado = json.loads(rec.Result())
                    print("DEBUG:", resultado)
                    texto = resultado.get("text", "").lower()
                    if texto:
                        return texto
                if time.time() - start_time > timeout:
                    falar("Tempo de escuta expirou. Tente novamente.")
                    return ""
    except Exception as e:
        print("Erro ao acessar o microfone:", e)
        falar("Erro ao acessar o microfone.")
        return ""

def interpretar_comando(texto):
    comandos = {
        "ligar luz da sala": "S",
        "desligar luz da sala": "s",
        "ligar luz do quarto": "Q",
        "desligar luz do quarto": "q",
        "ligar luz da cozinha": "C",
        "desligar luz da cozinha": "c",
        "abrir porta": "P",
        "fechar porta": "p",
        "abrir garagem": "G",
        "fechar garagem": "g"
    }
    if texto.strip() in ["ligar", "desligar", "abrir", "fechar"]:
        return "ESPECIFICAR", None
    lista_comandos = list(comandos.keys())
    melhor_match = difflib.get_close_matches(texto, lista_comandos, n=1, cutoff=0.6)
    if melhor_match:
        return comandos[melhor_match[0]], melhor_match[0]
    else:
        return "?", None

falar("Sistema pronto. Diga 'Olá' para começar.")
while True:
    texto = ouvir(timeout=10)
    if "olá" in texto:
        falar("Estou ouvindo! Diga seu comando.")
        while True:
            texto_comando = ouvir(timeout=10)
            if "obrigada ia" in texto_comando:
                falar("De nada! Até a próxima.")
                break
            comando, comando_texto = interpretar_comando(texto_comando)
            if comando == "ESPECIFICAR":
                falar("Por favor, especifique o local ou dispositivo. Por exemplo: 'ligar luz da sala'.")
            elif comando != "?":
                try:
                    print(f"Comando reconhecido: {comando_texto} -> Enviando: {comando}")
                    arduino.write((comando + '\n').encode())
                    falar("Comando enviado com sucesso!")
                except Exception as e:
                    falar(f"Erro de comunicação com o Arduino: {e}")
            else:
                falar("Desculpe, não entendi. Pode repetir?")
