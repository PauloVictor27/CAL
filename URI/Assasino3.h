#include <stdio.h>      
#include <stdlib.h>
#include <string.h>     
#include <math.h>
#include <time.h>

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
        if(n->mortes != 0 && n->status == 0){
			printf("%s %d\n", n->nome, n->mortes);
		}
        exibirOrdem(n->dir);
    }
}

//Inserção do primeiro parametro
void buscaAssasino(No **n, char nome[10]){
     if(*n == NULL){
		//printf("A ");
		*n = (No*) malloc(sizeof(No));
		strcpy((*n)->nome,nome);
		(*n)->mortes = 0;
		(*n)->status = 0;
		(*n)->esq = NULL;
		(*n)->dir = NULL;   
     }else{
		 }if(strcmp((*n)->nome,nome) == 0){
				(*n)->mortes++;
		 }else{
			if(strcmp((*n)->nome,nome) > 0){  
				buscaAssasino(&(*n)->esq, nome);
			}else{  
				buscaAssasino(&(*n)->dir, nome);
			}
		}
 }

void buscaVitima(No **n, char nome[10]){
     if(*n == NULL){
		//printf("B ");
		*n = (No*) malloc(sizeof(No));
		strcpy((*n)->nome,nome);
		(*n)->mortes = 0;
		(*n)->status = 0;
		(*n)->esq = NULL;
		(*n)->dir = NULL;   
     }else{
		 }if(strcmp((*n)->nome,nome) == 0){
				(*n)->status++;
		 }else{
			if(strcmp((*n)->nome,nome) > 0){  
				buscaVitima(&(*n)->esq, nome);
			}else{  
				buscaVitima(&(*n)->dir, nome);
			}
		}
 }

/*
int vivo(No **n, char nome[10]){
	 int ret;
     if(*n == NULL){
		ret = 0;  
     }else{
		 }if(strcmp((*n)->nome,nome) == 0){
			 printf("%d ",(*n)->status);
				ret = (*n)->status;
		 }else{
			if(strcmp((*n)->nome,nome) > 0){  
				buscaVitima(&(*n)->esq, nome);
			}else{  
				buscaVitima(&(*n)->dir, nome);
			}
		}
		return ret;
 }
 */

