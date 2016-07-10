#include "Assasino2.h"

//Nota: Precisamos calcula a complexidade de tempo para o pior caso

int main(){
	
	int i;
	Arvore assasinos;
	char nome1[10], nome2[10]; //Nome1: Nome do assasino, Nome2: Nome da vitima que o Nome1 matou
	No *aux1, *aux2;
	
	//Criando arvore
	assasinos.raiz = NULL;
	assasinos.tamanho = 0;
	
	
	for(i = 0; i < NUM; i++){
				
		aux1 = (No*) malloc(sizeof(No));
		aux2 = (No*) malloc(sizeof(No));
		
		//Entrada
		scanf(" %s %s",nome1,nome2);
		//Prints de teste
		//printf("%s %s\n",nome1,nome2);
		//printf("%d\n",strcmp(nome1,nome2));
		
		//Tente consertar a função de busca, quando der certo desmarque as operações abaixo
		inserirAssasino(&assasinos.raiz, nome1);
		busca(&assasinos.raiz, aux1, nome1);
		printf("%s\n",aux1->nome);
		inserirVitima(&assasinos.raiz, nome2);
		exibirOrdem(assasinos.raiz);
		
		/*
		//Se estiver vazio
		if(assasinos.raiz == NULL){
			inserirAssasino(&assasinos.raiz, nome1);
			assasinos.tamanho++;
			inserirVitima(&assasinos.raiz, nome2);
			assasinos.tamanho++;
		}else{
			//Busca os nomes
			busca(&assasinos.raiz, aux1, nome1);
			busca(&assasinos.raiz, aux2, nome2);
			
			//Se o assasino ja esta na arvore
			if(aux1 != NULL){
				aux1->mortes++;
			}else{
				inserirAssasino(&assasinos.raiz, nome1);
				assasinos.tamanho++;
			}
			
			//Se a vitima ja esta na arvore e ainda não foi morta, ou seja, entrou como assasino
			if(aux2 != NULL && aux2->status == 0){
				aux2->status++;
			}else{
				inserirVitima(&assasinos.raiz, nome2);
				assasinos.tamanho++;
			}
			
		}*/
		
	}
	
	//Desmarque aqui tbm, é aqui que é feita a saida
	/*
	//Vetor para guardar os elementos da arvore
	No vetor[assasinos.tamanho];
	preenchimento(assasinos.raiz, vetor);
	printf("\n");
	
	//Ver se a saida é igual a da saida do exibirOrdem
	for(i = 0; i < assasinos.tamanho; i++){
		printf("%s ", vetor[i].nome);
	}
	
	printf("\n");
	
	//Aqui só imprime quem ta vivo
	printf("HALL OF MURDERERS\n");
	for(i = 0; i < assasinos.tamanho; i++){
		if(vetor[i].status == 0){
			printf("%s: %d", vetor[i].nome, vetor[i].mortes);
		}
	}
	*/
	return 0;
}
