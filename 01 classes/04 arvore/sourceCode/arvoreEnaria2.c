/******************************************************************************
     arvoreEnaria2.c
  Este programa gerencia arvores n-arias (cada noh pode ter um numero ilimitado
  de filhos). Cada noh possui dois ponteiros um para seu ultimo filho e um para 
  o seu irmao a direita (essa lista de irmaos funciona como uma lista ligada).
******************************************************************************/
#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;
typedef char TIPOCHAVE;

typedef struct auxNo{
  TIPOCHAVE chave;
  struct auxNo * ultimoFilho; 
  struct auxNo * proximoIrmao; 
} NO, * PONT;


/* retorna o endereco do NO que contem chave=ch ou NULL caso a chave nao seja
   encontrada.                                                                */
PONT buscarChave(PONT raiz, TIPOCHAVE ch){
  if (raiz == NULL) return NULL;
  if (raiz->chave == ch) return raiz;
  PONT aux = buscarChave(raiz->ultimoFilho, ch);
  if (aux) return aux;
  return buscarChave(raiz->proximoIrmao, ch);
}  

/* retorna o tamanho (numero de nos da arvore) */
int numeroDeNos(PONT raiz){
   if (!raiz) return 0;
   int res = 1;
   PONT filhos = raiz->ultimoFilho;
   while (filhos != NULL){
      res += numeroDeNos(filhos);
      filhos = filhos->proximoIrmao;
   }
   return res;
}

/* retorna o tamanho (numero de nos da arvore) */
int numeroDeNos2(PONT raiz){
   if (!raiz) return 0;
   return 1 + numeroDeNos2(raiz->ultimoFilho) + numeroDeNos2(raiz->proximoIrmao);
}

/* retorna a altura da arvore */
int altura(PONT raiz){
   if (!raiz) return -1;
   int max = -1;
   int temp;
   PONT filhos = raiz->ultimoFilho;
   while (filhos != NULL){
      temp = altura(filhos);
      if (temp > max) max = temp;
      filhos = filhos->proximoIrmao;
   }
   return max + 1;
}
PONT criarNovoNo(TIPOCHAVE ch){
   PONT novoNo = (PONT)malloc(sizeof(NO));
   novoNo->ultimoFilho = NULL;
   novoNo->proximoIrmao = NULL;
   novoNo->chave = ch;
   return novoNo;
}

bool inserirFilho(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai){
     PONT pai = buscarChave(raiz, chavePai);
     if (!pai) return false;
     PONT novo = criarNovoNo(novaChave);
     novo->ultimoFilho = NULL;
     novo->proximoIrmao = pai->ultimoFilho;
     pai->ultimoFilho = novo;
     return true;
}

void exibirArvore(PONT raiz){
  if (raiz == NULL) return;
  printf("%c",raiz->chave);
  PONT filhos = raiz->ultimoFilho;
  if (filhos == NULL) return;
  printf("(");
  while (filhos != NULL){
    exibirArvore(filhos);
    filhos = filhos->proximoIrmao;
  }
  printf(")");     
}

PONT criarRaiz(TIPOCHAVE novaChave){
    return criarNovoNo(novaChave);
} 
  
int main(){
  PONT raiz = criarRaiz('a');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'b','a');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'c','a');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'d','a');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'e','b');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'f','b');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'g','b');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'h','d');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'i','h');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'j','h');
  printf("Numero de nos: %i\n", numeroDeNos(raiz));
  printf("Altura: %i\n", altura(raiz));    
  exibirArvore(raiz);
  printf("\n");

  char fim;
  printf("\nPressione <ENTER> para terminar.\n");
  scanf("%c",&fim);

  return 0;
}
  
