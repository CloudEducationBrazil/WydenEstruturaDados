#include <stdio.h>

int maximoElementoVetor(int v[], int pos);

int main(void){
  int tamVetor;
  
  printf("Digite Tamanho do Vetor: "); 
  scanf("%d", &tamVetor);

  int v[tamVetor];
  
  for ( int x =0; x < tamVetor; x++ ){
     printf("Digite elemento do Vetor[%d]: ", x);
	 scanf("%d", &v[x]);
  }
     
   printf("Resultado => %d", maximoElementoVetor(v, 0));
}

int maximoElementoVetor(int v[], int pos)
{  int flag = v[0];
   if (pos < 4) 
   {  if ( v[pos]>flag){
      flag = v[pos];
      return maximoElementoVetor(v, pos+1);
  	}
  	else return flag;
  }
   else 
  { return flag;  }
}
