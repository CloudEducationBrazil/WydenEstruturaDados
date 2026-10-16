/******************************************************************************/
/*              Este programa gerencia arvores AVL                            */
/*  Arvores AVL sao arvores balanceadas na altura.                            */
/*  O nome AVL vem de seus criadores Adelson Velsky e Landis, cuja primeira   */
/*    referência encontra-se no documento "Algoritmos para organização da     */
/*    informação" de 1962.                                                    */
/******************************************************************************/

#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
	TIPOCHAVE chave;
	struct aux *esq;
	struct aux *dir;
	int bal; // fator de balanceamento (0, -1 ou +1) => alt. direita - alt. esquerda
} NO, *PONT;

/* cria um novo (aloca memoria e preenche valores) no com chave=ch e retorna 
       seu endereco */
PONT criarNovoNo(TIPOCHAVE ch){
	PONT novoNo = (PONT)malloc(sizeof(NO));
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	novoNo->chave = ch;
	novoNo->bal = 0;
	return novoNo;
}


// Retorna o maior valor entre dois inteiros
int max(int a, int b){
	if (a>b) return a;
	return b;
}

// Retorna a altura de uma (sub-)arvore
int altura(PONT p){
	if (!p) return -1;
	else return 1 + max(altura(p->esq),altura(p->dir));
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
	exibirArvorePreOrdem(raiz->esq);
	exibirArvorePreOrdem(raiz->dir);
	printf("%i ",raiz->chave);
}

/* Exibe arvore Em Ordem (com parenteses para os filhos)    */
void exibirArvore(PONT raiz){
	if (raiz == NULL) return;
	printf("%i[%i]",raiz->chave,raiz->bal);
	printf("(");     
	exibirArvore(raiz->esq);
	exibirArvore(raiz->dir);
	printf(")");     
}

/* Exibe arvore Pre-Ordem indicando pai de cada no    */
void exibirArvore2(PONT raiz, TIPOCHAVE chavePai){
	if (raiz == NULL) return;
	printf("(%i,%i) ",chavePai,raiz->chave);
	exibirArvore2(raiz->esq,raiz->chave);
	exibirArvore2(raiz->dir,raiz->chave);
}


// Verifica se árvore é AVL
bool ehAVL(PONT p){
	int e,d;
	bool ok = true;
	if(p){
		ok = ehAVL(p->esq);
		if(ok) ok = ehAVL(p->dir);
		if(ok){
			e = altura(p->esq);
			d = altura(p->dir);
			if(e-d > 1 || e-d < -1) ok = false;  
			else ok = true;
		}
	}
	return(ok);
}

// Verifica se árvore é AVL
bool ehAVL2(PONT p, int* alt){
    if (!p){
       *alt=-1;
       return true;
    }
    bool res;
    int d, e;
    res = ehAVL2(p->dir,&d);
    if (!res) return false;
    res = ehAVL2(p->esq,&e);
    if (!res) return false;
    if (d-e != p->bal) printf("### O campo 'bal' do no '%i' esta com valor incorreto de balanceamento. ###\n",p->chave);
    if ((d-e<-1) || (d-e>1)) return false;
	*alt = max(d,e)+1; 
	return true;	
}

int atualizarBalanceamentoTotal(PONT raiz){
	if (!raiz) return 0;
	int d = atualizarBalanceamentoTotal(raiz->dir);
	int e = atualizarBalanceamentoTotal(raiz->esq);
	raiz->bal = d-e;
	return max(d,e)+1;
}


/* Rotações à direita (LL e LR) 
   Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
   iniciada por p */
PONT rotacaoL(PONT p){
	printf("Rotacao a esquerda, problema no no: %i\n",p->chave);
	PONT u, v;
	u = p->esq;
	if(u->bal == -1) {   // LL
		p->esq = u->dir;
		u->dir = p;
		p->bal = 0;
		u->bal = 0;
		return u;
	} else if (u->bal == 1) {  // LR
		v = u->dir;
		u->dir = v->esq;
		v->esq = u;
		p->esq = v->dir;
		v->dir = p;
		if(v->bal == -1) p->bal = 1;
		else p->bal = 0;
		if(v->bal == 1) u->bal = -1;
		else u->bal = 0;
		v->bal = 0;
		return v;
	}else{   // caso necessario apenas para a exclusao (u->bal == 0)
		p->esq = u->dir;
		u->dir = p;
		p->bal = -1;
		u->bal = 1;
		return u;
	}
}

