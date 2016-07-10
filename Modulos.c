#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include <time.h>       
#include <sys/time.h>

//O(n²)
int modulo(int a, int b, int c){
	int ret;
	if (b == 0){
		return 1;
	}
	ret = modulo(a, b/2, c);
	ret = (ret*ret) % c;
	if(b % 2 == 1){
		return ((ret*a) % c);
	}
	return ret;
}

int main(){
	//Variaveis
	int x, y, z, resultado;
	clock_t t0, tf;
	double tempo_gasto;
	
	//Entrada
	printf("Digite 3 numeros: ");
	scanf("%d %d %d", &x, &y, &z);
	
	//Calculo
	t0 = clock();
	resultado = modulo(x,y,z);
	tf = clock();
	tempo_gasto = ((double) (tf - t0)) / CLOCKS_PER_SEC;
	
	//Saida
	printf("(%d^%d) mod %d = %d\n",x,y,z,resultado);
	printf("Tempo: %lf s", tempo_gasto);
	
	return 0;
}
