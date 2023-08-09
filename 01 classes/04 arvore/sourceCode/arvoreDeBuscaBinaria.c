 /******************************************************************************
     arvoreDeBuscaBinaria.c
  Este programa gerencia arvores de busca binarias.
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
  TIPOCHAVE chave;
  struct aux *esq, *dir;
} NO;

typedef NO* PONT;

/* retorna o endereco do no que contem chave=ch ou NULL caso a chave nao seja
   encontrada. Utiliza busca binaria recursiva                                */
PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){
  if (raiz == NULL) return NULL;
  if (raiz->chave == ch) return raiz;
  if (raiz->chave<ch) 
    return buscaBinaria(ch,raiz->dir);
  return buscaBinaria(ch,raiz->esq);
}  

/* retorna o endereco do no que contem chave=ch ou NULL caso a chave nao seja
   encontrada. Utiliza busca binaria iterativa                                */
PONT buscaBinariaIterativa(PONT raiz, TIPOCHAVE ch){
  PONT atual = raiz;
  while (atual) {
    if(atual->chave == ch) return atual;
    if(ch < atual->chave) atual = atual->esq;
    else atual = atual->dir;
  }
  return NULL;
}

/* cria um novo (aloca memoria e preenche valores) no com chave=ch e retorna 
   seu endereco */
PONT criarNovoNo(TIPOCHAVE ch){
   PONT novoNo = (PONT)malloc(sizeof(NO));
   novoNo->esq = NULL;
   novoNo->dir = NULL;
   novoNo->chave = ch;
   return novoNo;
}


/* insere um novo no com chave=novaChave na arvore binaria 
   cujo endereco da raiz eh passado no parametro raiz */
bool inserirNoIterativo(PONT* raiz, TIPOCHAVE ch){
  if (*raiz == NULL){
    *raiz = criarNovoNo(ch);
    return true;
  } else {
    PONT atual = *raiz;
    while (atual){
      if (atual->chave > ch) {
        if (atual->esq == NULL) {
          atual->esq = criarNovoNo(ch);
          return true;
        }else atual = atual->esq;;
      }else{
        if (atual->dir == NULL) {
          atual->dir = criarNovoNo(ch);
          return true;
        }else atual = atual->dir;
      }
    }
  }
}



/* funcao auxiliar (recursiva) para insercao */
bool inserirAux(PONT raiz, TIPOCHAVE ch){
  if (raiz->chave > ch) {
    if (raiz->esq == NULL) {
      raiz->esq = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->esq, ch);
  }else{
    if (raiz->dir == NULL) {
      raiz->dir = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->dir, ch);
  }
}  

/* insere um novo no com chave=novaChave na arvore binaria apontada por raiz */
bool inserirNo(PONT * raiz, TIPOCHAVE novaChave){
  if (*raiz == NULL){
    *raiz = criarNovoNo(novaChave);
    return true;
  }
  else return inserirAux(*raiz, novaChave);    
}

/* insere um novo no com chave=novaChave na arvore binaria apontada por raiz */ 
void inserirNo2(PONT * raiz, TIPOCHAVE novaChave){
  PONT p = *raiz; 
  if (p == NULL) *raiz = criarNovoNo(novaChave); 
  else{
    if (novaChave > p->chave) inserirNo2(&(p->dir), novaChave);
    else inserirNo2(&(p->esq), novaChave);
  } 
}
 

// Busca binária não recursiva devolvendo o nó pai
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
  PONT atual = raiz;
  *pai = NULL;
  while (atual) {
    if(atual->chave == ch) return atual;
    *pai = atual;
    if(ch < atual->chave) atual = atual->esq;
    else atual = atual->dir;
  }
  return NULL;
}

/* Auxilir da funcao excluirChave, procura a maior chave menor que a chave que 
   serah excluida            */
PONT maior_esquerdo(PONT p, PONT *ant){
  *ant = p;
  p = p->esq;
  while (p->dir) {
    *ant = p;
    p = p->dir;
  }
  return(p);
}

/* exclui a chave com valor igual a ch   */
bool excluirNo(PONT *raiz, TIPOCHAVE ch){
  PONT atual, no_pai, substituto, pai_substituto;
  atual = buscaNo(*raiz, ch, &no_pai);
  if(atual == NULL) return false;
  if(!atual->esq || !atual->dir) { // tem zero ou um filho
    if(atual->esq) substituto = atual->esq;
    else substituto = atual->dir;
    if(!no_pai) {// no excluido eh raiz 
       *raiz = substituto;
    }else {
      if(no_pai->esq == atual) no_pai->esq = substituto;
      else no_pai->dir = substituto;
    }
    free(atual);
  }
  else {   // tem dois filhos
    substituto = maior_esquerdo(atual,&pai_substituto);
    atual->chave = substituto->chave;
    if (pai_substituto->esq == substituto) pai_substituto->esq = substituto->esq;
    else pai_substituto->dir = substituto->esq;
    free(substituto);
  }
  return true;
}


/* Exibe arvore Em Ordem         */
void exibirArvoreEmOrdem(PONT raiz){
  if (raiz == NULL) return;
  exibirArvoreEmOrdem(raiz->esq);
  printf("%i ",raiz->chave);
  exibirArvoreEmOrdem(raiz->dir);
}

/* Exibe arvore Pre Ordem         */
void exibirArvorePreOrdem(PONT raiz){
  if (raiz == NULL) return;
  printf("%i ",raiz->chave);
  exibirArvorePreOrdem(raiz->esq);
  exibirArvorePreOrdem(raiz->dir);
}

/* Exibe arvore Pos Ordem         */
void exibirArvorePosOrdem(PONT raiz){
  if (raiz == NULL) return;
  exibirArvorePosOrdem(raiz->esq);
  exibirArvorePosOrdem(raiz->dir);
  printf("%i ",raiz->chave);
}

/* Exibe arvore em Pre Ordem (com parenteses para os filhos) */
void exibirArvore(PONT raiz){
  if (raiz == NULL) return;
  printf("%i",raiz->chave);
  printf("(");     
  exibirArvore(raiz->esq);
  printf("|");
  exibirArvore(raiz->dir);
  printf(")");     
}


/* Exibe arvore Em Ordem (com parenteses para os filhos) */
void exibirArvore2(PONT raiz){
  if (raiz == NULL) return;
  printf("(");     
  exibirArvore2(raiz->esq);
  printf(")%i(",raiz->chave);
  exibirArvore2(raiz->dir);
  printf(")");
}

/* Exibe arvore em Pre Ordem (com parenteses para os filhos) */
void exibirArvore3(PONT raiz){
  if (raiz == NULL) return;
  printf("(");     
  exibirArvore3(raiz->esq);
  printf("|");
  exibirArvore3(raiz->dir);
  printf(")");     
  printf("%i",raiz->chave);
}

/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
void destruirAux(PONT subRaiz){
  if (subRaiz){
    destruirAux(subRaiz->esq);
    destruirAux(subRaiz->dir);
    free(subRaiz);
  }
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz    */
void destruirArvore(PONT * raiz){
  destruirAux(*raiz);
  *raiz = NULL;
}


/* inicializa arvore: raiz=NULL */
void inicializar(PONT * raiz){
  *raiz = NULL;
}

int main(void){
	// Atividade 23/05/2019 : Criar Menu
	printf("ATIVIDADE: Criar Menu para a chamada das funcoes de ARVORE...");
}
