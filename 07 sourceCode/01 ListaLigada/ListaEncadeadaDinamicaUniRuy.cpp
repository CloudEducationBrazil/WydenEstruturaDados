#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define false 0
#define true 1

typedef int TipoChave;

typedef struct {
	TipoChave chave;
} Registro;

typedef struct NO {
	Registro dado;
	struct NO* pontAtual;
	struct NO* pontNext;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio; 
} LISTAENCADEADA;

void menu();
PONT inicializaLista();
void tamanhoLista(PONT l);
void exibeLista(PONT l);
bool inserirLista(PONT l, Registro reg, int pos);
bool inserirListaCompleta(PONT l);
bool alterarLista(PONT l, TipoChave chave, int pos);
bool excluirLista(PONT l, TipoChave chave);
int buscarLista(PONT l, TipoChave chave);


int main(void){
    LISTAENCADEADA* listEnc = (LISTAENCADEADA) malloc(sizeof(ELEMENTO));
	
	int opc;
	int pos;
	int chave;
	
	menu();

	do {
		menu();
	    printf("Selecione Opcao? "); scanf("%d", &opc);
	    switch (opc) {
	    	case 0: printf("[Lista Reinicializada]\n"); inicializaLista(&l); break;
	    	case 1: printf("[Tamanho da Lista]\n"); tamanhoLista(&l); break;
	    	case 2: printf("[Exibindo Lista] \n"); exibeLista(&l); break;

	    	case 3: printf("[Modulo Inclusao] Digite Elemento?");scanf("%d", &reg); 
	    	        printf("Digite Posicao?");scanf("%d", &pos); 
			        if ( inserirLista(&l, reg, pos) == true ) printf("Elemento INSERIDO..."); else printf("Posicao Invalida, buraco na Lista. Nenhum elemento inserido..."); break;

	    	case 4: inserirListaCompleta(&l); break;

	    	case 5: printf("[Modulo Alteracao] Digite Elemento para alteracao?");scanf("%d", &chave); 
	    	        printf("Digite Posicao?");scanf("%d", &pos); 
					if ( alterarLista(&l, chave, pos) == true ) printf("Elemento ALTERADO..."); else printf("Posicao INVALDA!!!"); break;

	    	case 6: printf("[Modulo Exclusao] Digite Elemento a ser Excluido?");scanf("%d", &chave); 
				    if ( excluirLista(&l, chave) == true ) printf("Elemento EXCLUIDO..."); else printf("Elemento nao encontrado!!!"); break;
				    
	    	case 7: printf("[Modulo Consulta] Digite Elemento a ser Consultado?");scanf("%d", &chave);
			        if ( buscarLista(&l, chave) >= 0 ) printf("\n Registro Encontrado"); else printf("\n Registro nao Encontrado"); break;
			        
	    	case 8: exit(1); break;
	    	default:
	        printf("Opcao Invalida\n");
			}
			printf("\n\n");
		    system("PAUSE");  
	   } while ( opc != 8 );
	return 0;
}

void menu() {
		system("CLS");
		printf("0 - Inicializar Lista \n");
		printf("1 - Exibir Tamanho da Lista \n");
		printf("2 - Exibir Lista \n");
		printf("3 - Inserir na Lista \n");
		printf("4 - Inserir na Lista Completa \n");
		printf("5 - Alterar na Lista \n");
		printf("6 - Excluir na Lista \n");
		printf("7 - Buscar na Lista \n");
		printf("8 - Sair da Rotina \n");
};

PONT inicializaLista() {
	return null;
}

