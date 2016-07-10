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
	printf("pivo = %d -> %d\n",i,v[i]);
	return i;
}

void quicksort(int *a, int p, int r, int espaco, int tamanho)
{
	int q, i, j;
	for(i = 0; i < espaco; i++){
    	printf("-");
    }
	printf("quicksort(%d,%d)\n",p,r);
	//printf("pivo = %d -> %d\n",q,a[q]);
	
	if (p < r) {
		q = particao(a, p, r);
		for(j = 0; j < tamanho; j++){
    		printf("%d ",a[j]);
    	}
    	printf("\n");
		quicksort(a, p, q, espaco+1, tamanho);
		quicksort(a, q + 1, r, espaco+1, tamanho);	
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
	quicksort(vet, 0, n-1, 0, n);
	
	for(i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	
	return 0;
}
