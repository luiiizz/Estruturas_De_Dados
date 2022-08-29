#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/*Fa�a um programa que realize o cadastro de contas banc�rias com as seguintes informa��es: 
  n�mero da conta, nome do cliente e saldo.
  O banco permitir� o cadastramento da quantidade de contas que for informado pelo usu�rio, 
  aloque dinamicamente a mem�ria para essa estrutura, 
  n�o poder� haver mais que uma conta com o mesmo n�mero.
 */

struct conta{
     char cliente[50];
     int n_conta;
     float saldo;
     
     void mostrarCliente(){
		printf("\n			Cliente: %s", cliente);
		printf("\n			N� Conta: %d", n_conta);
		printf("\n			Saldo: %f", saldo);	
		printf("\n");
	}
};
typedef struct conta conta;

void menu();
int main(){
	setlocale(LC_ALL,"");
	
    int num, op, cont=0;
    conta *contas;
    float auxiliar2;
    
    
    printf("Entre com o numero m�ximo de contas a serem cadastradas: ");
    scanf("%d", &num);
   	
    contas = (conta*)malloc(num * sizeof(conta));
   
   
    for(int i=0; i<=num; i++){
    	contas[i].n_conta = 0;
	}
    
    do{
    	
    	menu();
	    scanf("%i", &op);
	    
		switch(op){
			case 1:
				
				if(cont < num){
					int verif = 0;
					int auxiliar;
					
					while(verif == 0){
					
						printf("Digite o n�mero da conta: ");
					 	scanf("%d",&auxiliar);
					 	//verificando se numero esta disponivel
						for(int i=0; i<=num; i++){
							if(contas[i].n_conta == auxiliar){
								system("cls");
								printf("Conta j� cadastrada");
								verif = 1;
								break;
							}else{
								contas[cont].n_conta = auxiliar;
								
								printf("Digite o nome do cliente: ");
							 	scanf("%s",&contas[cont].cliente);
				
							 	printf("Digite o saldo: ");
							 	scanf("%f",&contas[cont].saldo);
							 	verif = 1;
							 	system("cls");
							 	contas[cont].mostrarCliente();
								break;
							 	
							}
						}
					}	
				
				}else{
					system("cls");
					printf("N�mero m�ximo de contas cadastradas");
				}
				
				cont +=1;
				break;
			case 2:
			//2 - Visualizar todas as contas de determinado cliente.
				char nome[50];
				int ve;
				printf("Digite o nome do cliente: ");
				scanf("%s", &nome);
				
				for(int i; i<=num; i++){
					if(strcmp(nome, contas[i].cliente) == 0){
						contas[i].mostrarCliente();
						ve = 1;
					}else if(i==num && ve==0){
						printf("N�o foram encontradas contas para este cliente");
					}
				}
				
				break;
			case 3:
				//3 - Excluir a conta com menor saldo
				auxiliar2 = contas[1].saldo;
				int menor;
				
				for(int i=0; i<=num; i++){
					if(contas[i].saldo < auxiliar2){
						auxiliar2 = contas[i].saldo;
						menor = i;
					}
				}
				
				for(int i=0; i<=num; i++){
					if(i==menor){
						printf("\n\nApagando conta %i do cliente %s com saldo de %f\n",menor, contas[menor].cliente, contas[menor].saldo);
						contas[i].saldo = 0;
						contas[i].n_conta = 0;
					}
				}
				
			
				
				break;
				
			case 4:
				printf("Luiz");
				break;
		}
	    
	    
    	
	}while(op != 4);
	    
	    
    

    free(contas);
    return 0;
}
void menu(){
	printf("\nSelecione a op��o que melhor lhe atenda...\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Visualizar todas as contas de determinado cliente.\n");
        printf("3 - Excluir a conta com menor saldo (supondo a n�o exist�ncia de saldos iguais).\n");
        printf("4 - Sair deste Menu\n");
        printf("\nDigite uma op��o: ");
     

}
