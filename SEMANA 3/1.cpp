#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <math.h>


/*Criar uma estrutura que represente uma pessoa, contendo nome, data de nascimento e CPF. 
Crie uma variável que é um ponteiro para essa estrutura (no programa principal). 
Depois crie uma função que receba este ponteiro e preencha os dados da estrutura e também uma uma 
função que receba este ponteiro e imprima os dados da estrutura. Finalmente, faça a chamada a esta função na função principal. 
Aloque dinamicamente a estrutura 
para que sejam armazenadas a quantidade de registros definidos pelo usuário.*/

using namespace std;


typedef struct{
	char nome[30];
	char  data_nascimento [20];
	int cpf;
}Pessoa;


void preencher(Pessoa *pessoas, int qtd);
void imprimir(Pessoa *pessoas, int qtd);

int main(){
	setlocale(LC_ALL,"");
	
	int qtd;
	Pessoa *pessoas;
	
	cout << "Informe a quantidade de pessoas: ";
	cin >> qtd;
	
	pessoas = (Pessoa *) malloc(qtd * sizeof(Pessoa));
	
	preencher(pessoas, qtd);
	
	system("cls");
	
	imprimir(pessoas, qtd);
	free(pessoas);
	return 0;
}

void preencher(Pessoa *pessoas, int qtd){
	
		for(int i=1; i<=qtd; i++){
			cout << "\nDigite o nome da pessoa " << i <<": ";
			cin >> pessoas[i].nome;
			cout << "Digite a data de nascimento: ";
			cin >> pessoas[i].data_nascimento;
			cout << "Digite o CPF: ";
			cin >> pessoas[i].cpf;
		}
}
void imprimir(Pessoa *pessoas, int qtd){
	
		for(int i=1; i<=qtd; i++){
			
		cout << "\nNome: " << pessoas[i].nome;
		cout << "\nData de Nascimento: " << pessoas[i].data_nascimento;
		cout << "\nCPF: " << pessoas[i].cpf;
	}
	
}


