#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int primaryKey;

typedef struct {
	primaryKey chave;
} REGISTRO;

typedef struct no {
	 REGISTRO dado;
	 struct no* next;
} ELEMENTO;

typedef ELEMENTO* pont;

typedef struct {
	pont inicio;
} LISTA;

void criarLista(LISTA* l){
	l->inicio = NULL;
}

void exibirLista(LISTA* l){
	pont elementoLista = l->inicio;

	if ( l->inicio == NULL) printf("\nLista Encadeada Dinâmica Vazia!!!");

	while ( elementoLista != NULL) {
	  printf("\nElemento %i %p ", elementoLista->dado.chave, elementoLista->next);
      elementoLista = elementoLista->next;
	};
}

pont buscarLista(LISTA* l, pont* anterior, primaryKey chave) {
     *anterior = NULL;
     pont atual = l->inicio;

     if ( l->inicio == NULL ) { printf("Lista Vazia!!!"); return NULL;}

     while ( ( atual != NULL ) && ( atual->dado.chave != chave ) ) {
        *anterior = atual;
         atual = atual->next;
     }

     if ( ( atual != NULL ) && ( atual->dado.chave == chave ) ) return atual;
     return NULL;
}

bool inserirLista(LISTA* l){
	   primaryKey chave;
	   printf("\n Digite a Chave ?"); scanf("%d", &chave);

       pont anterior;
	   pont atual = buscarLista(l, &anterior, chave);

	   if ( atual == NULL ){
	      atual = (pont) malloc(sizeof(ELEMENTO));
          atual->dado.chave = chave;

           if ( anterior == NULL ){
             atual->next = l->inicio;
             l->inicio = atual;
            }
            else {
             atual->next = anterior->next;
             anterior->next = atual;

            }

           return true;
	   }
	   else return false;
}

bool excluirLista(LISTA* l){
	   primaryKey chave;
	   printf("\n Digite a Chave ?"); scanf("%d", &chave);

       pont anterior;
	   pont atual = buscarLista(l, &anterior, chave);

	   if ( atual == NULL ) return false;

       if ( anterior == NULL )
            l->inicio = atual->next;
       else
            anterior->next = atual->next;

        free(atual);
        return true;
}


int main(void){
	LISTA l;
	REGISTRO reg;

	criarLista(&l);
	printf("\nLista criada...");
	getchar();

	exibirLista(&l);
	printf("\nLista exibida...");
	getchar();

	if ( inserirLista(&l) == true )
	  printf("\nLista inserida 5...");
    else
	  printf("\n NAO inserida 5...");

	getchar();

	if ( inserirLista(&l) == true )
	  printf("\nLista inserida 17...");
    else
	  printf("\n NAO inserida 5...");

	getchar();

    exibirLista(&l);
	printf("\nLista exibida...");
	getchar();

    excluirLista(&l);
	printf("\nLista exibida...");
	getchar();

    exibirLista(&l);
	printf("\nLista exibida...");
	getchar();

	printf("Fim");
}
