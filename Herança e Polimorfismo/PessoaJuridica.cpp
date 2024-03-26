#include "PessoaJuridica.h"
#include <iostream>

PessoaJ::PessoaJ(){
}

PessoaJ::PessoaJ(string nome,string endereco,string email,string cnpj,string inscriE,string razaoS) : Contato(nome,endereco,email){
	 setCnpj(cnpj);
	 setInscriE(inscriE);
	 setRazaoS(razaoS);
}

PessoaJ::~PessoaJ(){
}
		
string PessoaJ::getCnpj(){
	return cnpj;
}
string PessoaJ::getInscriE(){
	return inscriE;
}
string PessoaJ::getRazaoS(){
	return razaoS;
}
	
void PessoaJ::setCnpj(string cnpj){
	this->cnpj = cnpj;
}
void PessoaJ::setInscriE(string inscriE){
	this->inscriE = inscriE;
}
void PessoaJ::setRazaoS(string razaoS){
	this->razaoS = razaoS;
}

void PessoaJ::Imprimir_Agenda(){
	
	Contato::Imprimir_Agenda();
	cout<<"CNPJ :"<<cnpj<<endl;
	cout<<"Inscri��o Estadual  :"<<inscriE<<endl;
	cout<<"Raz�o Social :"<<razaoS<<endl;
}


