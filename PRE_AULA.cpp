// Semana 17 

/* Devs: Luiz Henrique Bispo Barreira
		Lorraynne Annyelly Cardoso
		Elias Soares 
*/

#include<iostream>
#include<string.h>

#define q 15  


using namespace std;

struct Clientes{
	int cod_cli;
	string nome;
	string fone;
	string endereco;
	
	void mostrarCliente(){
		cout << "\n			Cod. Cliente: " << cod_cli;
		cout << "\n			Nome: " << nome;
		cout << "\n			Fone: " << fone;
		cout << "\n			Enderço: " << endereco << endl; 
	}
	
}cliente[15];

struct Data{
	int dia;
	int mes;
	int ano;
};

struct Documentos{
	int num_doc;
	int cod_cli;
	Data data_venc;
	Data data_pag;
	float valor;
	float juros; 
	
	void mostrarDoc(){
		cout << "\n			Número documento: " << num_doc;
		cout << "\n			Código do Cliente: " << cod_cli;
		cout << "\n			Data de Vencimento:  "<<endl;
		cout << "			"<<data_venc.dia<<"/"<<data_venc.mes<<"/"<<data_venc.ano;
		cout << "\n			Data de Pagamento:  "<<endl;
		cout << "			"<<data_pag.dia<<"/"<<data_pag.mes<<"/"<<data_pag.ano;
		cout << "\n			Valor do Documento: " << valor;
		cout << "\n			Juros: " << juros<< endl; 
	}
	
}documento[30];

char* menu();

