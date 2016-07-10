#include <stdio.h>      
#include <stdlib.h> 
#include <string.h>     
#include <math.h>
#include <time.h> 
#include <limits.h> 
#include <sys/time.h>

//Complexidade em Geral: O(n)
int main(){
	
	float troco;
	int i, aux;
	int num_moedas = 0;
	int moedas[6] = {71, 53, 37, 17, 7, 1};
	clock_t t0, tf;
	double tempo_gasto;	
	srand((unsigned)time(NULL));
	
	printf("Digite o troco (R.CC): ");
	scanf("%f",&troco);
	printf("\n");
	aux = 100*troco;
	
	//Contagem de moedas: O(n)
	t0 = clock();
	for(i = 0; i < 6; i++){
		printf("Moeda: %d c, Quantidade: %d\n", moedas[i], aux/moedas[i]);
		num_moedas += aux/moedas[i];
		aux = aux % moedas[i];
	}
	tf = clock();
	tempo_gasto = ((double) (tf - t0)) / CLOCKS_PER_SEC;
	
	printf("\n");
	printf("Numero de moedas: %d\n", num_moedas);
	printf("Tempo: %lf s", tempo_gasto);
	
	return 0;
}
