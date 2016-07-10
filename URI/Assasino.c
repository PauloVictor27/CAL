#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>
#define NUM 10
#define OPE 5

//Complexidade O(n²)
typedef struct{
	int id;
	int mortes;
	int status;
}Assasino;

//Prototipo pra arvore
/*
typedef struct no{
	char nome;
	int mortes;
	int status;
	struct no *esq;
    struct no *dir;
}No;
 
typedef struct arvore{
	No *raiz;
}Arvore;

As inserções são feitas em ordem alfabetica, 
dai quando os recebe dois nomes (assasino e vitima) é preciso ver se ja estao na arvore e marcar quem ta morto.
Exemplos de operações com arvores estão no links.txt
 */ 

void bubble(Assasino *v, int n)
{
	int i, j; 
	Assasino aux;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (v[j].mortes < v[j + 1].mortes) {
				aux.id = v[j].id;
				aux.mortes = v[j].mortes;
				aux.status = v[j].status;
				v[j].id = v[j + 1].id;
				v[j].mortes = v[j + 1].mortes;
				v[j].status = v[j + 1].status;
				v[j + 1].id = aux.id;
				v[j + 1].mortes = aux.mortes;
				v[j + 1].status = aux.status;
			}
		}
	}
}

int main(){
	int i, a, b;
	int vivos = NUM;
	Assasino *vetorvivos;
	Assasino vetorassa[NUM];
	
	for(i = 0; i < NUM; i++){
		vetorassa[i].id = i;
		vetorassa[i].mortes = 0;
		vetorassa[i].status = 0;
	}
	
	for(i = 0; i < OPE; i++){
		printf("Digite a %d) interacao: ",i+1);
		scanf("%d %d", &a, &b);
		if(vetorassa[b].status != 0 || a == b){
			while(vetorassa[b].status != 0 || a == b){
				printf("Entrada invalida, redigite: ");
				scanf("%d %d", &a, &b);
			}
		}
		vetorassa[a].mortes++;
		vetorassa[b].status++;
		vivos--;
	}
	printf("\n");
	
	vetorvivos = (Assasino*) calloc(vivos,sizeof(Assasino));	
	for(i = 0; i < OPE; i++){
		printf("%d) %d %d %d\n", i, vetorassa[i].id, vetorassa[i].mortes, vetorassa[i].status);
	}
	printf("\n");
	
	int j = 0;
	for(i = 0; i < NUM; i++){
		if(vetorassa[i].status == 0)
		{
			vetorvivos[j].id = vetorassa[i].id;
			vetorvivos[j].mortes = vetorassa[i].mortes;
			vetorvivos[j].status = vetorassa[i].status;
			j++;
		}
	}
		
	for(i = 0; i < j; i++){
		printf("%d ",vetorvivos[i].id);
	}
	printf("\n\n");
	bubble(vetorvivos, vivos);
	for(i = 0; i < j; i++){
		if(vetorvivos[i].mortes != 0){
			printf("%d: %d\n",vetorvivos[i].id,vetorvivos[i].mortes);
		}
	}
	
	return 0;
}
