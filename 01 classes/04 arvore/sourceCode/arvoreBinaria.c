/******************************************************************************
  ArvoreBinaria.c
  Este programa gerencia arvores Binarias.
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef enum{esquerdo, direito} LADO;

typedef int bool;
typedef char TIPOCHAVE;

typedef struct aux{
  TIPOCHAVE chave;
  struct aux *esq, *dir;
} NO;

typedef NO* PONT;

/* retorna o endereco do NO que contem chave=ch ou NULL caso a chave nao seja
   encontrada.                                                                */
PONT buscarChave(TIPOCHAVE ch, PONT raiz){
  if (raiz == NULL) return NULL;
  if (raiz->chave == ch) return raiz;
  PONT aux = buscarChave(ch,raiz->esq);
  if (aux) return aux;
  return buscarChave(ch,raiz->dir);
}  

/* aloca memoria, preenche os campos e retorna o endereco de um no           */
PONT criarNovoNo(TIPOCHAVE ch){
   PONT novoNo = (PONT)malloc(sizeof(NO));
   novoNo->esq = NULL;
   novoNo->dir = NULL;
   novoNo->chave = ch;
   return novoNo;
}

/* insere um novo no como filho de um no ja existente
   o novo no sera pai do antigo filho de seu pai                             */
bool inserirFilho(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai, LADO lado){
  PONT pai = buscarChave(chavePai,raiz);
  if (!pai) return false;
  PONT novo = criarNovoNo(novaChave);
  if (lado == esquerdo){
    novo->esq = pai->esq;
    pai->esq = novo;
  }else{
     novo->esq = pai->dir;
     pai->dir = novo;              
  }
  return true;
}

/* exibe a arvore recursivamente em 'pre-ordem', ou seja, primeiro o no atual
   seguido pela subarvore a esquerda e entao a subarvore a direita          */
void exibirArvorePreOrdem(PONT raiz){
  if (raiz == NULL) return;
  printf("%c ",raiz->chave);
  exibirArvorePreOrdem(raiz->esq);
  exibirArvorePreOrdem(raiz->dir);
}

/* exibe a arvore recursivamente em 'pre-ordem', usando parenteses para 
   delimitar os descentes do elemento atual                                 */
void exibirArvore(PONT raiz){
  if (raiz == NULL) return;
  printf("%c",raiz->chave);
  printf("(");     
  exibirArvore(raiz->esq);
  printf("|");
  exibirArvore(raiz->dir);
  printf(")");     
}

/* retorna o maior entre os dois valores de entrada */
int max(int a, int b){
  if (a>b) return a;
  return b;
}

/* calcula de maneira recursiva a altura da arvore
   assumiu-se que a altura de uma folha vale zero                            */
int alturaArvore(PONT raiz){
  if (!raiz ) return -1;
  return 1 + max(alturaArvore(raiz->esq),alturaArvore(raiz->dir));
}

/* calcula de maneira recursiva a quantidade de elementos de uma arvore      */
int numeroNos(PONT raiz){
  if (!raiz ) return 0;
  return 1 + numeroNos(raiz->esq) + numeroNos(raiz->dir);
}

/* inicializa uma arvore cujo endereco da variavel que aponta para a raiz esta
   armzaenado na variavel raiz */
void inicializar(PONT * raiz){
  *raiz = NULL;
}

/* cria a raiz da arvore e coloca seu endereco na variavel apontada por raiz*/
void criarRaiz(PONT * raiz, TIPOCHAVE novaChave){
    *raiz = criarNovoNo(novaChave);
} 

int main(){
  PONT raiz;
  inicializar(&raiz);
  criarRaiz(&raiz,'a');
  inserirFilho(raiz,'b','a',esquerdo);
  inserirFilho(raiz,'c','b',direito);
  printf("Numero de Nos: %d.\n", numeroNos(raiz));
  printf("Altura: %d.\n", alturaArvore(raiz));
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'d','c',esquerdo);
  inserirFilho(raiz,'e','b',esquerdo);
  inserirFilho(raiz,'f','e',esquerdo);
  inserirFilho(raiz,'g','f',esquerdo);
  printf("Numero de Nos: %d.\n", numeroNos(raiz));
  printf("Altura: %d.\n", alturaArvore(raiz));
  exibirArvore(raiz);
  printf("\n");
  inserirFilho(raiz,'h','d',direito);
  inserirFilho(raiz,'i','h',esquerdo);
  inserirFilho(raiz,'j','i',esquerdo);
  printf("Numero de Nos: %d.\n", numeroNos(raiz));
  printf("Altura: %d.\n", alturaArvore(raiz));  
  exibirArvore(raiz);
  printf("\n");

  char fim;
  printf("\nPressione <ENTER> para terminar.\n");
  scanf("%c",&fim);

  return 0;
}
  

