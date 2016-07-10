#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>       
#include <sys/time.h>

int main(){

	//Variaveis
	int numero;
	float inferior = 1.0;
	float superior;
	float media;
	
	//Entrada
	printf("Digite um numero: ");
	scanf("%d",&numero);
	superior = numero;
	media = (inferior + superior)/2;
	
	//Busca Binaria
	/*Relação de Recorrencia
	 * T(n) = T(n/2) + O(1) + O(n)
	 * T(1) = O(1)
	 */
	printf("\n%.2f --- %.2f: %.2f\n",inferior,superior,media);
	while(abs((media*media) - numero) >= 0.0001){
		
		if((media*media) > numero){
			superior = media;
			media = (inferior + superior)/2;
		}
	
		else if((media*media) < numero){
			inferior = media;
			media = (inferior + superior)/2;
		}
		printf("%.2f --- %.2f: %.2f\n",inferior,superior,media);
	}
	printf("\nRaiz: %.2f",media);
	
	return 0;
}
