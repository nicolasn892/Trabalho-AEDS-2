#include "PessoaFisica.h"
#include "Contatos.h"
#include <iostream>

PessoaF::PessoaF(){
}

PessoaF::PessoaF(string nome,string endereco,string email,string cpf,string data,string estado) : Contato(nome,endereco,email){
	 setCpf(cpf);
	 setData(data);
	 setEstado(estado);
}

PessoaF::~PessoaF(){
}

string PessoaF::getCpf(){
	return cpf;
}

string PessoaF::getData(){
	return data;
}
string PessoaF::getEstado(){
	return estado;
}

void PessoaF::setCpf(string cpf){
	this->cpf = cpf;
}
void PessoaF::setData(string data){
	this->data = data;
}
void PessoaF::setEstado(string estado){
	this->estado = estado;
}

void PessoaF::Imprimir_Agenda(){
	
	Contato::Imprimir_Agenda();
	cout<<"CPF : "<<cpf<<endl;
	cout<<"Data : "<<data<<endl;
	cout<<"Estado : "<<estado<<endl;
}





