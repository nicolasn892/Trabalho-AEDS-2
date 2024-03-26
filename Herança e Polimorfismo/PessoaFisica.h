#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include "Contatos.h"
#include <string>

class PessoaF : public Contato
{
	private:
		
		string cpf;
		string data;
		string estado;
		
	protected:
	public:
		PessoaF();
		PessoaF(string nome,string endereco,string email,string cpf,string data,string estado);
		~PessoaF();
		
		string getCpf();
		string getData();
		string getEstado();
		
		void setCpf(string cpf);
		void setData(string data);
		void setEstado(string estado);	
		
		void Imprimir_Agenda();
	
};

#endif




