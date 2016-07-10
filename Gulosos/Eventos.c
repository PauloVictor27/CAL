#include <stdio.h>      
#include <stdlib.h> 
#include <string.h>     
#include <math.h>
#include <time.h> 
#include <limits.h> 
#include <sys/time.h>

const int N = 100;

typedef struct Evento{
	//char nome[99];
    int inicio;
    int fim;
    int marcado;
} Evento;

//O(n log n)
void merge(Evento *v, int in, int fi, int mid){
	int i, j, k; 
	Evento *aux;
	
	i = in;
    j = mid + 1;
    k = 0;
    
    aux = (Evento *) malloc(sizeof(Evento) * (fi - in + 1));

    while(i <= mid || j  <= fi) {
        if (i == mid+ 1 ) { 
            aux[k].inicio = v[j].inicio;
            aux[k].fim = v[j].fim;
            j++;
            k++;
        } 
        else {
            if (j == fi + 1) { 
                aux[k].inicio = v[i].inicio;
            	aux[k].fim = v[i].fim;
                i++;
                k++;
            } 
            else {
                if ((v[i].fim < v[j].fim) || ((v[i].fim == v[j].fim) && (v[i].inicio < v[j].inicio))) { 
                    aux[k].inicio = v[i].inicio;
            		aux[k].fim = v[i].fim;
                    i++;
                    k++;
                } 
                else { 
                    aux[k].inicio = v[j].inicio;
            		aux[k].fim = v[j].fim;
                    j++;
                    k++;
                }
            }
        }

    }
    
    for(i = in; i <= fi; i++) {
        v[i].inicio = aux[i - in].inicio;
        v[i].fim = aux[i - in].fim;
    }
    free(aux);
}

void mergesort(Evento *vetor, int inicio, int fim) {
    int metade;
    
    if(inicio == fim) return;

    metade = (inicio + fim ) / 2;
    mergesort(vetor, inicio, metade);
    mergesort(vetor, metade + 1, fim);
    merge(vetor, inicio, fim, metade);

}

//Complexidade em Geral: O(n²)
int main(){
	
	Evento *vet;
	Evento *res;
	int i, j;
	clock_t t0, tf;
	double tempo_gasto;
	
	//int n;
	//printf("Digite um numero: ");
	//scanf("%d",&n);
	vet = (Evento *) calloc(N,sizeof(Evento));
	res = (Evento *) calloc(N,sizeof(Evento));
	
	srand((unsigned)time(NULL));
	
	//Preenchimento manual
	/*
	for(i = 0; i < N; i++){
		printf("Digite o nome do %d evento: ",(i+1));
		scanf("%s", vet[i].nome);
		printf("Digite o inicio do %d evento: ",(i+1));
		scanf("%d", &vet[i].inicio);
		printf("Digite o fim do %d evento: ",(i+1));
		scanf("%d", &vet[i].fim);
		printf("\n");
	}
	*/
	
	t0 = clock();
	//Preenchimento aleatorio, O(n)
	for(i = 0; i < N; i++){
		vet[i].inicio = (rand()%100 +1);
		vet[i].fim = (rand()%101 +1);
		vet[i].marcado = 0;
		if(vet[i].fim <= vet[i].inicio){
			while(vet[i].fim <= vet[i].inicio){
				vet[i].fim = (rand()%101 +1);
			}
		}
	}
	
	//Impressão do vetor original, O(n)
	for(i = 0; i < N; i++){
		printf("[%d, %d]\n", vet[i].inicio,vet[i].fim);
	}
	printf("\n");
	
	//O(n log n)
	mergesort(vet, 0, N-1);
	
	//Impressão do vetor ordenado, O(n)
	for(i = 0; i < N; i++){
		printf("[%d, %d]\n", vet[i].inicio,vet[i].fim);
	}
	printf("\n");
	
	int k = 1;
	int soma = 0;
	int cont, menor, posicao;
	
	res[0].inicio = vet[0].inicio;
    res[0].fim = vet[0].fim;
    vet[0].marcado = 1;
    
	//Filtra os elementos, O(n²)
	for(i = 0; i < N; i++){
		cont = 0;
		menor = INT_MAX;
		for(j = 0; j < N; j++){
			if(vet[j].inicio >= res[k-1].fim && vet[j].inicio < menor && vet[j].marcado == 0){
				menor = vet[j].inicio;
				posicao = j;
				cont++;
			}
		}
		if(cont != 0){
			res[k].inicio = vet[posicao].inicio;
			res[k].fim = vet[posicao].fim;
			vet[posicao].marcado = 1;
			k++;
			soma++;
		}
	}
	
	//Impressão dos elementos, O(n)
	for(i = 0; i < k; i++){
		printf("[%d, %d]\n", res[i].inicio,res[i].fim);
	}
	tf = clock();
	tempo_gasto = ((double) (tf - t0)) / CLOCKS_PER_SEC;
	
	printf("\nNumero de eventos: %d\n", soma+1);
	printf("Tempo: %lf s", tempo_gasto);
	
	return 0;
}
