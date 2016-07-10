#include <stdio.h>      
#include <stdlib.h>     


typedef struct{
	int placa;
	int tamanho;
}Carro;

//Função para evitar colocar placas iguais
//Complexidade: O(n)
int repitido(Carro aux, Carro *vet, int tam){
	int i;
	int cont = 0;
	for(i = 0; i < tam; i++){
		if(vet[i].placa == aux.placa){
			cont++;
		}
	}
	return cont;
}

int main(){
	int i,j,k;
	int lucro = 0;
	int vazio;
	char cs;
	int tamanho;
	int operacoes;
	int rep;
	Carro carroaux;
	Carro *estacionamento;
	
	//Primeira entrada
	//Complexidade: O(n)
	printf("Digite o tamanho do estacionamento e o numero de operacoes: ");
	scanf("%d %d",&tamanho,&operacoes);
	//Condição
	if(tamanho < 1 || tamanho > 1000 || operacoes < 1 || operacoes > 1000){
		while(tamanho < 1 || tamanho > 1000 || operacoes < 1 || operacoes > 1000){
			printf("Operação invalida, digite novamente: ");
			scanf("%d %d",&tamanho,&operacoes);
		}
	}

	//Alocação
	estacionamento = (Carro*) calloc(tamanho,sizeof(Carro));
	
	//Inicialização
	//Complexidade: O(n)
	for(i = 0; i < tamanho; i++){
		estacionamento[i].placa = 0;
		estacionamento[i].tamanho = 0;
	}
	
	//Segunda entrada
	//Complexidade: O(n)
	for(i = 0; i < operacoes; i++){      
			printf("Digite a %d) operacao: ",i+1);
			scanf(" %c ", &cs);
			if(cs == 'C' || cs == 'c'){
				scanf("%d %d",&carroaux.placa,&carroaux.tamanho);
				while(carroaux.placa < 1000 || carroaux.placa > 9999 || carroaux.tamanho < 1 || carroaux.tamanho > 1000){
					printf("Operação invalida, digite novamente: ");
					scanf("%d %d",&carroaux.placa,&carroaux.tamanho);
				}
			}else{
				scanf("%d",&carroaux.placa);
				while(carroaux.placa < 1000 || carroaux.placa > 9999){
					printf("Operação invalida, digite novamente: ");
					scanf("%d",&carroaux.placa);
				}
			}
			switch(cs){
				case 'C':
				case 'c':
					k = 0;
					vazio = 0;
					rep = repitido(carroaux, estacionamento, tamanho);
					if(rep != 0){
						break;
					}else{
						//Complexidade: O(n)
						while(k < tamanho){
							if(estacionamento[k].placa == 0){
								vazio++;
								if(vazio == carroaux.tamanho){
									for(j = (k - vazio +1); j <= k; j++){
										estacionamento[j].placa = carroaux.placa;
										estacionamento[j].tamanho = carroaux.tamanho;
									}
									lucro += 10;
									break;
									break;
								}
							}else{
								vazio = 0;
							}
							k++;
						}	
						break;
					}
				case 'S':   
				case 's':
					k = 0;
					//Complexidade: O(n)
					while(k < tamanho){
						if(estacionamento[k].placa == carroaux.placa){
							estacionamento[k].placa = 0;
							estacionamento[k].tamanho = 0;
						}
						k++;
					}
					break;
				default:
					printf("Operação invalida, digite de novo:\n");
					i--;
			}
		}
	
	printf("\n");
	for(i = 0; i < tamanho; i++){
		printf("%d ", estacionamento[i].placa);
	}
	printf("\n");
	printf("Lucro: %d", lucro);
	
	return 0;
}

//Complexidade em geral para o pior caso: O(n)
