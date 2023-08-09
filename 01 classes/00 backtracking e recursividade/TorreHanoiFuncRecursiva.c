#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int movimentohanoi(double num_move){
	
	if(num_move <= 0)
		return 1;	
	else
		return (pow(2,num_move)-1);	
	
	
}

main(){
	
	double n_move, retorno;
	
	scanf("%lf", &n_move);

	retorno = movimentohanoi(n_move);
		 
	printf("Numeros de Movimentos permitidos: %lf\n", retorno);
	
	system("pause");
	
}
