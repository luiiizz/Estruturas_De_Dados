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
	char *vetor;
	 
	
	cout << "Digite o tamanho da string: ";
	cin >> qtd;
	
	
	
	vetor = (char *) calloc (qtd, sizeof(char));
	
	for(int i=1; i<=qtd; i++){
		cin >> vetor[i];
	}
	
	system("cls");
	
	cout << "String sem suas vogais: \n";
	for(int i=1; i<=qtd; i++){
		
		if(vetor[i] == 'a' || vetor[i] == 'e' || vetor[i] == 'i' || vetor[i] == 'o' || vetor[i] == 'u'){
			cout << " ";
		}else
			cout << vetor[i];
	}
	
	free(vetor);
	return 0;
}
