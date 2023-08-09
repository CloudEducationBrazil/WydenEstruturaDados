#include <stdio.h>

int maximoElementoVetor(int v[], int n, int cont);

int main(void){
  int tamVetor;
  
  printf("Digite Tamanho do Vetor: "); 
  scanf("%d", &tamVetor);

  int v[tamVetor];
  
  for ( int x =0; x < tamVetor; x++ ){
     printf("Digite elemento do Vetor[%d]: ", x);
	 scanf("%d", &v[x]);
  }
     
  printf("Resultado => %d", maximoElementoVetor(v, tamVetor-1, tamVetor-1) );
}

int maximoElementoVetor(int v[], int n, int cont)
{ 
   if (cont ==  n - 1) return v[cont];
   return ( maximoElementoVetor(v, n, cont + 1) );

}
