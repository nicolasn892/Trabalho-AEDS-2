#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
#include <cstring>


#include "Contatos.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"

#define Max 100

using namespace std;

void cadastraAgenda(Contato *list_agenda){
	
	string nome;
	string endereco;
	string email;
	
	system("cls");
	cin.clear();
	fflush(stdin);
	cout<<"Nome do Contato :"<<endl;
	getline(cin,nome);
	cin.clear();
	fflush(stdin);
	list_agenda->setNome(nome);
	
	cout<<"Endereço do Contato :"<<endl;
	getline(cin,endereco);
	cin.clear();
	fflush(stdin);
	list_agenda->setEndereco(endereco);
	
	cout<<"Email do  Contato :"  <<endl;
	getline(cin,email);
	cin.clear();
	fflush(stdin);
	list_agenda->setEmail(email);
	
}
void cadastraPessoaF(PessoaF *list_agenda){
	string cpf;
	string data;
	string estado;
	
	cout<<"cadastro de Pessoa Física "<<endl;
	cadastraAgenda(list_agenda);
	
	cout<<"Cpf do Contato: "  <<endl;
	getline(cin,cpf);
	cin.clear();
	fflush(stdin);
	list_agenda->setCpf(cpf);
	
	cout<<"Data de nascimento do Contato: "  <<endl;
	getline(cin,data);
	cin.clear();
	fflush(stdin);
	list_agenda->setData(data);
	
	cout<<"Estado civil do Contato: "  <<endl;
	getline(cin,estado);
	cin.clear();
	fflush(stdin);
	list_agenda->setEstado(estado);
	system("cls");
	
}
void cadastraPessoaJ(PessoaJ *list_agenda){
	string cnpj;
	string inscriE;
	string razaoS;
	
	cout<<"cadastro de Pessoa Jurídica "<<endl;
	cadastraAgenda(list_agenda);
	
	cout<<"Cnpj do Contato: "  <<endl;
	getline(cin,cnpj);
	cin.clear();
	fflush(stdin);
	list_agenda->setCnpj(cnpj);
	
	cout<<"Inscrição Estadual do Contato: "  <<endl;
	getline(cin,inscriE);
	cin.clear();
	fflush(stdin);
	list_agenda->setInscriE(inscriE);
	
	cout<<"Razão social do Contato: "  <<endl;
	getline(cin,razaoS);
	cin.clear();
	fflush(stdin);
	list_agenda->setRazaoS(razaoS);
	system("cls");
}



//ordena os contatos na agenda ( Bubble Sort)
void ordena(Contato *list_agenda[], int &contContato){
	PessoaF *pfC1, *pfC2;
	PessoaJ *pjC1, *pjC2;
	Contato *temp;
	if(contContato > 1){
		for (int i = contContato-1;i > 0;i--){
			for (int j = 0;j < i;j++){
				if(dynamic_cast<PessoaF*>(list_agenda[i]) && dynamic_cast<PessoaF*>(list_agenda[j])){
					pfC1 = dynamic_cast<PessoaF*>(list_agenda[i]);
					pfC2 = dynamic_cast<PessoaF*>(list_agenda[j]);
					if(pfC1->getCpf() < pfC2->getCpf()){
						temp = list_agenda[i];
						list_agenda[i] = list_agenda[j];
						list_agenda[j] = temp;
					}
				}else if(dynamic_cast<PessoaF*>(list_agenda[i]) && dynamic_cast<PessoaJ*>(list_agenda[j])){
					pfC1 = dynamic_cast<PessoaF*>(list_agenda[i]);
					pjC1 = dynamic_cast<PessoaJ*>(list_agenda[j]);
					temp = list_agenda[i];
					list_agenda[i] = list_agenda[j];
					list_agenda[j] = temp;
				}else if(dynamic_cast<PessoaJ*>(list_agenda[i]) && dynamic_cast<PessoaJ*>(list_agenda[j])){
					pjC1 = dynamic_cast<PessoaJ*>(list_agenda[i]);
					pjC2 = dynamic_cast<PessoaJ*>(list_agenda[j]);
					if(pjC1->getCnpj() < pjC2->getCnpj()){
						temp = list_agenda[i];
						list_agenda[i] = list_agenda[j];
						list_agenda[j] = temp;
					}
				}
			}
		}
	}
}

