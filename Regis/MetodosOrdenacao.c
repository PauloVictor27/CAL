#include "MetodosOrdenacao.h"

//BUBBLE SORT
/* Este método faz a comparação, da esquerda para a direita do vector, 
 * de cada elemento com o seu elemento anterior até que não seja 
 * necessário trocar mais vezes, ficando assim ordenado.
 * Também se pode percorrer o vector da direita para a esquerda.
 */
void bubble(int *v, int n)
{
	int i, j, aux;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
}


//ORDENAÇÃO POR INSERÇÃO
/* Em termos gerais, ele percorre um vetor de elementos da esquerda
 *  para a direita e à medida que avança vai deixando os elementos 
 * mais à esquerda ordenados. O algoritmo de inserção funciona da 
 * mesma maneira com que muitas pessoas ordenam cartas em um jogo de 
 * baralho como o pôquer*/
void insercao(int *v, int n)
{
	int i, j, x;
	for (i = 1; i < n; i++) {
		x = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > x) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = x;
	}
}

//QUICK SORT
/*o Quicksort ordena as duasublistas de chaves menores e maiores 
 * recursivamente até que a lista completa se encontre ordenada. 
 *  Os passos são:

    Escolha um elemento da lista, denominado pivô;
    Rearranje a lista de forma que todos os elementos anteriores ao pivô 
    * sejam menores que ele, e todos os elementos posteriores ao pivô
    *  sejam maiores que ele. Ao fim do processo o pivô estará em sua
    *  posição final e haverá duas sublistas não ordenadas. 
    * Essa operação é denominada partição;
    Recursivamente ordene a sublista dos elementos menores e a sublista dos elementos maiores;

*/

void quickSort(int *a, int p, int r)
{
	int q;
	if (p < r) {
		q = particao(a, p, r);
		quickSort(a, p, q);
		quickSort(a, q + 1, r);
	}
}

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

//MERGE SORT
/*Os três passos úteis dos algoritmos dividir-para-conquistar, 
 * ou divide and conquer, que se aplicam ao merge sort são:
    Dividir: Dividir os dados em subsequências pequenas;
    Conquistar: Classificar as duas metades recursivamente aplicando o merge sort;
    Combinar: Juntar as duas metades em um único conjunto já classificado.
*/

void merge(int *v, int p, int q, int r)
{
	int *temp, p1, p2, tamanho;
	int fim1 = 0, fim2 = 0, i, j, k;

	tamanho = r - p + 1;
	p1 = p; // inicio do vetor a esquerda
	p2 = q + 1; // inicio do vetor a direita
	if ((temp = (int *) malloc(tamanho * sizeof (int))) == NULL) {
		printf("ERRO: nao foi possivel alocar o vetor.");
		exit(1);
	} else {
		for (i = 0; i < tamanho; i++) {
			if (!fim1 && !fim2) // nenhum dos vetores chegou ao fim
			{
				if (v[p1] < v[p2])
					temp[i] = v[p1++]; // seleciona o menor
				else
					temp[i] = v[p2++];
				if (p1 > q) fim1 = 1;
				if (p2 > r) fim2 = 1;
			} else {
				if (!fim1)
					temp[i] = v[p1++];
				else
					temp[i] = v[p2++];
			}
		}
		// copia vetor temp para o vetor v
		for (j = 0, k = p; j < tamanho; j++, k++)
			v[k] = temp[j];
		free(temp);
	}
}

void mergeSort(int *v, int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(v, p, q);
		mergeSort(v, q + 1, r);
		merge(v, p, q, r);
	}
}

void mSort(int *v, int n)
{
	mergeSort(v, 0, n - 1);
}

//Heap binário
/*O heapsort utiliza uma estrutura de dados chamada heap, para ordenar 
 * os elementos a medida que os insere na estrutura. Assim, ao final 
 * das inserções, os elementos podem ser sucessivamente removidos da
 *  raiz da heap, na ordem desejada, lembrando-se sempre de manter 
 * a propriedade de max-heap.

A heap pode ser representada como uma árvore 
* (uma árvore binária com propriedades especiais2 ) ou como um vetor. 
* Para uma ordenação crescente, deve ser construído uma heap mínima 
* (o menor elemento fica na raiz). Para uma ordenação decrescente, 
* deve ser construído uma heap máxima (o maior elemento fica na raiz).
* 
*/

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

/*
void heapSort(int *v, int n)
{
	int i,aux;
	buildHeap(v, n);
	n--;
	for (i = n; i >= 1; i--) {
		aux = v[0];
		v[0] = v[n];
		heapify(v, n, 0);
		n--;
	}
}*/
