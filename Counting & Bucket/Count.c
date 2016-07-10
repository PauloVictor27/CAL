#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>

void countsort (int *vetor, int tamanho){
	int i, *aux, *res;
	int maior = tamanho;
	
	for(i = 0; i < tamanho; i++){
		if(vetor[i] > maior){
			maior = vetor[i];
		}
	}
	maior++;
	
	//Alocação
	aux = (int *) calloc(maior,sizeof(int));
	res = (int *) calloc(tamanho,sizeof(int));
	
	//Inicialização
	for(i = 0; i < maior; i++){
		aux[i] = 0;
		
	}
	
	//Contagem
	for(i = 0; i < tamanho; i++){
		aux[vetor[i]] += 1;
	}
	
	
	for(i = 0; i < maior; i++){
		printf("%d ",aux[i]);
	}
	
	printf("\n");
	
	
	//Somatorio
	for(i = 1; i < maior; i++){
		aux[i] += aux[i-1];
	}
	
	
	for(i = 0; i < maior; i++){
		printf("%d ",aux[i]);
	}
	
	printf("\n");
	
	
	//Verificação
	for(i = 0; i < tamanho; i++){
		res[aux[vetor[i]]-- -1] = vetor[i];
	}
	
	//Atualização
	for(i = 0; i < tamanho; i++){
		vetor[i] = res[i];
	}
	
}

 int main(){
	
	int *vet;
	int n,i,k;
	clock_t t0, tf;
	double tempo_gasto;
	double media = 0;
	
	n = 5;
	vet = (int *) calloc(n,sizeof(int));
	srand((unsigned)time(NULL));
	for(k = 0; k < 10; k++){
		for(i = 0; i < n; i++){
			vet[i] = rand()%10;
			printf("%d ",vet[i]);
		}

		printf("\n");
		t0 = clock();
		countsort(vet, n);
		tf = clock();
		for(i = 0; i < n; i++){
			printf("%d ",vet[i]);
		}
		tempo_gasto = ((double) (tf - t0)) / CLOCKS_PER_SEC;
		media += tempo_gasto;
		printf("\n%d): %lf s\n\n",(k+1), tempo_gasto);
	}
	
	printf("\nMedia: %lf s\n",media/10);
	
	return 0;
}
