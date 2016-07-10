#include "Assasino3.h"

//O(n²)

int main(){
	
	Arvore assasinos;
	char nome1[10], nome2[10]; //Nome1: Nome do assasino, Nome2: Nome da vitima que o Nome1 matou
		
	//Criando arvore
	assasinos.raiz = NULL;
	assasinos.tamanho = 0;
	
	while(scanf("%s %s",nome1,nome2)!=EOF){				
		buscaAssasino(&assasinos.raiz, nome1);
		buscaVitima(&assasinos.raiz, nome2);
	}
	
	printf("HALL OF MURDERERS\n");
	exibirOrdem(assasinos.raiz);
	
	return 0;
}
