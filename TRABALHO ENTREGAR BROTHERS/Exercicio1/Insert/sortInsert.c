#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <Windows.h>

const int N = 5000;

typedef struct Intervalo{
    int inicio;
    int fim;
} Intervalo;

//----------------------------------------------------
void sort(Intervalo *vetor){
	int i, j;
	Intervalo aux;
	for (i = 1; i < N; i++) {
		aux.inicio = vetor[i].inicio;
		aux.fim = vetor[i].fim;
		j = i - 1;
		while (j >= 0 && vetor[j].inicio > aux.inicio || (vetor[j].inicio == aux.inicio && vetor[j].fim > aux.fim)){
		    vetor[j + 1].inicio = vetor[j].inicio;
		    vetor[j + 1].fim = vetor[j].fim;
			j--;
		}
		vetor[j + 1].inicio = aux.inicio;
		vetor[j + 1].fim = aux.fim;
	}
}
//----------------------------------------------------
void vetorPreenche( Intervalo*, int );
void vetorMostra( Intervalo* );
int verificaOrdenacao( Intervalo* );
double time_diff(struct timeval , struct timeval);

//----------------------------------------------------
//----------------------------------------------------
int main(){
    int repeticoes, tipo_preenchimento;
    Intervalo vetor[N];
    LARGE_INTEGER inicio, fim, tempo, frequencia, tempo_total;

    printf("Digite o numero de testes que deseja executar: ");
    scanf("%i", &repeticoes);

    printf("Qual o tipo de vetor a ser utilizado?\n"
           "\t1 - Ordenado (crescente)\n"
           "\t2 - Ordenado (decrescente)\n"
           "\t(outro numero) - Aleatorio\n");
    scanf("%i", &tipo_preenchimento);

    /// inicializa uma semente de números aleatórios
    srand ( time(NULL) );

    int teste, correta;
    tempo_total.QuadPart = 0;
    for(teste=1; teste<=repeticoes; teste++){
        /// Preenche o vetor
        vetorPreenche( vetor, tipo_preenchimento );

        /// Inicia o relógio para contar o tempo
        QueryPerformanceFrequency( &frequencia );
        QueryPerformanceCounter( &inicio );

        /// Tarefa a qual queremos medir o tempo de execução (aproximação em microssegundos)
        sort( vetor );

        /// Interrompe o relógio e calcula o número de microsegundos da operação
        QueryPerformanceCounter( &fim );
        tempo.QuadPart = fim.QuadPart - inicio.QuadPart;
        tempo.QuadPart *= 1000000;
        tempo.QuadPart /= frequencia.QuadPart;
        tempo_total.QuadPart += tempo.QuadPart / repeticoes;

        /// Verifica se resposta esta correta
        correta = verificaOrdenacao( vetor );

        /// Mostra resultados
        printf("Teste n. %i: %li us" , teste, tempo );
        printf("%s\n", (correta==0 ? " (ORDENACAO INCORRETA!)":""));
    }

    /// Mostra a média de tempo
    printf("\n\nTEMPO MEDIO: %li us\n" , tempo_total);

    return 0;
}




//----------------------------------------------------
void vetorPreenche( Intervalo *v, int tipo ){
    int i;
    switch( tipo ){
        case 1: // preenchimento ordenado - não aleatório
            for(i=0; i<N; i++){
                v[i].inicio = i;
                v[i].fim = i+10;
            }
            break;
        case 2: // preenchimento ordenado ao inverso - não aleatório
            for(i=0; i<N; i++){
                v[i].inicio = N-i;
                v[i].fim = N-i+10;
            }
            break;
        default: // preenchimento aleatório
            for(i=0; i<N; i++){
                v[i].inicio = rand() % 10000;
                v[i].fim = v[i].inicio + (rand() % 10000);
            }
    }
    return;
}
//----------------------------------------------------
void vetorMostra( Intervalo *v ){
    int i;
    for(i=0; i<N; i++)
        printf("%i - %i", v[i].inicio, v[i].fim);
    puts("");
}
//----------------------------------------------------
int verificaOrdenacao( Intervalo *v ){
    int i;
    for(i=1; i<N; i++){
        if( (v[i].inicio < v[i-1].inicio) || (v[i].inicio == v[i-1].inicio && v[i].fim < v[i-1].fim) )
            return 0;
    }
    return 1;
}
//----------------------------------------------------
double time_diff(struct timeval x , struct timeval y){
    double diff;
    diff = (y.tv_sec - x.tv_sec) + 1e-6 * (y.tv_usec - x.tv_usec); /* in seconds */
    return diff;
}
