#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <math.h>

using namespace std;

struct Aluno{
	int matricula;
	char nome [20];
	int ano_nasc;
	
	void mostrar(){
		cout << "\nMatricula: " << matricula;
		cout << "\nNome do Aluno: " << nome;
		cout << "\nAno de Nascimento: " << ano_nasc << endl<<endl;
	}
};

main(){
	setlocale(LC_ALL,"");
	
	int qtd;
	Aluno *alunos;
	int matricula, nasc;
	string nome;
	
	
	cout << "Digite a quantidade de alunos: ";
	cin >> qtd;
	
	
	alunos = (Aluno *) malloc (qtd * sizeof(Aluno));
	
	alunos[1].matricula = 1;
	for(int i=1; i<=qtd; i++){
		cout << "\nDigite a matricula do aluno " << i <<": ";
		cin >> alunos[i].matricula;
		cout << "Digite o nome: ";
		cin >> alunos[i].nome;
		cout << "Digite o ano de nascimento: ";
		cin >> alunos[i].ano_nasc;
	}
	
	system("cls");
	
	cout << "Alunos Cadastrados: \n";
	for(int i=1; i<=qtd; i++){
		cout << "\n\nMatricula: " << alunos[i].matricula;
		cout << "\nNome: " << alunos[i].nome;
		cout <<  "\nAno de Nascimento: " << alunos[i].ano_nasc;
	}

	free(alunos);
	return 0;
}
