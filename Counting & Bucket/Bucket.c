#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>
#define MAX 40

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
	int i;
	Lista *balde;
	//Ponteiros Auxiliares
	No *aux1, *aux2, *aux3;
	aux1 = (No*) malloc(sizeof(No));
	aux2 = (No*) malloc(sizeof(No));
	aux3 = (No*) malloc(sizeof(No));
	
	//Alocação e Inicialização
	balde = (Lista *) calloc(n,sizeof(Lista));
	for(i = 0; i < n; i++){
		balde[i].primeiro = NULL;
	}
	
	//Execução
	//Ela coloca os primeiros em cima dos outros e não mantem os menores
	for(i = 0; i < n; i++){
		
		aux1->valor = vetor[i];
		aux2 = balde[((vetor[i]*n)/MAX)].primeiro;
		//Se estiver vazio, insere normal
		if(balde[((vetor[i]*n)/MAX)].primeiro == NULL){
			balde[((vetor[i]*n)/MAX)].primeiro = aux1;
			printf("%d: %d, %d", vetor[i], ((vetor[i]*n)/MAX), balde[((vetor[i]*n)/MAX)].primeiro->valor);
		}
		else{
			//Novo inicio
			if(aux1->valor <= balde[((vetor[i]*n)/MAX)].primeiro->valor){
				balde[((vetor[i]*n)/MAX)].primeiro = aux1;
				balde[((vetor[i]*n)/MAX)].primeiro->prox = aux2;
				aux2->ant = balde[((vetor[i]*n)/MAX)].primeiro;
				printf("%d: %d, %d", vetor[i], ((vetor[i]*n)/MAX), balde[((vetor[i]*n)/MAX)].primeiro->valor);
			}
			else{	
				//Percorre a lista até achar a melhor posição
				while(aux1->valor >= aux2->valor && aux2 != NULL){
					aux3 = aux2;
					aux2 = aux2->prox;
				}
				//Se chegou no final da lista
				if(aux2 == NULL){
					aux3->prox = aux1;
					aux1->ant = aux3;
					printf("%d: %d, %d", vetor[i], ((vetor[i]*n)/MAX), balde[((vetor[i]*n)/MAX)].primeiro->valor);
				}
				else{				
					aux1->ant = aux2->ant;
					aux2->ant->prox = aux1;
					aux1->prox = aux2;
					aux2->ant = aux1;
					printf("%d: %d, %d", vetor[i], ((vetor[i]*n)/MAX), balde[((vetor[i]*n)/MAX)].primeiro->valor);
				}
			}
		}
		printf("\n");
		
	}
	
	printf("\n");
	
	//Erro Aqui, ela não tá imprindo corretamente
	
	No *aux4;
	aux4 = (No*) malloc(sizeof(No));
	for(i = 0; i < n; i++){
		printf("%d: ",i);
		aux4 = balde[i].primeiro;
		if(aux4 != NULL){
			//while(aux4 != NULL){
				printf("%d ",aux4->valor);
				//aux4 = aux4->prox;
			//}
		}
		printf("\n");
	}
}


/*
void bucketsort(int *vetor, int n)
{   
	int i;
	No *balde;
	//Ponteiros Auxiliares
	No aux1, aux2;
	//aux1 = (No*) malloc(sizeof(No));
	//aux2 = (No*) malloc(sizeof(No));
	//aux3 = (No*) malloc(sizeof(No));
	
	//Alocação e Inicialização
	balde = (No *) malloc(n*sizeof(No));
	for(i = 0; i < n; i++){
		balde[i].valor = -1;
	}
	
	//Execução
	for(i = 0; i < n; i++){
		
		aux1.valor = vetor[i];
		aux2 = balde[((vetor[i]*n)/MAX)];
		//Se estiver vazio, insere normal
		if(balde[((vetor[i]*n)/MAX)].valor == -1){
			balde[((vetor[i]*n)/MAX)].valor = vetor[i];
			printf("%d: %d, %d", vetor[i], ((vetor[i]*n)/MAX), balde[((vetor[i]*n)/MAX)].valor);
		}
		else{
			//Novo inicio
			if(aux1.valor <= balde[((vetor[i]*n)/MAX)].valor){
				balde[((vetor[i]*n)/MAX)] = aux1;
				balde[((vetor[i]*n)/MAX)].prox = &aux2;
				aux2.ant = &balde[((vetor[i]*n)/MAX)];
				printf("%d: %d, %d", vetor[i], ((vetor[i]*n)/MAX), balde[((vetor[i]*n)/MAX)].valor);
			}
			else{	
				//Percorre a lista até achar a melhor posição
				while(aux1.valor >= aux2.valor && aux2.prox != NULL){
					aux2 = aux2->prox;
				}
				//Se chegou no final da lista
				if(aux2.prox == NULL){
					aux2.prox = &aux1;
					aux1.ant = &aux2;
					printf("%d: %d, %d", vetor[i], ((vetor[i]*n)/MAX), balde[((vetor[i]*n)/MAX)].valor);
				}
				else{				
					aux1.ant = aux2.ant;
					aux2.ant.prox = aux1;
					aux1.prox = aux2;
					aux2.ant = aux1;
					printf("%d: %d, %d", vetor[i], ((vetor[i]*n)/MAX), balde[((vetor[i]*n)/MAX)].valor);
				}
			}
		}
		printf("\n");
		
	}
	
	printf("\n");
	
	//Erro Aqui, ela não tá imprindo corretamente
	No aux4;
	for(i = 0; i < n; i++){
		printf("%d: ",i);
		aux4 = balde[i].valor;
		if(aux4 != NULL){
			while(aux4 != NULL){
				printf("%d ",aux4->valor);
				aux4 = aux4->prox;
			}
		}
		printf("\n");
	}

}
*/

int main(){
	
	int *vet;
	int n,i;
	//int k;
	clock_t t0, tf;
	double tempo_gasto;
	double media = 0;
	
	n = 5;
	vet = (int *) calloc(n,sizeof(int));
	srand((unsigned)time(NULL));
	//for(k = 0; k < 10; k++){
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
		printf("\n%d): %lf s\n\n",(1), tempo_gasto);
	//}
	
	printf("\nMedia: %lf s\n",media/10);
	
	return 0;
}  
