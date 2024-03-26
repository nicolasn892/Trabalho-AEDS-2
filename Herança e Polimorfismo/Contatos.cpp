#include "Contatos.h"
#include <iostream>

Contato::Contato(){
	
}
Contato::Contato(string nome,string endereco,string email){
		 setNome(nome);
		 setEndereco(endereco);
		 setEmail(email);
}
Contato::~Contato(){
	
}

string Contato::getNome(){
	return nome;
}

string Contato::getEndereco(){
	return endereco;
}

string Contato::getEmail(){
	return email;
}

void Contato::setNome(string nome){
	this->nome = nome;
}

void Contato::setEndereco(string endereco){
	this->endereco = endereco;
}

void Contato::setEmail(string email){
	this->email = email;
}

void Contato::Imprimir_Agenda(){
	
	cout<<"Nome :"<<nome<<endl;
	cout<<"Endereço :"<<endereco <<endl;
	cout<<"Email :"<<email<<endl;
}



