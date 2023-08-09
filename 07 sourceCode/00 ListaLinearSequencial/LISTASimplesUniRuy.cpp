#include <stdio.h>
#include <stdlib.h>

#define tamLista 5
#define false 0
#define true 1
//#include <stdbool.h>

typedef int TipoChave;

typedef struct{ TipoChave chave;
} Registro;

typedef struct { Registro A[tamLista];
                 int nroElemento;
} Lista;

void menu();
void inicializaLista(Lista* l);
void tamanhoLista(Lista* l);
void exibeLista(Lista* l);
bool inserirLista(Lista* l, Registro reg, int pos);
bool inserirListaCompleta(Lista* l);
bool alterarLista(Lista* l, TipoChave chave, int pos);
bool excluirLista(Lista* l, TipoChave chave);
int buscarLista(Lista* l, TipoChave chave);

int main(){
	Registro reg;
	Lista l; 

	inicializaLista(&l);	
	int opc;
	int pos;
	int chave;
	
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

void inicializaLista(Lista* l) {
	l->nroElemento = 0;
}

void tamanhoLista(Lista* l){
	printf("\nQuantidade de Elementos na Lista = %d \n", l->nroElemento);
	printf("\nTotal em Bytes %d \n", sizeof(l));
}

void exibeLista(Lista* l){
    printf("\n\n");
    if ( l->nroElemento == 0 ) printf("Lista Vazia\n");

	for (int i = 0; i<l->nroElemento; i++)
	  printf("Elemento [%d]=%d\n", i, l->A[i].chave);
	  
    if ( l->nroElemento < tamLista)
	  printf("\n Proxima Posicao LIVRE da Lista = %d", l->nroElemento);
	else
	  printf("\n Lista CHEIA");
};

bool inserirLista(Lista* l, Registro reg, int pos){
 	if ( l->nroElemento == tamLista || pos > l->nroElemento || pos < 0 || pos > tamLista ) return false;
 
 	for (int i = l->nroElemento; i > pos; i--)
 	  l->A[i] = l->A[i-1];
 	  
 	l->A[pos] = reg;
 	l->nroElemento++;
 	return true;  
 }

bool inserirListaCompleta(Lista* l) {
	Registro reg;

	if ( l->nroElemento > 0 ) { printf("\nLista ja INSERIDA"); return false; }
	
 	for (int i = 0; i < tamLista; i++){
 		printf("\nDigite Elemento [%d]=? ", i); scanf("%d", &reg); 
 	    l->A[i] = reg;
 	    l->nroElemento++;
	 }
	 
	 printf("\nLista INSERIDA"); 
	 return true;
}

bool alterarLista(Lista* l, TipoChave chave, int pos){
 	if ( pos < 0 || pos > tamLista || pos > l->nroElemento-1 || l->nroElemento == 0 ) return false;

 	l->A[pos].chave = chave;
 	return true;  
 }

bool excluirLista(Lista* l, TipoChave chave){
    int pos = buscarLista(l, chave);
    if ( pos == -1 ) return false;
    
    for ( int i = pos; i < l->nroElemento-1; i++)
	  l->A[i] = l->A[i+1];
 	
	l->nroElemento--;
    return true;
 }
 
 int buscarLista(Lista* l, TipoChave chave){
 	for (int pos=0; pos < l->nroElemento; pos++)
 	  if ( chave == l->A[pos].chave )
	    return pos;
	
	// Se não encontrou
    return -1;
 }
 
 // Outras opções de funcionalidades que podem ser implementadas
 
 // Primeiro ELemento da Lista
 TipoChave primeiroElementoLista(Lista* l){
 	if ( l->nroElemento > 0 ) return l->A[0].chave;
 	else return -1;
 }
 
// Último ELemento da Lista
 TipoChave ultimoElementoLista(Lista* l){
 	if ( l->nroElemento > 0 ) return l->A[l->nroElemento-1].chave;
 	else return -1;
 }
 
// Retorna a chave da posição da LISTA
TipoChave chaveElementoLista(Lista* l, int pos){
 	if ( ( l->nroElemento > 0 ) && ( pos >= 0 && pos < l->nroElemento ) ) return l->A[pos].chave;
 	else return -1;
 }
 
