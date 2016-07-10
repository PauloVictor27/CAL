#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>
#define MAX 100
#define BALDE 10

typedef struct no{
    int valor;
    struct no *prox;
    struct no *ant
}No;

typedef struct lista{
    int tamInfo;
    No *primeiro;
}Lista;


void bucketsort(int *vetor, int n)
{   
	int i,j;
	Lista *balde;
	int *vetor2;
	//Ponteiros Auxiliares
	No *aux1, *aux2, *aux3;	
	
	//Alocação e Inicialização
	vetor2 = (int *) calloc(n,sizeof(int));
	balde = (Lista *) calloc(BALDE,sizeof(Lista));
	for(i = 0; i < BALDE; i++){
		balde[i].primeiro = NULL;
	}
	
	//Execução
	for(i = 0; i < n; i++){
		aux1 = (No*) malloc(sizeof(No));
		aux2 = (No*) malloc(sizeof(No));
		aux3 = (No*) malloc(sizeof(No));
		aux1->valor = vetor[i];
		aux2 = balde[((vetor[i]*BALDE)/MAX)].primeiro;
		//Se estiver vazio, insere normal
		if(balde[((vetor[i]*BALDE)/MAX)].primeiro == NULL){
			balde[((vetor[i]*BALDE)/MAX)].primeiro = aux1;
			//printf("%d: %d, %d", vetor[i], ((vetor[i]*BALDE)/MAX), balde[((vetor[i]*BALDE)/MAX)].primeiro->valor);
		}
		else{
			//Novo inicio
			if(aux1->valor <= balde[((vetor[i]*BALDE)/MAX)].primeiro->valor){
				balde[((vetor[i]*BALDE)/MAX)].primeiro = aux1;
				balde[((vetor[i]*BALDE)/MAX)].primeiro->prox = aux2;
				aux2->ant = balde[((vetor[i]*BALDE)/MAX)].primeiro;
				//printf("%d: %d, %d", vetor[i], ((vetor[i]*BALDE)/MAX), balde[((vetor[i]*BALDE)/MAX)].primeiro->valor);
			}
			else{	
				//Percorre a lista até achar a melhor posição
				while(aux2->prox != NULL && aux1->valor >= aux2->valor) {
					aux2 = aux2->prox;
				}
				//Se chegou no final da lista
				if(aux2->prox == NULL){
					aux2->prox = aux1;
					aux1->ant = aux2;
					//printf("%d: %d, %d", vetor[i], ((vetor[i]*BALDE)/MAX), balde[((vetor[i]*BALDE)/MAX)].primeiro->valor);
				}
				else{				
					aux1->ant = aux2->ant;
					aux2->ant->prox = aux1;
					aux1->prox = aux2;
					aux2->ant = aux1;
					//printf("%d: %d, %d", vetor[i], ((vetor[i]*BALDE)/MAX), balde[((vetor[i]*BALDE)/MAX)].primeiro->valor);
				}
			}
		}		
	}
	
	//printf("\n");
	
	aux3 = (No*) malloc(sizeof(No));
	for(i = 0; i < BALDE; i++){
		printf("%d: ",i);
		aux3 = balde[i].primeiro;
		if(aux3 != NULL){
			while(aux3 != NULL){
				printf("%d ",aux3->valor);
				aux3 = aux3->prox;
			}
		}
		printf("\n");
	}
	
	printf("\n");
	
	j = 0;
	for(i = 0; i < BALDE; i++){
		aux3 = balde[i].primeiro;
			while(aux3 != NULL){
				vetor2[j] = aux3->valor;
				printf("%d ",vetor2[j]);
				j++;
				aux3 = aux3->prox;
			}
			
	}
	
	printf("\n");
	
	for(i = 0; i < n; i++){
		vetor[i] = vetor2[i];
		//printf("%d ",vetor[i]);
	}
}


int main(){
	
	int *vet;
	int n,i;
	int k;
	clock_t t0, tf;
	double tempo_gasto;
	double media = 0;
	
	n = 10;
	vet = (int *) calloc(n,sizeof(int));
	srand((unsigned)time(NULL));
	for(k = 0; k < 10; k++){
		for(i = 0; i < n; i++){
			vet[i] = rand()%MAX;
			printf("%d ",vet[i]);
		}

		printf("\n\n");
		t0 = clock();
		bucketsort(vet, n);
		tf = clock();
		
		tempo_gasto = ((double) (tf - t0)) / CLOCKS_PER_SEC;
		media += tempo_gasto;
		printf("\n%d): %lf s\n\n",(k+1), tempo_gasto);
		printf("-----------------------------------\n\n");
	}
	
	printf("\nMedia: %lf s\n",media/10);
	
	return 0;
}  
