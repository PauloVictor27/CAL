#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>

int esquerda(int i)
{
	return 2 * i + 1;
}

int direita(int i)
{
	return 2 * i + 2;
}

void heapify(int *a, int n, int i)
{
	int e, d, maior;
	e = esquerda(i);
	d = direita(i);
	if (e < n && a[e] > a[i])
		maior = e;
	else
		maior = i;
	if (d < n && a[d] > a[maior])
		maior = d;
	if (maior != i) {
		trocar(&a[i], &a[maior]);
		heapify(a, n, maior);
	}
}

void trocar(int *n1, int *n2)
{
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void buildHeap(int *a, int n)
{
	int i;
	for (i = n / 2; i >= 0; i--)
		heapify(a, n, i);
}

void heapSort(int *v, int n)
{
	int i;
	buildHeap(v, n);
	n--;
	for (i = n; i >= 1; i--) {
		trocar(&v[0], &v[n]);
		heapify(v, n, 0);
		n--;
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
	heapSort(vet, n);
	
	for(i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	return 0;
}
