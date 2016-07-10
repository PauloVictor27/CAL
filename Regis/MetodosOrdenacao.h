#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM_MAX 300000 
#define TAM_MIN 100000 

void bubble(int *v, int n); 
/* Bubble
 * Melhor Caso: vetor ja esta ordenado
 * Pior Caso: vetor ordenado na ordem inversa
 * Caso Medio: vetor aleatoriamente organizado
 * O(n^2) em todos os casos porque os ciclos sao sempre realizados ate ao fim.
 */
 void mergeSort(int *v, int p, int r);
 /*MergeSort
  * Melhor Caso: Nunca é necessario trocar após as comparações
  * Caso Medio: Há necessidade de trocas após as comparações
  * Pior caso: Sempre é necessário efetuar a troca após as comparações
  * O(log n) em todos os casos
  */

void insercao(int *v, int n); 

/* Insercao
 * Melhor caso: Quando o vetor se encontra ordenado. Somente n-1 comparações [O(n)]
 * Caso Medio: Os demais casos exceto os casos do pior e melhor caso [ O(n^2) ] 
 * Pior caso: QUando o vetor se encontra na ordem inversa a desejada [0(n^2)]
 */ 
void quickSort(int *a, int p, int r); 
/* QuickSort 
 * Melhor caso: Ocorre quando o problema é sempre divido em subproblemas de igual tamanho após a partição. [  O(log n)  ] 
 * Caso Medio:  Todos os demais casos [ n log n]
 * Pior caso: O pior caso ocorre quando, sistematicamente, o pivô é escolhido como sendo um dos extremos de um arquivo já ordenado. [ O (n^2) ]
 */
 
void heapSort(int *v, int n);
/*
 * /*HeapSOrt
 * Melhor caso:[ O n log n]
 * Caso Medio: [ O n log n]
 * Pior caso:  [ O n log n]
 */
 
// funcoes auxiliares
void merge(int *A, int e, int q, int d);
void mSort(int *v, int n); // funcao de interface
void trocar(int *n1, int *n2);
int particao(int *v, int e, int d);
void buildHeap(int *a, int n);
void heapify(int *a, int n, int i);