int main(){
	setlocale(LC_ALL,"");
	int ver_cod, auxiliar_cod;
	char *op;
	FILE *file;	
	int *aaa;
	char documentos[200];
	FILE *file2;
	char *result;
	
	
	
	for(int i=0; i<15; i++){
		cliente[i].cod_cli = 0;
	}
	for(int i=0; i<30; i++){
		documento[i].num_doc = 0;
	}
	
	op = menu();

	while (strcmp(op, "i")!=0){
		
		//a) Cadastrar clientes
		if(strcmp(op,"a") == 0){
			system("cls");
			cout << "CADRATRO DE CLIENTES\n" << endl;
				ver_cod = 0;
				//Loop para validar numero de cliente disponivel
				while(ver_cod == 0){
					cout << "\nDigite o codigo do cliente: ";
					cin >> auxiliar_cod;
					for(int i=0; i<q;i++){
						//Verificar se já existe.
						if(cliente[i].cod_cli == auxiliar_cod){
							system("cls");
							cout << "\nCliente já cadrastrado\n";
							break;
						}
						else if (cliente[i].cod_cli == 0){
							//Cadastrando Cliente
							cliente[i].cod_cli = auxiliar_cod;
							cout << "\nDigite o nome do cliente: ";
							cin >> cliente[i].nome;
							cout << "\nInforme o fone: ";
							cin >> cliente[i].fone;
							cout << "\nInforme o enderço: ";
							cin >> cliente[i].endereco;
							
							//menor_saldo = contas[i].saldo;
							ver_cod = 1;
							system("cls");
							//Mostrando Cliente
							cout << "			Cliente cadastrado"<<endl;
							cout << "			----------------";
							cliente[i].mostrarCliente();
				
							break;
						}
					}
				}
			}
			
			//b) Cadrastrar documentos
			else if(strcmp(op,"b") == 0){
				auxiliar_cod = 0;
				int a = 0;
				system("cls");
				cout << "CADRATRO DE DOCUMENTOS\n" << endl;
				
				cout << "\nDigite o código do cliente: ";
				cin >> auxiliar_cod;
				
				// For para verificar se existe cliente;
				for(int i=0; i<q; i++){
					if(cliente[i].cod_cli == auxiliar_cod){
						cout << "Cliente: " << cliente[i].nome<<endl;
						//verificar posteriormente se não achou em nenhum espaço
						a = 1;
						 
							for(int j=0; j<30;j++){
								//Se estiver espaço disponivel
								if(documento[j].num_doc == 0){
									
									cout << "\nDigite o número do documento: ";
									cin >> documento[j].num_doc;
									documento[j].cod_cli = cliente[i].cod_cli;
									
									cout << "\nDigite a data de vencimento: ";
									cout << "\nDia: ";
									cin >> documento[j].data_venc.dia;
									cout << "Mês: ";
									cin >> documento[j].data_venc.mes;
									cout << "Ano: ";
									cin >> documento[j].data_venc.ano;
									
									cout << "\nDigite a data de pagamento: ";
									cout << "\nDia: ";
									cin >> documento[j].data_pag.dia;
									cout << "Mês: ";
									cin >> documento[j].data_pag.mes;
									cout << "Ano: ";
									cin >> documento[j].data_pag.ano;
									
									cout << "\nDigite o valor do documento: ";
									cin >> documento[j].valor;
									
									//se o ano for maior, cobrar juros direto
									if(documento[j].data_pag.ano > documento[j].data_venc.ano){
										documento[j].juros = 0.05 * documento[j].valor;
									}
									//Se o mês for maior e o mesmo ano, cobrar juros
									else if(documento[j].data_pag.mes > documento[j].data_venc.mes && documento[j].data_pag.ano == documento[j].data_venc.ano){
										documento[j].juros = 0.05 * documento[j].valor;
									}
									//Se o dia for maior e o mesmo mês e ano
									else if(documento[j].data_pag.dia > documento[j].data_venc.dia && documento[j].data_pag.mes == documento[j].data_venc.mes && documento[j].data_pag.ano == documento[j].data_venc.ano){
										documento[j].juros = 0.05 * documento[j].valor;
									}
									
									system("cls");
									cout << "			Documento Cadrastrado e escrito em doc.txt: "<< endl;
									cout << "			----------------";
									//escrita no arquivo
										file = fopen("doc.txt", "wt");
										if(file==NULL){
											cout<<"Problemas na criação do doc";
										}
										
										sprintf(documentos, "\nInformações do Documento:\nNumero do documento: %i \nData de Vencimento:%i \nValor: %f\n\n Informações de Clientes:\nCodigo Cliente: %i", documento[j].num_doc,documento[j].data_venc, documento[j].valor,cliente[i].cod_cli);
									
										fprintf(file,"%s",documentos);
										fclose(file);
									//Leitura do arquivo
										file2 = fopen("doc.txt", "rt");
										if(file2==NULL){
											cout<< "Erro na abertura do arquivo";
										}
										
										int i=1;
										char linha[100];
										while(!feof(file2)){
											result = fgets(linha,100,file2);
											if(result){
												//printf("Linha %d: %s", i,linha);
											}
											
											i++;	
										}
										fclose(file2);
									
									documento[j].mostrarDoc();
									break;
								}
							}	
					}
					if (i == 14 && a == 0)
						cout << "\nCliente não cadastrado\n";
				}
			}
			
			//c) Excluir clientes
			else if(strcmp(op,"c") == 0){
				int a = 0, n_excluir = 0;
				auxiliar_cod = 0;
				system("cls");
				cout << "EXCLUSÃO DE CLIENTE\n" << endl;
				cout << "Digite o código do cliente: ";
				cin >> auxiliar_cod;
				
				for(int i=0; i<q; i++){
					if(cliente[i].cod_cli == auxiliar_cod){
						cout << "\nCliente: " << cliente[i].nome<<endl;
						a = 1;
						
						//Verificar se tem documento vinculado ao cliente
						n_excluir = 0;
						for(int j=0; j<30;j++){
							if(documento[j].cod_cli == auxiliar_cod){
								cout << "\nDocumentos vinculados a este cliente !!!"<<endl;
								n_excluir = 1;
							}
						}
						
						if(n_excluir == 0){
							cout << "			Excluido o seguinte cliente: ";
							cliente[i].mostrarCliente();
							cliente[i].cod_cli = 0;	
						}
						
						break;
					}
					if(i == 14 && a == 0)
						cout << "\nCliente não cadastrado\n";
				}	
			}
			
			//d) Excluir documentos individuais
			else if(strcmp(op,"d") == 0){
				int a = 0;
				auxiliar_cod = 0;
				system("cls");
				cout << "EXCLUSÃO DE DOCUMENTOS INDIVIDUAIS\n" << endl;
				cout << "\nDigite o código do documento: ";
				cin >> auxiliar_cod;
				
				//Verificando se existe o documento
				for(int j=0; j<30; j++){
					if(documento[j].num_doc == auxiliar_cod){
						a = 1;
						cout <<"\nExcluindo o seguinte documento\n: "<<endl;
						documento[j].mostrarDoc();
						documento[j].num_doc = 0;
						break;
					}
					if(j==29 && a == 0){
						cout << "\nDocumento não encontrado" <<endl;
					}
				}
			}
			
		
			
			//e) Alterar informações sobre cliente
			else if(strcmp(op,"e") == 0){
				int a = 0;
				auxiliar_cod = 0;
				system("cls");
				cout << "ALTERAR INFORMAÇÕES SOBRE CLIENTE\n" << endl;
				cout << "Digite o código do cliente: ";
				cin >> auxiliar_cod;
				
				for(int i=0; i<q; i++){
					if(cliente[i].cod_cli == auxiliar_cod){
						a = 1;
						cout << "\nDigite um novo nome do cliente: ";
						cin >> cliente[i].nome;
						cout << "\nInforme um novo fone: ";
						cin >> cliente[i].fone;
						cout << "\nInforme um novo enderço: ";
						cin >> cliente[i].endereco;
					}
					if(i == 14 && a == 0)
						cout << "\nCliente não encontrado\n";
				}
			}
			
			
			
			// Imprimir menu novamente
			menu();
			
	}
	// Opção igual a i
	system("cls");
	cout << "\nOBRIGADO POR UTILIZAR UM SISTEMA HENRIKS"<<endl<<endl;
	cout << "\nSaindooo....\n";
		
	return 0;
}

char* menu(){
	static char op[2];
	int val = 0;
	char opc [2];
	system("color b");
	cout << "\n MENU DE OPÇÕES: " <<endl<<endl;
	cout << " a) Cadastrar clientes" <<endl;
	cout << " b) Incluir recebimentos "<<endl;
	cout << " c) Excluir clientes"<<endl;
	cout << " d) Excluir recebimentos"<<endl;
	cout << " e) Alterar informações sobre cliente"<<endl;
	cout << " i) Sair"<<endl<<endl;
	
	while(val == 0){
	cout<< " Digite uma letra: ";
	cin >> op;
	if(strcmp(op,"a") == 0 || strcmp(op,"b") == 0 || strcmp(op,"c") == 0|| strcmp(op,"d") == 0|| strcmp(op,"e") == 0|| strcmp(op,"f") == 0|| strcmp(op,"g") == 0|| strcmp(op,"h") == 0 || strcmp(op,"i") == 0)
		val = 1;
	else
		cout << "\n Opção Inválida\n"<<endl;
	}
	return op;
}