/* Rotações à esquerda (RR e RL) 
   Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
   iniciada por p */
PONT rotacaoR(PONT p){
	printf("Rotacao a direita, problema no no: %i\n",p->chave);
	PONT u, v;
	u = p->dir;
	if(u->bal == 1) {   // RR
		p->dir = u->esq;
		u->esq = p;
		p->bal = 0;
		u->bal = 0;
		return u;
	} else if (u->bal == -1){  // RL
		v = u->esq;
		u->esq = v->dir;
		v->dir = u;
		p->dir = v->esq;
		v->esq = p;
		if(v->bal == 1) p->bal = -1;
		else p->bal = 0;
		if(v->bal == -1) u->bal = 1;
		else u->bal = 0;
		v->bal = 0;
		return v;
	}else{   // caso necessario apenas para a exclusao (u->bal == 0)
		p->dir = u->esq;
		u->esq = p;
		p->bal = 1;
		u->bal = -1;
		return u;	}
}



/* Inserção AVL: p é inicializado com o endereco do nó raiz e 
   *alterou com false                                         */
void inserirAVL(PONT* pp, TIPOCHAVE ch, bool* alterou){
	PONT p = *pp;
	if(!p){
		*pp = criarNovoNo(ch);
		*alterou = true;
	} else {
		if(ch < p->chave) {
			inserirAVL(&(p->esq), ch, alterou);
			if(*alterou)
				switch (p->bal) {
					case 1 : p->bal = 0;
					*alterou = false;
					break;
					case 0 : p->bal = -1;
					break;
					case -1: *pp = rotacaoL(p);
					*alterou = false;
					break;
				}
		} else {
			inserirAVL(&(p->dir), ch, alterou);
			if(*alterou)
				switch (p->bal) {
					case -1: p->bal = 0;
					*alterou = false;
					break;
					case 0 : p->bal = 1;
					break;
					case 1 : *pp = rotacaoR(p);
					*alterou = false;
					break;
				}
		}
	}
}

/* retorna o endereco do NO que contem chave=ch ou NULL caso a chave nao seja
       encontrada. Utiliza busca binaria recursiva                                */
PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){
	if (raiz == NULL) return NULL;
	if (raiz->chave == ch) return raiz;
	if (raiz->chave<ch) 
		return buscaBinaria(ch,raiz->dir);
	return buscaBinaria(ch,raiz->esq);
}  


// Busca binária não recursiva devolvendo o nó pai
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
	PONT atual = raiz;
	*pai = NULL;
	while (atual) {
		if(atual->chave == ch)
			return(atual);
		*pai = atual;
		if(ch < atual->chave) atual = atual->esq;
		else atual = atual->dir;
	}
	return(NULL);
}

/* Auxilir da funcao excluirChave, procura a maior chave menor que a chave que 
   serah excluida            */
PONT maiorAEsquerda(PONT p, PONT *ant){
  *ant = p;
  p = p->esq;
  while (p->dir) {
    *ant = p;
    p = p->dir;
  }
  return(p);
}


/* exclui a chave com valor igual a ch   */
bool excluirAVL(PONT* raiz, TIPOCHAVE ch, bool* alterou){
  PONT atual = *raiz;
  if (!atual) return false;
  if (atual->chave == ch){
    PONT no_pai, substituto, pai_substituto;
    atual = buscaNo(*raiz, ch, &no_pai);
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
      *alterou = true;
      return true;
    }
    else {   // tem dois filhos
      substituto = maiorAEsquerda(atual,&pai_substituto);
      atual->chave = substituto->chave;
      bool res = excluirAVL(&(atual->esq), substituto->chave, alterou);
      printf("Excluir recursivo a esquerda (substituicao por maior a esquerda): %i(%i)\n", atual->chave, atual->bal); 
      if (*alterou){
         switch (atual->bal){
            case -1: atual->bal = 0;
            return true;
            case 0: atual->bal = 1;
            *alterou = false;
            return true;
            case 1: atual->esq = rotacaoR(atual);
            if (atual->bal != 0) *alterou = false;
            return true;
         }
      }
    }
    return true;
  }else{
    bool res;
    if (ch > atual->chave) {
      res = excluirAVL(&(atual->dir), ch, alterou);
      printf("Excluir recursivo a direita: %i(%i)\n", atual->chave, atual->bal); 
      if (*alterou){
         switch (atual->bal){
            case 1: atual->bal = 0;
            return true;
            case 0: atual->bal = -1;
            *alterou = false;
            return true;
            case -1: *raiz = rotacaoL(atual);
            if (atual->bal != 0) *alterou = false;
            return true;
         }
      }
    }else{
      res = excluirAVL(&(atual->esq), ch, alterou);
      printf("Excluir recursivo a esquerda: %i(%i)\n", atual->chave, atual->bal); 
      if (*alterou){
         switch (atual->bal){
            case -1: atual->bal = 0;
            return true;
            case 0: atual->bal = 1;
            *alterou = false;
            return true;
            case 1: *raiz = rotacaoR(atual);
            if (atual->bal != 0) *alterou = false;
            return true;
         }
      }
    }
    return res;
  }
}



