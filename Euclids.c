#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>       
#include <sys/time.h>

typedef struct{
    int d;
    int x;
    int y;
}Trio;

//O(n²)
Trio euclids(int a, int b){
	Trio ret;
	Trio aux;
		
	if (b == 0){
		aux.d = a;
		aux.x = 1;
		aux.y = 0;
		return aux;
	}
	
	aux = euclids(b, a%b);
	ret.d = aux.d;
	ret.x = aux.y;
	ret.y = aux.x -((a/b)*aux.y);
	
	return ret;
}

void modulo(int a, int b, int c){
	int ret, i;
	Trio aux = euclids(a, c);
	
	if (aux.d % b == 0 || b % aux.d == 0){
		ret = (aux.x*(b/aux.d))%c;
		if(ret < 0){
			ret += c;
		}
		//printf("Solucao: %d\n", ret);
		for(i = 0; i < aux.d; i++){
			printf("Solucao %d: %d\n",(i+1),(ret + (i*(c/aux.d)))%c);
		}
		
	}else{
		printf("Nenhuma solucao\n");
	}
}

int main(){
	//Variaveis
	int x, y, z;
	clock_t t0, tf;
	double tempo_gasto;
	
	//Entrada
	printf("Digite 3 numeros: ");
	scanf("%d %d %d", &x, &y, &z);
	
	//Calculo
	t0 = clock();
	modulo(x, y, z);
	tf = clock();
	tempo_gasto = ((double) (tf - t0)) / CLOCKS_PER_SEC;

	//Saida
	printf("Tempo: %lf s", tempo_gasto);
	
	return 0;
}
