#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Contatos.h"
#include <string>

class PessoaJ : public Contato
{
	private:
		
		string cnpj;
		string inscriE;
		string razaoS;
		
	protected:
	public:
		
		PessoaJ();
		PessoaJ(string nome,string endereco,string email,string cnpj,string inscriE,string razaoS);
		~PessoaJ();
	
		string getCnpj();
		string getInscriE();
		string getRazaoS();
	
	
		void setCnpj(string cnpj);
		void setInscriE(string inscriE);
		void setRazaoS(string razaoS);
	
		void Imprimir_Agenda();
};

#endif



