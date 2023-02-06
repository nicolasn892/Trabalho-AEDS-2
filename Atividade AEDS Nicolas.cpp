#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#define naipe4 " DE PAUS"
#define naipe2 " DE ESPADAS"
#define naipe1 " DE OUROS"
#define naipe3 " DE COPAS"
typedef struct carta{
	char nome[30];
	int numero,naipe;
}carta;

typedef struct mao{
	carta *cartas;
}mao;

typedef struct jogador{
	char nome[30];
	int vidas,fazquantas;
	mao *m;
}jogador;

typedef struct baralho{
	carta *c;
	int topo;
}baralho;

typedef struct mesa{
	carta *c;
	int max,posmax;
}mesa;

jogador* inicializarjogadores(int n);
baralho* inicializarbaralho();
mesa* inicializarmesa();
void embaralhar(baralho *b);
void jogadas(jogador *j,baralho *b, int *quantidadedejogadores, int quantidadedecartas, int vezdojogador, mesa *m);
void jogarnamesa(jogador *j, int vezdojogador, int quantidadedecartas, int quantidadedejogadores, mesa *m);
void rodada(jogador *j, baralho *b, int quantidadedejogadores, int vezdojogador, int quantidadedecartas, mesa *m);
void printarcartas(jogador *j, int vezdojogador, int quantidadedecartas, int quantidadedejogadores);
void darascartas(jogador *j,baralho *b,int quantidadedecartas,int quantidadedejogadores, int vezdojogador);

int main(){
	int i,k,quantidadedejogadores,quantidadedecartas=5,vezdojogador=0;
	FILE *arquivo;
	arquivo = fopen("arquivo fedaputa.txt","w+");
	do{
		printf("Digite a quantidade de jogadores:");
		scanf("%d", &quantidadedejogadores);
		if(quantidadedejogadores<2 || quantidadedejogadores>8){
			printf("Quantidade de jogadores invalida.\n");
		}
	} while(quantidadedejogadores<2 || quantidadedejogadores>8);
	jogador *j=inicializarjogadores(quantidadedejogadores);
	baralho *b=inicializarbaralho();
	mesa *m=inicializarmesa();
	srand(time(NULL));
	jogadas(j,b,&quantidadedejogadores,quantidadedecartas,vezdojogador,m);
	fprintf(arquivo,"Jogador %s venceu!\n",j[vezdojogador].nome);
	printf("\n\n\nVENCEDOR: %s", j[0].nome);
	return 0;
}

jogador* inicializarjogadores(int n){ //Função para inicializar os jogadores
	jogador *j=(jogador*) malloc(n*sizeof(jogador));
	int i;
	for(i=0; i<n; i++){
		printf("Digite o nome do jogador %d: ", i+1);
		setbuf(stdin, NULL);
		fgets(j[i].nome, 30, stdin);
		j[i].vidas=5;
		j[i].m=(mao*)malloc(sizeof(mao));
	}
	return j;
}

baralho* inicializarbaralho(){ //Função para inicializar o baralho e atribuir peso para cada carta
	baralho *b=(baralho*)malloc(sizeof(baralho));
	b->c=(carta*)malloc(40*sizeof(carta));
	int i,j,aux=0,numerodacarta=1;
	for(i=0; i<10; i++){
		for(j=0; j<4; j++){
			if(numerodacarta==1){
				strcpy(b->c[aux].nome, "4");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].numero=14;
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==2){
				strcpy(b->c[aux].nome, "5");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==3){
				strcpy(b->c[aux].nome, "6");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==4){
				strcpy(b->c[aux].nome, "7");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].numero=11;
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].numero=13;
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==5){
				strcpy(b->c[aux].nome, "Q");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==6){
				strcpy(b->c[aux].nome, "J");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==7){
				strcpy(b->c[aux].nome, "K");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==8){
				strcpy(b->c[aux].nome, "A");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].numero=12;
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==9){
				strcpy(b->c[aux].nome, "2");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			} else if(numerodacarta==10){
				strcpy(b->c[aux].nome, "3");
				b->c[aux].numero=numerodacarta;
				if(j==0){
					strcat(b->c[aux].nome, naipe4);
					b->c[aux].naipe=4;
				} else if(j==1){
					strcat(b->c[aux].nome, naipe2);
					b->c[aux].naipe=2;
				} else if(j==2){
					strcat(b->c[aux].nome, naipe1);
					b->c[aux].naipe=1;
				} else if(j==3){
					strcat(b->c[aux].nome, naipe3);
					b->c[aux].naipe=3;
				}
			}
			aux++;
		}
		numerodacarta++;
	}
	b->topo=39;
	return b;
}

