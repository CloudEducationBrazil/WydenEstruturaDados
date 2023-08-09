#include <stdio.h>

int maximoElementoVetor(int i, int n, int v[]);

int main(void){
  int tamVetor;
  
  printf("Digite Tamanho do Vetor: "); 
  scanf("%d", &tamVetor);

  int v[tamVetor];
  
  for ( int x =0; x < tamVetor; x++ ){
     printf("Digite elemento do Vetor[%d]: ", x);
	 scanf("%d", &v[x]);
  }
     
   printf("Resultado => %d", maximoElementoVetor(1, tamVetor, v));
}

int maximoElementoVetor(int i, int n, int v[])
{ 
   if (i == n - 1)
      return v[i];
   else {
   	    int aux = maximoElementoVetor(i+1, n, v);
   	    if ( aux > v[i])
           return aux; 
		else return v[i]; 
	}
}
