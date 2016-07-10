#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>

//Espaço: O(n) para cada chamada da função
//Tempo: O(log n) para o melhor caso
//       O(n²) para o pior caso quando escolhido um "pivo ruin", com isso é dado mais voltas  

int particao(int *v, int e, int d)
{
	int i, j, aux;
	i = e;
	for (j = e + 1; j <= d; j++) {
		if (v[j] < v[e]) {
			i++;
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}
	aux = v[e];
	v[e] = v[i];
	v[i] = aux;
	return i;
}

void quicksort(int *a, int p, int r)
{
	int q;
	if (p < r) {
		q = particao(a, p, r);
		quicksort(a, p, q);
		quicksort(a, q + 1, r);
	}
}
 
 int main(){
	
	int *vet;
	int n,i;
	
	printf("Digite um numero: ");
	scanf("%d",&n);
	vet = (int *) calloc(n,sizeof(int));
	
	srand((unsigned)time(NULL));
	 
	for(i = 0; i < n; i++){
		vet[i] = rand()%20;
		printf("%d ",vet[i]);
	}
	
	printf("\n");
	quicksort(vet, 0, n-1);
	
	for(i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	
	return 0;
}
