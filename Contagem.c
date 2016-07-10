#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>       

/*Função Alternativa
int contagem(int tamanho, int vetor, int numeroigual){
	
	int x = 0;
	int i;
	for(i = 0; i < tamanho; i++){
		if(vetor[i] == numeroigual){
			x++;
		}
	}
	
	return x;
}
*/

int main(){

	//Variaveis
	int n, i;  //Contadores
	int *vet;  //Vetor
	int igual; //Numero para buscar
	int cont = 0;
	
	//Entrada
	printf("Digite o numero de numeros: ");
	scanf("%d",&n);
	printf("Digite o numero que queria procurar: ");
	scanf("%d",&igual);
	printf("\n");
	
	//Alocação
	vet = (int *) calloc(n,sizeof(int));
	
	//Reiniciando Tempo
	srand((unsigned)time(NULL));
	 
	//Processamento
	for(i = 0; i < n; i++){
		vet[i] = rand()%10;
		printf("vet[%d] = %d\n",i, vet[i]);
		if(vet[i] == igual){
			cont++;
		}
	}
	
	//Saida
	printf("\nContagem: %d", cont);
	
	return 0;
}
