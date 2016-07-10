#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>       
#include <sys/time.h>

int main(){

	//Variaveis
	int a, b; //Parametros O(1)
	int expoente = 1; //   O(1)
	int i; //Contador      O(1)
	
	//Entrada
	printf("Digite o primeiro numero: "); //O(1)
	scanf("%d",&a); //                      O(1)
	printf("Digite o segundo: "); //        O(1)
	scanf("%d",&b); //                      O(1)
	 
	//Multiplicação
	for(i = 0; i < b; i++){ //              O(n)
		expoente = expoente*a;//            O(1)
	}
	
	//Saida
	printf("\nResultado: %d\n", expoente);//  O(1)
	
	return 0;                             //  O(1)
}
