#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//#define false 0;
//#define true 1;
typedef int bool;

typedef int PRIMARYKEY;

typedef struct aux {
	PRIMARYKEY chave;
	struct aux *sae;
	struct aux *sad;
} NO;

typedef NO* PONT;

PONT inicializaArvore(){
	return(NULL);
}

PONT CriaElementoNo(PRIMARYKEY ch){
	PONT novoNO = (PONT) malloc(sizeof(NO));
	novoNO->chave = ch;
	novoNO->sae = NULL;
	novoNO->sad = NULL;
	
	return novoNO;
}

PONT AdicionaElemento(PONT raiz, PONT no){
  if ( raiz == NULL ) return no;
  
  if ( no->chave < raiz->chave )
     raiz->sae = AdicionaElemento(raiz->sae, no);
  else
     raiz->sad = AdicionaElemento(raiz->sad, no);
     
  return raiz;
}
int main(void){
	PONT r= inicializaArvore();
	PONT no = CriaElementoNo(23);
	r = AdicionaElemento(r, no);

}


