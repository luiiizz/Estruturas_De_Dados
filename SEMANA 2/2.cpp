#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <math.h>

using namespace std;


main(){
	setlocale(LC_ALL,"");
	
	int qtd, *vetor;
	 
	
	cout << "Digite o tamanho de vetor: ";
	cin >> qtd;
	
	
	
	vetor = (int  *) malloc (qtd * sizeof(int));
	
	for(int i=1; i<=qtd; i++){
		cout << "Digite o valor " << i <<": ";
		cin >> vetor[i];
	}
	
	system("cls");
	
	cout << "Pares: \n";
	for(int i=1; i<=qtd; i++){
		
		if (vetor[i]%2 == 0){
			cout << vetor[i] << "\n";
		}
	}
	
	cout << "\nImpares: \n";
	for(int i=1; i<=qtd; i++){
		
		if (vetor[i]%2 != 0){
			cout << vetor[i] << "\n";
		}
	}
	
	free(vetor);
	return 0;
}
