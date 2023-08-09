#include <stdio.h>

int maximoElementoVetor(int v[], int *i, int n, int *a);

int main(void){
  int i, tamVetor, n=0 , a;
  
  printf("Digite Tamanho do Vetor: "); 
  scanf("%d", &tamVetor);

  int v[tamVetor];
  
  for ( i =0; i < tamVetor; i++ ){
     printf("Digite elemento do Vetor[%d]: ", i);
	 scanf("%d", &v[i]);
	 n++;
  }
     
   maximoElementoVetor(v, &i, n, &a);
   printf("Resultado => %d", a);
}

int maximoElementoVetor(int v[], int *i, int n, int *a){
    if (*i != n){
		if ( v[*i] < v[*i+1]){
		*a = v[*i+1];
		*i = *i + 1;
		}
		return maximoElementoVetor(v, i, n, a);
  }
  else {
  	return 0;
  }
}