int main(int argc, char** argv) {
	
	setlocale(LC_ALL,"");
	system("chcp 1252 > nul");
	
	Contato *list_agenda[Max];
	
	PessoaF *pf;
	PessoaJ *pj;
	
	for(int i=0;i<Max;i++){
		list_agenda[i]=NULL;
	}
	
	// declaração das variaveis 
	int op =1;
	int i=0;
	int c = 0;
	int opcao=0;
	int contContato=0;
	int encontrouContato=-1;
	string PesquisaCpf;
	string PesquisaCnpj;
	string PesquisaNome;
	
	while(op != 0 ){
		for(contContato;contContato<Max;contContato++){
		system("cls");
		cout<<"1- Cadastra Contato-Pessoa Física"<<endl;
		cout<<"2- Cadastra Contato-Pessoa Jurídica"<<endl;
		cout<<"3- Remover Cadastro da Agenda"<<endl;
		cout<<"4- Pesquisar na Agenda" <<endl;
		cout<<"5- Visualizar todos os Contatos da Agenda " <<endl;
		cout<<"0- Sair" <<endl;
		cin>>op;
		cin.clear();
		fflush(stdin);
		
		switch(op){
		case 1: 
			//Pessoa Fisica;
			list_agenda[contContato] = new PessoaF();
			cadastraPessoaF(dynamic_cast<PessoaF*>(list_agenda[contContato]));
			contContato++;
			ordena(list_agenda,contContato);
			cout<<endl;
			break;
			
		case 2:
			//Pessoa Juridica;
			list_agenda[contContato] = new PessoaJ();
			cadastraPessoaJ(dynamic_cast<PessoaJ*>(list_agenda[contContato]));
			contContato++;
			ordena(list_agenda,contContato);
			cout<<endl;
			break;
			
		case 3:
					//Verifica se algum contato já tiver sido inserido na agenda
					if(contContato > 0){
						//Remove um contato
						do{
							cout << "1- Remover pelo  CPF" << endl;
							cout << "2- Remover pelo  CNPJ" << endl;
							cout << "Qual Deseja: ";
							cin >> opcao;
							cin.clear();
							fflush(stdin);
							if(opcao == 1){
								cout << "Informe o CPF a ser removido: ";
								getline(cin, PesquisaCpf);
								cin.clear();
								fflush(stdin);
							
								//Pesquisa pelo CPF fornecido pelo usuário e armazena a posição na variável encontrouContato (se encontrar)
								for(int i = 0;i < contContato;i++){
									if(dynamic_cast<PessoaF*>(list_agenda[i])){
										pf = dynamic_cast<PessoaF*>(list_agenda[i]);
										if(pf->getCpf() == PesquisaCpf){
											encontrouContato = i;
											//Deleta os dados do contato
											delete(list_agenda[encontrouContato]);
											if(encontrouContato < contContato){
												for(int j = encontrouContato;j<contContato-1;j++){
													list_agenda[j] = list_agenda[j+1];
												}
											}
											list_agenda[contContato-1] = NULL;
											contContato--;
										}
									}
								}
								if(encontrouContato < 0){
									cout << "CPF não foi encontrado!" << endl;
								}else{
									cout << "Contato foi removido com sucesso!" << endl << endl;
								}
							}else if(opcao == 2){
								cout << "Informe o CNPJ a ser removido: ";
								getline(cin, PesquisaCnpj);
								cin.clear();
								fflush(stdin);
								
								//Pesquisa pelo CNPJ fornecido pelo usuário e armazena a posição na variável encontrouContato (se encontrar)
								for(int i = 0;i < contContato;i++){
									if(dynamic_cast<PessoaJ*>(list_agenda[i])){
										pj = dynamic_cast<PessoaJ*>(list_agenda[i]);
										if(pj->getCnpj() == PesquisaCnpj){
											encontrouContato = i;
											
											//Deleta os dados do contato
											delete(list_agenda[encontrouContato]);
											if(encontrouContato < contContato){
												for(int j = encontrouContato;j<contContato-1;j++){
													list_agenda[j] = list_agenda[j+1];
												}
											}
											list_agenda[contContato] = NULL;
											contContato--;
										}
									}
								}
								if(encontrouContato < 0){
									cout << "CPF não encontrado!" << endl;
								}else{
									cout << "Contato removido com sucesso!" << endl << endl;
								}
							}else{
								cout << "Opção inválida! Digite uma opção válida, por gentileza" << endl;
								system("pause");
								system("cls");
							}
						}while(opcao < 1 || opcao > 3);
					}else{
						cout << "Não existem contatos cadastrados!" << endl;										
					}
					
					PesquisaCpf = "";
					PesquisaCnpj = "";
					encontrouContato = -1;
					
					system("pause");
					system("cls");
					break;
		case 4:
			//Pesquisar na Agenda
			cout<<"Deseja pesquisa como :"<<endl;
			cout<<"1- Pelo CPF :"<<endl;
			cout<<"2- Pelo CNPJ :"<<endl;
			cout<<"3- Pelo Nome :"<<endl;
			cin>>opcao;
			cin.clear();
			fflush(stdin);
			
			switch(opcao){
				case 1:
					cout<<"Informe o CPF:"<<endl;
					getline(cin,PesquisaCpf);
					cin.clear();
					fflush(stdin);
		
					for(i=0;i<Max;i++){
						Contato *agenda = list_agenda[i];
						if(dynamic_cast<PessoaF*>(agenda)){
							PessoaF *pf = dynamic_cast<PessoaF*>(agenda);
							if(strcmp(pf->getCpf().c_str(),PesquisaCpf.c_str()) == 0){
								cout<<endl<<endl;
								pf->Imprimir_Agenda();
								cout<<endl<<endl;
								system("pause");
							break;
					}
				}
			}	
			
				break;
				
				case 2:
					cout<<"Informe o CNPJ:"<<endl;
					getline(cin,PesquisaCnpj);
					cin.clear();
					fflush(stdin);
		
					for(i=0;i<Max;i++){
						Contato *agenda = list_agenda[i];
						if(dynamic_cast<PessoaJ*>(agenda)){
							PessoaJ *pj = dynamic_cast<PessoaJ*>(agenda);
							if(strcmp(pj->getCnpj().c_str(),PesquisaCnpj.c_str()) == 0){
								cout<<endl<<endl;	
								pj->Imprimir_Agenda();
								cout<<endl<<endl;
								system("pause");
							break;
					}
				}
			}
				break;
				case 3:
					cout<<"Informe o Nome:"<<endl;
					getline(cin,PesquisaNome);
					cin.clear();
					fflush(stdin);
		
					for(i=0;i<Max;i++){
						Contato *agenda = list_agenda[i];
						if(dynamic_cast<Contato*>(agenda)){
							Contato *ag = dynamic_cast<Contato*>(agenda);
							if(strcmp(ag->getNome().c_str(),PesquisaNome.c_str()) == 0){
								cout<<endl<<endl;	
								ag->Imprimir_Agenda();
								cout<<endl<<endl;
								system("pause");
						     	break;
					}
				}
			}					
	}
		break;
		case 5:
			//Imprime toda Agenda	
			cout<<"       Mostrar Agenda        "<<endl<<endl;		
			for(int i=0;i<contContato;i++){
				if(list_agenda[i]!=NULL){
					cout<<endl<<endl;
					list_agenda[i]->Imprimir_Agenda();
					cout<<endl;
				}
			}
			
			system("pause");
			system("cls");
			
			
		break;
		case 0:
			cout<<"saindo do programa"<<endl;
			exit(1);
		break;	
		
		default:

			system("cls");
			cout<<"Tipo invalida"<<endl;
			system("pause");
			system("cls");
		continue;
			}
		}
	}

				
	return 0;
}

