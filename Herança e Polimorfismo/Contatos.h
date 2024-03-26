#ifndef CONTATOS_H
#define CONTATOS_H

#include <string>
using namespace std;

class Contato
{
	private:
		string nome;
		string endereco;
		string email;
	
	
	
	protected:
	public:
		Contato();
		Contato(string nome,string endereco,string email);
		~Contato();
		
		
		string getNome();
		string getEndereco();
		string getEmail();
		
		void setNome(string nome);
		void setEndereco(string endereco);
		void setEmail(string email);
		
		virtual void Imprimir_Agenda();
		void Menu();
		
	
};

#endif


