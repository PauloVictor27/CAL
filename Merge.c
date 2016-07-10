#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h> 

//Relação de Recorrencia: T(n) = 2T(n/2) + O(n)
//                        2T(n/2) = 4T(n/4) + O(n/2)
//                        ...
//                        (2^h)T(n/(2^h)) = (2^h+1)T(n/(2^h+1)) + O(n/(2^h+1))
//                        T(1) = O(1)
//Espaço: O(n) no vetor original e auxiliar
//Tempo: O(n log n) a O(n log 2n)


void merge(int *v, int in, int fi, int mid){
	int i, j, k, *aux;
	
	i = in;
    j = mid + 1;
    k = 0;
    
    aux = (int *) malloc(sizeof(int) * (fi - in + 1));

    while(i <= mid || j  <= fi) {
        if (i == mid+ 1 ) { 
            aux[k] = v[j];
            j++;
            k++;
        } 
        else {
            if (j == fi + 1) { 
                aux[k] = v[i];
                i++;
                k++;
            } 
            else {
                if (v[i] < v[j]) { 
                    aux[k] = v[i];
                    i++;
                    k++;
                } 
                else { 
                    aux[k] = v[j];
                    j++;
                    k++;
                }
            }
        }

    }
    
    for(i = in; i <= fi; i++) {
        v[i] = aux[i - in];
    }
    free(aux);
}

void mergesort(int *vetor, int inicio, int fim, int espaco) {
	
    int metade, i, j;
    for(i = 0; i < espaco; i++){
    	printf("-");
    }
    printf("MergeSort(%d,%d)\n",inicio,fim);
    if(inicio == fim) return;

    metade = (inicio + fim ) / 2;
    mergesort(vetor, inicio, metade, espaco+1);
    mergesort(vetor, metade + 1, fim,espaco+1);
    merge(vetor, inicio, fim, metade);
    for(j = inicio; j <= fim; j++){
    	printf("%d ",vetor[j]);
    }
    printf("\n");

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
	mergesort(vet, 0, n-1,0);
	
	
	return 0;
}