mesa* inicializarmesa(){ //Função para inicializar a mesa
	int i;
	mesa *m=(mesa*)malloc(sizeof(mesa));
	m->max=0;
	m->posmax=0;
	return m;
}

void jogadas(jogador *j,baralho *b, int *quantidadedejogadores, int quantidadedecartas, int vezdojogador, mesa *m){ //Função para controlar a quantidade de jogadores, quantidade de cartas e determinar a vez do jogador
	int i,k,n=0;
	do{
		for(i=0; i<*quantidadedejogadores; i++){ //Verifica se algum jogador não possui mais vidas 
			if(j[i].vidas<=0){
				*quantidadedejogadores--;
				for(k=i; k<*quantidadedejogadores; k++){ // Reorganização do vetor de jogadores
					j[k]=j[k+1];
				}
				realloc(j,*quantidadedejogadores*sizeof(jogador)); 
			}
		}
		rodada(j,b,*quantidadedejogadores,vezdojogador,quantidadedecartas,m);
		if(n==0){ //Controle da quantidade de cartas
			quantidadedecartas--;
			if(quantidadedecartas==1){
				n=1;
			}
		} else if(n==1){
			quantidadedecartas++;
			if(quantidadedecartas==5){
				n=0;
			}
		}
		if(vezdojogador==*quantidadedejogadores-1){ //Controle da vez do jogador
			vezdojogador=0;
		} else {
			vezdojogador+=1;
		}
	}while(*quantidadedejogadores>1);
	return;
}

void rodada(jogador *j, baralho *b, int quantidadedejogadores, int vezdojogador, int quantidadedecartas, mesa *m){ //Distribui as cartas e verifica quantas rodadas cada jogador irá fazer
	int i,aux=0,soma=0,saida=0;
	if(vezdojogador==quantidadedejogadores-1){
		vezdojogador=0;
	} else {
		vezdojogador+=1;
	}
	do{
		saida=0;
		printf("JOGADOR: %s\n", j[vezdojogador].nome);
		if(aux==0){ // As cartas serão dadas aos jogadores que em seguida serão perguntados quantas rodadas irão fazer
			darascartas(j,b,quantidadedecartas,quantidadedejogadores,vezdojogador);
		}
		printarcartas(j,vezdojogador,quantidadedecartas,quantidadedejogadores);
		printf("	Faz quantas?  \n");
		if(aux!=quantidadedejogadores-1){ //Checagem para ver se a quantidade de rodadas que o jogador irá fazer é válida
			do{
				scanf("%d", &j[vezdojogador].fazquantas);
				if(j[vezdojogador].fazquantas>quantidadedecartas){
					printf("Quantidade de rodadas feitas nao pode ser maior que a quantidade total de rodadas.\n");
					continue;
				} else {
					soma+=j[vezdojogador].fazquantas;
					saida=1;
				}
			} while(saida!=1);
		} else {
			do{
				scanf("%d", &j[vezdojogador].fazquantas);
				if(j[vezdojogador].fazquantas+soma==quantidadedecartas){
					printf("Quantidade de rodadas feitas nao pode ser igual a quantidade total de rodadas.\n");
					continue;
				} else {
					soma+=j[vezdojogador].fazquantas;
					saida=1;
				}
			} while(saida!=1);	
		}
		if(vezdojogador==quantidadedejogadores-1){
			vezdojogador=0;
		} else {
			vezdojogador+=1;
		}
		aux++;
	} while(aux!=quantidadedejogadores);
	jogarnamesa(j,vezdojogador,quantidadedecartas,quantidadedejogadores,m);
	return;
}

