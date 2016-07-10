#include "MetodosOrdenacao.h"
int main()
{
	int i, v[TAM_MAX], cont;
	clock_t start;  // Tempo do processador pelo programa.
	clock_t end;
	srand(time(NULL));
	for (cont = TAM_MIN; cont <= TAM_MAX; cont += 1000) {

		for (i = 0; i < cont; i++)
			v[i] = rand() % 100; 

		start = clock();

		end = clock();


		unsigned long millis = (end - start) * 1000 / CLOCKS_PER_SEC;
		printf("%ld\n", millis);
		printf("%d\n", cont);
	}
	return 0;
}