/* Rotações à direita (LL e LR) */
void rotacaoL2(PONT *p){
	printf("Rotacao a esquerda, problema no no: %i\n",(*p)->chave);
	PONT u, v;
	u = (*p)->esq;
	if(u->bal == -1) {   // LL
		(*p)->esq = u->dir;
		u->dir = *p;
		(*p)->bal = 0;
		*p = u;
	} else {  // LR
		v = u->dir;
		u->dir = v->esq;
		v->esq = u;
		(*p)->esq = v->dir;
		v->dir = *p;
		if(v->bal == -1)(*p)->bal = 1;
		else (*p)->bal = 0;
		if(v->bal == 1) u->bal = -1;
		else u->bal = 0;
		*p = v;
	}
	(*p)->bal = 0; // balanço final da raiz (p) da subarvore
}

/* Rotações à esquerda (RR e RL)    */
void rotacaoR2(PONT *p){
	printf("Rotacao a direita, problema no no: %i\n",(*p)->chave);
	PONT u, v;
	u = (*p)->dir;
	if(u->bal == 1) {   // RR
		(*p)->dir = u->esq;
		u->esq = *p;
		(*p)->bal = 0;
		*p = u;
	} else {  // RL
		v = u->esq;
		u->esq = v->dir;
		v->dir = u;
		(*p)->dir = v->esq;
		v->esq = *p;
		if(v->bal == 1) (*p)->bal = -1;
		else (*p)->bal = 0;
		if(v->bal == -1) u->bal = 1;
		else u->bal = 0;
		*p = v;
	}
	(*p)->bal = 0; // balanço final da raiz (p) da subarvore
}



/* Inserção AVL2: p é inicializado com raiz e *alterou com false */
void inserirAVL2(PONT *pp, TIPOCHAVE ch, bool *alterou){
	PONT p = *pp;
	if(!p){
		*pp = criarNovoNo(ch);
		*alterou = true;
	} else {
		if(ch < p->chave) {
            inserirAVL2(&(p->esq), ch, alterou);
			if(*alterou)
				switch (p->bal) {
					case 1 : p->bal = 0;
					*alterou = false;
					break;
					case 0 : p->bal = -1;
					break;
					case -1: rotacaoL2(pp);
					*alterou = false;
					break;
				}
		} else {
			inserirAVL2(&(p->dir), ch, alterou);
			if(*alterou)
				switch (p->bal) {
					case -1: p->bal = 0;
					*alterou = false;
					break;
					case 0 : p->bal = 1;
					break;
					case 1 : rotacaoR2(pp);
					*alterou = false;
					break;
				}
		}
	}
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


void travessiaAux(PONT p, int *niv, TIPOCHAVE ch, bool *achou) {
	if(p) {
		(*niv)++;// *niv = *niv + 1;
		if(p->chave == ch) *achou = true;
		else {
			travessiaAux(p->esq, niv, ch, achou);
			if(!(*achou)) travessiaAux(p->dir, niv, ch, achou);
			if(!(*achou)) *niv = *niv - 1;
		}
	}
}

/* Retorna true e o nivel de uma chave (caso seja encontrada) e false caso 
       contrario.                                                                */
bool travessia(PONT p, int *niv, TIPOCHAVE ch) {
	*niv = 0;
	PONT temp = buscaBinaria(ch,p);
	if (temp){
		bool achou = false;
		travessiaAux(p, niv, ch, &achou);
		return true;
	}
	else return false;
}

int main(void){
	// Atividade 23/05/2019 : Criar Menu de Chamada 
	printf("ATIVIDADE: Criar Menu para a chamada das funcoes de ARVORE...");
}