void jogarnamesa(jogador *j, int vezdojogador, int quantidadedecartas, int quantidadedejogadores, mesa *m){ //Função para os jogadores jogarem suas cartas na mesa
	int i,k,aux,numerodacarta,numerodacartamax,n=0,*quantasfez=(int*) malloc(quantidadedejogadores*sizeof(int)); 
	FILE *arquivo;
	arquivo = fopen("arquivo fedaputa.txt","w+");
	for(i=0; i<quantidadedejogadores; i++){ // inicialização da variável auxiliar para guardar quantas rodadas cada jogador fez
		quantasfez[i]=0;
	}
	m->c=(carta*)malloc(quantidadedejogadores*sizeof(carta)); 
	for(i=0; i<quantidadedecartas; i++){
		aux=0;
		m->max=0; //Variável para guardar a maior carta jogada na mesa
		m->posmax=0; //Variável para guardar qual jogador foi o que jogou a maior carta na mesa
		do{
			printf("JOGADOR: %s\n", j[vezdojogador].nome);
			printarcartas(j,vezdojogador,quantidadedecartas-i,quantidadedejogadores);
			printf("	Numero da carta a jogar:"); //Jogador irá escolher qual carta irá jogar
			scanf("%d", &numerodacarta);
			fprintf(arquivo,"Jogador %s usou a carta %d da sua mao\n",j[vezdojogador].nome,numerodacarta);
			m->c[aux]=j[vezdojogador].m->cartas[numerodacarta];
			if(m->max<m->c[aux].numero){ //checagem para ver se a carta é maior do que as outras anteriormente jogadas
				m->max=m->c[aux].numero;
				m->posmax=vezdojogador;
				numerodacartamax=numerodacarta;
			} else if(m->max==m->c[aux].numero){
				if(j[m->posmax].m->cartas[numerodacartamax].naipe<j[vezdojogador].m->cartas[numerodacarta].naipe){
					m->max=m->c[aux].numero;
					m->posmax=vezdojogador;
					numerodacartamax=numerodacarta;
				}
			}
			for(k=numerodacarta; k<quantidadedecartas; k++){ //Reorganização da mão do jogador
				j[vezdojogador].m->cartas[k]=j[vezdojogador].m->cartas[k+1];
			}
			if(vezdojogador==quantidadedejogadores-1){
				vezdojogador=0;
			} else {
				vezdojogador+=1;
			}
			aux++;
		} while(aux!=quantidadedejogadores);
		fprintf(arquivo,"Jogador %s fez a rodada!",j[vezdojogador].nome);
		printf("\nFEZ A RODADA O JOGADOR %s\n", j[m->posmax].nome);
		quantasfez[m->posmax]++;
	}
	for(i=0; i<quantidadedejogadores; i++){ //Checagem de todos os jogadores para ver quem irá perder vidas
		free(j[i].m->cartas);
		if(j[i].fazquantas!=quantasfez[i]){
			if(j[i].fazquantas>quantasfez[i]){
				j[i].vidas-=(j[i].fazquantas-quantasfez[i]);
			} else {
				j[i].vidas-=(quantasfez[i]-j[i].fazquantas);
			}
			fprintf(arquivo,"Jogador %s perdeu vida!\n",j[vezdojogador].nome);
			printf("PERDEU VIDA O JOGADOR %s", j[i].nome);
		}
	}
	free(quantasfez);
	free(m->c);
	return;
}

void embaralhar(baralho *b){ 
	int i,x;
	carta aux;
	for(i=0; i<40; i++){ // todas as cartas são trocadas por uma aleatória
		do{
			x=rand() % 40;
		} while(x==i);
		aux=b->c[x];
		b->c[x]=b->c[i];
		b->c[i]=aux;
	}
	return;
}

void printarcartas(jogador *j, int vezdojogador, int quantidadedecartas, int quantidadedejogadores){ //imprimir cartas de um determinado jogador
	int i;
	printf("	Cartas:\n");
	for(i=0; i<quantidadedecartas; i++){
		printf("		%d) %s\n", i,j[vezdojogador].m->cartas[i].nome);
	}
	return;
}

void darascartas(jogador *j, baralho *b, int quantidadedecartas, int quantidadedejogadores, int vezdojogador){ //Função para dar as cartas à todos jogadores
	int i,k;
	b->topo=39;
	embaralhar(b);
	for(i=0 ;i<quantidadedejogadores; i++){
		j[vezdojogador].m->cartas=(carta*)malloc(quantidadedecartas*sizeof(carta));
		for(k=0; k<quantidadedecartas; k++){
			j[vezdojogador].m->cartas[k]=b->c[b->topo];
			b->topo--;
		}
		if(vezdojogador==quantidadedejogadores-1){
			vezdojogador=0;
		} else {
			vezdojogador+=1;
		}
	}
	return;
}
