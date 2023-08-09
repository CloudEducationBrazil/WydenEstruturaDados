#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct no tipoNo;

struct no{
	int num;
	struct no *prox;
};


int imprimirLista(tipoNo *Lista){
	int n=1;
	tipoNo *aux = Lista;
	system("cls");
	printf("Os elementos da lista sao: \n");
	while(aux!=NULL){
		printf("Elemento %d: %d\n", n, aux->num);
		aux=aux->prox;
		n++;
	}
	return n;
}


tipoNo *criarBloco(){
	//Cria um bloco na memoria, esse bloco eh uma estrutura e contem dentro dele um numero do tipo inteiro e um ponteiro que aponta para o bloco seguinte ou para NULL
	tipoNo *criarBloco = (tipoNo*)malloc(sizeof(tipoNo));;
	return criarBloco;
}

tipoNo *inserirNovoBloco(tipoNo *Lista){
	int n=1, opt, m=0, i;
	
	tipoNo *aux = Lista;
	
	tipoNo *novoBloco = criarBloco();
	
	printf("Informe o elemento que deseja inserir na lista:\n");
	scanf("%d", &(novoBloco->num));
	
	if(Lista==NULL){
		printf("Lista vazia, elemento inserido pela primeira vez\n");
		Lista=novoBloco;
		novoBloco->prox=NULL;
		system("pause");
	}
	
	else{
		printf("Escolha: \n");
		printf("1 - Inserir elemento no inicio\n");
		printf("2 - Inserir elemento no fim\n");
		printf("3 - Inserir elemento em outro lugar\n");
		scanf("%d", &opt);
			
		switch(opt){
			case 1:
				novoBloco->prox=Lista;
				Lista=novoBloco;
				break;
			
			case 2:
				while(aux->prox!=NULL){
					aux=aux->prox;
				}
				if(aux->prox==NULL){
					aux->prox=novoBloco;
					novoBloco->prox=NULL;
				}
				break;
			
			case 3:
				printf("Escolha em qual indice deseja por o novo elemento:\n");
				while(aux!=NULL){
					printf("indice %d: Elemento %d\n", n, aux->num);
					aux=aux->prox;
					n++;
				}
				scanf("\n%d", &m);
				tipoNo *aux = Lista;
				tipoNo *aux1 = Lista;
				for(i=1; i<=m-1; i++){
					aux=aux->prox;
				}
				for(i=1; i<=m-2; i++){
					aux1=aux1->prox;
				}
				novoBloco->prox = aux;
				aux1->prox= novoBloco;
		}
	}
	system("cls");
	return Lista;
}

tipoNo *excluirBloco(tipoNo *Lista){
	tipoNo *aux = Lista;
	tipoNo *aux1 = Lista;
	tipoNo *aux2 = Lista;
	int i, l, cont=1;
	
	printf("Informe qual indice voce deseja apagar:\n");
	while(aux!=NULL){
		printf("Indice %d Elemento %d \n", cont, aux->num);
		cont++;
		aux=aux->prox;
	}
	scanf("%d", &l);
	if(l==1){
		
	}
	else if(l==cont){
		
	}
	else{
	cont=l;
	for(i=1; i<cont-1; i++){
		printf("Saca soh o aux1 %d", aux1->num);
		system("pause");
		aux1=aux1->prox;
	}
	for(i=1; i<cont+1; i++){
		printf("Saca soh o aux2 %d", aux2->num);
		system("pause");
		aux2=aux2->prox;
	}
	
	aux1->prox=aux2;
	//printf("saca soh aux1 e aux2 %d %d", aux1->num, aux2->num);
	//system("pause");
	}
	

	return Lista;
}



int main(){
	int x=1, y=0;
	
	tipoNo *Lista=NULL;
	
	while(x==1){
		printf("Menu:\n");
		printf("1 - Inserir um elemento na lista\n");
		printf("2 - Excluir um elemento da lista\n");
		printf("3 - Imprimir Lista\n");
		scanf("%d", &y);
		switch(y){
			case 1:
				Lista = inserirNovoBloco(Lista);
				break;
			case 2:
				Lista = excluirBloco(Lista);
				break;
			case 3:
				imprimirLista(Lista);
				break;
		}	
		printf("\n\nDigite:\n\n\t0 Para Sair\n\n\t1 Para continuar\n");
		scanf("%d", &x);
		system("cls");
	};
	
	return 0;
}
