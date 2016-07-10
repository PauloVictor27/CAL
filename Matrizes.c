#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>
#include <sys/time.h>       

int main(){

	//Variaveis
	int ordem;                                      // O(1);
	int i, j, k;                          //Contadores O(1);
	int **a, **b, **c;                    //Matrizes   O(1);
	
	//Entrada
	printf("Digite a ordem das matrizes: ");        // O(1);
	scanf("%d",&ordem);                             // O(1);
	printf("\n");                                   // O(1);
	
	//Reiniciando Tempo
	srand((unsigned)time(NULL));                    // O(1);
	
	//Alocação
	a = (int **) calloc(ordem ,sizeof(int*));       // O(1);
	b = (int **) calloc(ordem ,sizeof(int*));       // O(1);
	c = (int **) calloc(ordem ,sizeof(int*));       // O(1);
	
	for(i = 0; i < ordem; i++){                     // O(n);
		a[i] = (int *) calloc(ordem ,sizeof(int*)); 
		b[i] = (int *) calloc(ordem ,sizeof(int*)); 
		c[i] = (int *) calloc(ordem ,sizeof(int*)); 
	}
	
	//Inicialização	
	for(i = 0; i < ordem; i++){                     // O(n²);
		for(j = 0; j < ordem; j++){                 
			a[i][j] = rand()%10;                    
			b[i][j] = rand()%10;                    
			c[i][j] = 0;                            
		}
	}
	
	//Imprimindo matriz A
	for(i = 0; i < ordem; i++){                     // O(n²);
		for(j = 0; j < ordem; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");                                   // O(1);
	
	//Imprimindo matriz B
	for(i = 0; i < ordem; i++){                     // O(n²);
		for(j = 0; j < ordem; j++){
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");                                    // O(1);
	
	//Multiplicação
	for(i = 0; i < ordem; i++){                      // O(n³);
		for(j = 0; j < ordem; j++){
			for(k = 0; k < ordem; k++){
				c[i][j] += a[i][k]*b[k][j];	
			}
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
		
	return 0;                                        // O(1);
}
