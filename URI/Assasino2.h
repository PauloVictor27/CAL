#include <stdio.h>      
#include <stdlib.h>
#include <string.h>     
#include <math.h>
#include <time.h>
#define NUM 1 //Numero de operações


//Status: 0 pra vivo e 1 pra morto
typedef struct no{
	char nome[10];
	int mortes;
	int status;
	struct no *esq;
    struct no *dir;
}No;

typedef struct {
	int tamanho;
    No *raiz;
}Arvore;

//Função que imprime a arvore em ordem alfabetica
void exibirOrdem(No *n){
    if(n != NULL){
        exibirOrdem(n->esq);
        printf("%s ", n->nome);
        exibirOrdem(n->dir);
    }
}

//Função para preencher o vetor da arvore, similar a função de cima
void preenchimento(No *n, No *vet){
	int i = 0;
    if(n != NULL){
        preenchimento(n->esq, vet);
        printf("%s ", n->nome);
        vet[i] = *n;
        i++;
        preenchimento(n->dir, vet);
    }
}

//Inserção do primeiro parametro
void inserirAssasino(No **n, char nome[10]){
     if(*n == NULL){
		//printf("A ");
		*n = (No*) malloc(sizeof(No));
		strcpy((*n)->nome,nome);
		(*n)->mortes = 1;
		(*n)->status = 0;
		(*n)->esq = NULL;
		(*n)->dir = NULL;   
     }else{
         if(strcmp((*n)->nome,nome) < 0){  
              inserirAssasino(&(*n)->esq, nome);
         }else if(strcmp((*n)->nome,nome) > 0){  
              inserirAssasino(&(*n)->dir, nome);
		  }
     }
 }

//Inserção do segundo parametro
void inserirVitima(No **n, char nome[10]){
     if(*n == NULL){
		//printf("B\n");
		*n = (No*) malloc(sizeof(No));
		strcpy((*n)->nome,nome);
		(*n)->mortes = 0;
		(*n)->status = 1;
		(*n)->esq = NULL;
		(*n)->dir = NULL;   
     }else{
         if(strcmp((*n)->nome,nome) < 0){  
              inserirVitima(&(*n)->esq, nome);
         }else if(strcmp((*n)->nome,nome) > 0){  
              inserirVitima(&(*n)->dir, nome);
		  }
     }
 }

 
 //Retorna tal ponteiro em tal posição (essa função tá com problemas)
 void busca(No **n,No *aux, char nome[10]){
	 if(*n == NULL || (*n)->nome == nome){
		printf("%s\n",(*n)->nome);
		aux = (*n);  
     }else{
         if(strcmp((*n)->nome,nome) < 0){  
              busca(&(*n)->esq, aux, nome);
         }else if(strcmp((*n)->nome,nome) > 0){  
              busca(&(*n)->dir, aux, nome);
		  }
     }
 }

