#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
} REGISTRO;

typedef struct no {
	REGISTRO dado;
	struct no* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
	PONT inicio;
} LISTA_LIGADA_D;

int main(void){
	LISTA_LIGADA_D* lista;
    REGISTRO reg;
    TIPOCHAVE ch;

	printf("\n");
	printf("\n****** INICIANDO A LISTA ENCADEADA DINAMICA - [LISTA_LIGADA_D]");
	printf("\n");

    // INICIANDO A LISTA
    lista = (LISTA_LIGADA_D*) malloc(sizeof(LISTA_LIGADA_D));
    lista->inicio=NULL;

	printf("\n Endereco da Lista %p", lista);
	printf("\n Endereco da PROXIMO da Lista %p", lista->inicio);

	printf("\n");

    // Teste de alocação
    if (lista == NULL)
    {
      printf("Nao foi possivel alocar memoria para a lista!\n");
      exit(1);
    }

    // INSERINDO ELEMENTOS NA LISTA
	ch = 7;
	reg.chave = 7;

	printf("\n Opcao 1 de imprimiir a chave = %d", reg.chave);
	printf("\n Opcao 2 de imprimiir a chave = %d", ch);

    printf("\n");
    printf("\n****** INSERINDO ELEMENTO 7 NA LISTA [LISTA_LIGADA_D]");
	printf("\n");

	PONT novo_elemento = (PONT) malloc(sizeof(ELEMENTO));
	novo_elemento->dado.chave = ch;
	novo_elemento->prox = NULL;

    lista->inicio = novo_elemento;

	printf("\n Endereço PROXIMO da Lista %p", lista->inicio);
    printf("\n Elemento = %d -> Endereco do Elemento = %p", novo_elemento->dado.chave, novo_elemento) ;
    printf("\n Elemento = %d -> Endereco do Proximo  = %p", novo_elemento->dado.chave, novo_elemento->prox) ;
    printf("\n Opcao 3 de imprimiir a chave = %d", novo_elemento->dado.chave);

	ch = 9;
	reg.chave = 9;

	printf("\n");
    printf("\n****** IMPRIMINDO O ELEMENTO 9 QUE SERA INSERIDO NA LISTA [LISTA_LIGADA_D]");
	printf("\n");

	printf("\n Opcao 1 de imprimiir a chave = %d", reg.chave);
	printf("\n Opcao 2 de imprimiir a chave = %d", ch);

	printf("\n");
    printf("\n****** INSERINDO ELEMENTO 9 NA LISTA [LISTA_LIGADA_D]");
	printf("\n");

	PONT novo_elemento2 = (PONT) malloc(sizeof(ELEMENTO));
	novo_elemento->prox = novo_elemento2;
	novo_elemento2->dado.chave = 9;
	novo_elemento2->prox = NULL;

    printf("\n****** ELEMENTO 9 ACABOU DE SER INSERIDO NA LISTA [LISTA_LIGADA_D]");

	printf("\n");
    printf("\n****** EXIBINDO O PROX DO ELEMENTO 7 INSERIDO NA LISTA [LISTA_LIGADA_D]");
    printf("\n       OBSERVE QUE ELE APONTA PARA O ENDERECO DO ELEMENTO 9,");
    printf("\n       PROXIMO ELEMENTO INSERIDO NA LISTA");
	printf("\n");

	printf("\n Elemento = %d -> Endereco PROX = %p", novo_elemento->dado.chave, novo_elemento->prox);

	printf("\n");
    printf("\n****** EXIBINDO DADOS ELEMENTO 9 QUE FOI INSERIDO NA LISTA [LISTA_LIGADA_D]");
	printf("\n");

	printf("\n Elemento = %d -> Endereco ELEMENTO = %p", novo_elemento2->dado.chave, novo_elemento2);
	printf("\n Elemento = %d -> Endereco PROXIMO = %p", novo_elemento2->dado.chave, novo_elemento2->prox);
    printf("\n Opcao 3 de imprimiir a chave = %d", novo_elemento2->dado.chave);

    printf("\n");
    printf("\n****** IMPRIMINDO ELEMENTOS DA LISTA [LISTA_LIGADA_D]");
	printf("\n");

	// IMPRIMINDO ELEMENTOS DA LISTA
	PONT auxiliar;
	auxiliar=lista->inicio;

    while (auxiliar != NULL){
    	printf("Elemento = %d \n", auxiliar->dado.chave);
    	auxiliar=auxiliar->prox;
 	}

 	// EXIBINDO O TAMANHO DA LISTA
	PONT auxiliar2;
	auxiliar2=lista->inicio;
    int tamanho = 0;

    while (auxiliar2 != NULL){
        tamanho++;
    	auxiliar2=auxiliar2->prox;
 	}

    printf("\n");
    printf("\n****** EXIBINDO O TAMANHO DA LISTA");
    printf("\n");
   	printf("Tamanho da Lista = %d \n", tamanho);

    printf("\n");
    printf("\n****** BUSCANDO ELEMENTO NA LISTA [LISTA_LIGADA_D] ORDENADA");
    printf("\n");

 	// BUSCANDO ELEMENTO NA LISTA ORDENADA
 	TIPOCHAVE ch2;
 	printf("Digite elemento ? "); scanf("%d", &ch2);
 	int encontrou=0;

	PONT ant, atual;
	atual=lista->inicio;
	ant = NULL;

    while ( (atual != NULL) && (atual->dado.chave < ch2) ) {
        ant = atual->prox;
    	atual= atual->prox;
 	}

 	if ( (atual != NULL) && (atual->dado.chave == ch2) ) encontrou = 1;

    printf("\n");
    printf("\n");

 	if ( encontrou == 1) {
 	  printf("Endereco PROXIMO do Predecessor = %p, => Elemento = %d \n", ant, novo_elemento->dado.chave);
 	  printf("\n");
 	  printf("Elemento Encontrado = %d\n", atual->dado.chave);
 	  printf("Endereco ATUAL do Elemento = %p\n", atual);
 	  printf("Endereco PROXIMO do Elemento = %p\n", atual->prox);
 	}
 	else
 	  printf("Elemento NAO Encontrado !!!");

    printf("\n");

	return 0;
}
