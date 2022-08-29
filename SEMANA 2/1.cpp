#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <math.h>

using namespace std;

int menu();
main(){
	setlocale(LC_ALL,"");
	
	int qtd;
	float *notas, soma=0;
	
	cout << "Digite a quantidade de alunos da turma: ";
	cin >> qtd;
	
	
	notas = (float  *) malloc (qtd * sizeof(float));
	
	for(int i=1; i<=qtd; i++){
		cout << "Digite a nota do aluno" << i <<": ";
		cin >> notas[i];
		soma = soma+notas[i];
	}
	
	cout << "A media da turma é: "<< round(soma/qtd);
	
	free(notas);

	
	return 0;
}
