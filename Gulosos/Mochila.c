#include <stdio.h>      
#include <stdlib.h> 
#include <string.h>     
#include <math.h>
#include <time.h> 

const int N = 10;
const int MaxPeso = 9;

typedef struct Item{
	//char nome[99];
    int valor;
    int peso;
    float razao;
} Item;

//O(n²)
void bubblesort(Item *vetor, int tamanho){
	int i, j;
	Item aux;
    for(i = tamanho-1; i >= 1; i--){  
        for(j=0; j < i ; j++){
            if(vetor[j].razao < vetor[j+1].razao){
                aux.valor = vetor[j].valor;
                aux.peso = vetor[j].peso;
                aux.razao = vetor[j].razao;
                vetor[j].valor = vetor[j+1].valor;
                vetor[j].peso = vetor[j+1].peso;
                vetor[j].razao = vetor[j+1].razao;
                vetor[j+1].valor = aux.valor;
                vetor[j+1].peso = aux.peso;
                vetor[j+1].razao = aux.razao;
            }
        }
    }
}

//Complexidade em Geral: O(n²)
int main(){
	
	Item *vet;
	Item *res;
	int i;
	clock_t t0, tf;
	double tempo_gasto;
	
	//int n;
	//printf("Digite um numero: ");
	//scanf("%d",&n);
	vet = (Item *) calloc(N,sizeof(Item));
	res = (Item *) calloc(N,sizeof(Item));
	
	srand((unsigned)time(NULL));
	
	//Preenchimento manual
	/*
	for(i = 0; i < N; i++){
		printf("Digite o inicio do %d evento: ",(i+1));
		scanf("%d", &vet[i].inicio);
		printf("Digite o fim do %d evento: ",(i+1));
		scanf("%d", &vet[i].fim);
		printf("\n");
	}
	*/
	
	t0 = clock();
	//Preenchimento aleatorio, //O(n)
	for(i = 0; i < N; i++){
		vet[i].peso = (rand()%5 +1);
		vet[i].valor= (rand()%5 +1);
		vet[i].razao = vet[i].valor/vet[i].peso;
	}
	
	//Impressão do vetor original, O(n)
	for(i = 0; i < N; i++){
		printf("[%d, %d, %.2f]\n",vet[i].peso, vet[i].valor, vet[i].razao);
	}
	printf("\n");
	
	//O(n²)
	bubblesort(vet, N);
	
	//Impressão do vetor ordenado, O(n)
	for(i = 0; i < N; i++){
		printf("[%d, %d, %.2f]\n",vet[i].peso, vet[i].valor, vet[i].razao);
	}
	printf("\n");
	
	int cont = 0;
	int j = 0;
	int soma = 0;
	i = 0;
	
	//Filtra os elementos
	while(cont <= MaxPeso && i < N){
		if(vet[i].peso <= MaxPeso && cont + vet[i].peso <= MaxPeso){
			res[j].peso = vet[i].peso;
			res[j].valor = vet[i].valor;
			res[j].razao = vet[i].razao;
			j++;
			i++;
			cont += vet[i].peso;
			soma += vet[i].valor;
		}else{
			i++;
		}
	}
	
	//Impressão dos elementos, O(n)
	for(i = 0; i < j; i++){
		printf("[%d, %d, %.2f]\n",vet[i].peso, vet[i].valor, vet[i].razao);
	}
	tf = clock();
	tempo_gasto = ((double) (tf - t0)) / CLOCKS_PER_SEC;
	
	printf("\nDinheiro Acumulado: %d\n", soma);
	printf("Tempo: %lf s", tempo_gasto);
	
	return 0;
}
