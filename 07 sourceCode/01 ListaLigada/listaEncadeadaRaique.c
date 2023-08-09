#include <stdio.h>
#include <stdlib.h>

/**
	* @author Raique Carvalho Queiroz - Eng Computação - 162030146
	* @description Lista Encadeada
	* @language C
	* @date 2019, March 11	
*/

/* 	//NOTA//
	SE O PROJETO FOR RODAR NO ONLINEGBD AS FUNCOES "SYSTEM()" NAO FUNCIONARÃO!
*/

//Estruturas

#define MAX_NOME 30

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE matricula;
    char nomeAluno[MAX_NOME];
} REGISTRO;

typedef struct lista{
    REGISTRO registro;
    struct lista *prox;
} *LISTA;

//Declaração de Funções

void criarLista(LISTA *lista);

int verificarMatricula(LISTA *lista, REGISTRO registro);

void inserirInicio(LISTA *lista, REGISTRO registro);
void inserirFinal(LISTA *lista, REGISTRO registro);
void inserirPosicao(LISTA *lista, REGISTRO registro, int posicao);

int imprimirQuantidade(LISTA *lista);
void imprimirLista(LISTA *lista);

void buscarPosicao(LISTA *lista, int posicao);
void buscarMatricula(LISTA *lista, TIPOCHAVE matricula);

void deletarPosicao(LISTA *lista, int posicao, int verificador);
void deletarMatricula(LISTA *lista, TIPOCHAVE matricula);

void editarRegistro(LISTA *lista, int posicao);

void reiniciarLista(LISTA *lista);

void gravarArquivo(LISTA *lista);

//PROGRAMA PRINCIPAL;

int main(){
    LISTA lista;
    REGISTRO registro;
    TIPOCHAVE matricula;
    int opc, posicao, opcAux, qtd;
    opc=0;

    do{
		system("cls");
    	printf("Seja bem vindo ao Menu!\n");
   		printf("Selecione uma das opcoes abaixo:\n\n");
   		printf("1 - Criar Estrutura\n");
		printf("9 - Sair\n");		
    	printf("Opcao: ");
    	scanf("%d",&opc);
    	switch(opc){
    	    case 1:{
    	    	criarLista(&lista);
				break;
			}
			case 9:{
				exit(1);
				break;
			}
			default:{
    	        system("cls");
    	        printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
    	        system("pause");
    	        break;
    	    }
		}
	}while(opc!=1);
			
	do{
        system("cls");
    	printf("Seja bem vindo ao Menu!\n");
   		printf("Selecione uma das opcoes abaixo:\n\n");
    	printf("1 - Exibir Quantidade de Registros\n");
    	printf("2 - Exibir Registros\n");
    	printf("3 - Buscar\n");
    	printf("4 - Inserir Registro\n");
    	printf("5 - Editar Registro\n");
    	printf("6 - Excluir Registro\n");
    	printf("7 - Gravar Registros em Arquivo\n");
    	printf("8 - Reinicializar a Estrutura\n");
    	printf("9 - Sair\n");
    	printf("Opcao: ");
    	scanf("%d",&opc);
    	switch(opc){
    	    case 1:{
    	        qtd = imprimirQuantidade(&lista);
    	        system("cls");
    	        if(qtd==0)
    	        	printf("Lista vazia!\n");
    	        else
    	        	printf("Quantidade de Registros: %d\n",qtd);
    			system("pause");
    	        break;
    	    }	
    	    case 2:{
    	    	imprimirLista(&lista);
				break;
			}
			case 3:{
				system("cls");
    	       	printf("Selecione uma das opcoes abaixo: \n\n");
    	       	printf("1 - Buscar por numero de Matricula\n");
    	       	printf("2 - Buscar por indice da Posicao\n");
    	       	printf("Opcao: ");
    	    	scanf("%d",&opcAux);
    	    	system("cls");
    	    	switch(opcAux){
    	    		case 1:{
						printf("Informe o numero de Matricula: ");
						scanf("%d",&matricula);
						buscarMatricula(&lista,matricula);
						break;
					}
					case 2:{
						printf("Informe o indice da Posicao: ");
    	    			scanf("%d",&posicao);
    	    			buscarPosicao(&lista,posicao);
						break;
					}
					default:{
						printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
						system("pause");
						break;
					}
				}
				break;
			}
			case 4:{
				system("cls");
    	       	printf("Selecione uma das opcoes abaixo: \n\n");
    	       	printf("1 - Inserir no Inicio\n");
    	       	printf("2 - Inserir no Fim\n");
    	       	printf("3 - Inserir em uma Posicao\n");
    	       	printf("Opcao: ");
    	    	scanf("%d",&opcAux);
    	    	system("cls");
    	    	if(opcAux==1 || opcAux==2 || opcAux==3){
    	    		printf("Informe o numero de Matricula do Aluno: ");
    	    		scanf("%d",&registro.matricula);
    	    		printf("Informe o Nome do Aluno: ");
    	    		fflush(stdin);
    	    		fgets(registro.nomeAluno,MAX_NOME,stdin);
				}
    	    	switch(opcAux){
    	    		case 1:{
    	    			inserirInicio(&lista,registro);
						break;
					}
					case 2:{
						inserirFinal(&lista,registro);
						break;
					}
					case 3:{
						printf("Informe o indice da Posicao: ");
						scanf("%d",&posicao);
						inserirPosicao(&lista,registro,posicao);
						break;
					}
					default:{
						printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
						system("pause");
						break;
					}
				}
				break;
			}
			case 5:{
				system("cls");
				printf("Informe o indice da Posicao do Registro: ");
				scanf("%d",&posicao);
				editarRegistro(&lista,posicao);
				break;
			}
			case 6:{
				system("cls");
				printf("Selecione uma das opcoes abaixo: \n\n");
    	       	printf("1 - Deletar pelo numero de Matricula\n");
    	       	printf("2 - Deletar pelo indice da Posicao\n");
    	       	printf("Opcao: ");
    	    	scanf("%d",&opcAux);
    	    	system("cls");
    	    	switch(opcAux){
    	    		case 1:{
						printf("Informe o numero de Matricula:  ");
						scanf("%d",&matricula);
						deletarMatricula(&lista,matricula);
						break;
					}
    	    		case 2:{
						printf("Informe o indice da Posicao:  ");
						scanf("%d",&posicao);
						deletarPosicao(&lista,posicao,0);
						break;
					}
					default:{
						printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
						system("pause");
						break;
					}
				}
				break;
			}
			case 7:{
				gravarArquivo(&lista);
				break;
			}
			case 8:{
				reiniciarLista(&lista);
				break;
			}
			case 9:{
				system("cls");
				printf("Programa sera fechado!\n");
				printf("Deseja gravar os registros em Arquivo?\n");
				printf("0 - SIM\n");
				printf("1 - NAO\n");
    			printf("Opcao: ");
    			scanf("%d",&opcAux);
    			system("cls");
    			switch(opcAux){
    				case 0:{
    					gravarArquivo(&lista);
    					system("cls");
						printf("Programa encerrado!\n");
						system("pause");
						exit(1);
						break;
					}
					case 1:{
						printf("Programa encerrado!\n");
						system("pause");
						exit(1);
						break;
					}
					default:{
						printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
						system("pause");
						break;
					}
				}
				break;
			}
    	    default:{
				system("cls");
				printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
				system("pause");
				break;
			}
		}
	}while(opc!=9);
    return 0;
}

//Funções

void criarLista(LISTA *lista){
	*lista = NULL;
}

int verificarMatricula(LISTA *lista, REGISTRO registro){
	LISTA auxiliar;
	if(*lista==NULL)
		return 0;
	else{
		auxiliar = *lista;
		while(auxiliar!=NULL && registro.matricula!=auxiliar->registro.matricula)
			auxiliar = auxiliar->prox;
		if(auxiliar==NULL)
			return 0;
		else if(registro.matricula==auxiliar->registro.matricula)
			return 1;
	}
}

void inserirInicio(LISTA *lista, REGISTRO registro){
	LISTA novo, auxiliar;
	auxiliar = *lista;
	int verificador = verificarMatricula(&auxiliar,registro);
	if(verificador==0){
		novo = (LISTA)malloc(sizeof(struct lista));
		novo->prox = *lista;
		*lista = novo;
		novo->registro = registro;
		system("cls");
		printf("Registro inserido com sucesso!\n");
		system("pause");
	}else{
		system("cls");
		printf("Numero de matricula ja inserido na lista!\n");
		system("pause");
	}
}

void inserirFinal(LISTA *lista, REGISTRO registro){
	LISTA auxiliar, novo;
	int verificador;
	auxiliar = *lista;
	verificador = verificarMatricula(&auxiliar,registro);
	if(verificador==0){
		if(*lista==NULL)
			inserirInicio(&auxiliar,registro);
		else{
			while(auxiliar->prox!=NULL)
				auxiliar = auxiliar->prox;
			novo = (LISTA)malloc(sizeof(struct lista));
			novo->prox = NULL;
			auxiliar->prox = novo;
			novo->registro = registro;
			system("cls");
			printf("Registro inserido com sucesso!\n");
			system("pause");
		}
	}else{
		system("cls");
		printf("Numero de matricula ja inserido na lista!\n");
		system("pause");
	}
}

void inserirPosicao(LISTA *lista, REGISTRO registro, int posicao){
	LISTA auxiliar, anterior, novo;
	int contAux, cont, verificador;
	auxiliar = *lista;
	contAux = imprimirQuantidade(lista);
	verificador = verificarMatricula(&auxiliar,registro);
	if(verificador==0){
		if(posicao==0)
			inserirInicio(&(*lista),registro);
		else if(posicao>=contAux)
			inserirFinal(&(*lista),registro);
		else{
			cont = 0;
			while(auxiliar->prox!=NULL && posicao!=cont){
				anterior = auxiliar;
				auxiliar = auxiliar->prox;
				cont++;
			}
			novo = (LISTA)malloc(sizeof(struct lista));
			novo->prox = auxiliar;
			anterior->prox = novo;
			novo->registro = registro;
			system("cls");
			printf("Registro inserido com sucesso!\n");
			system("pause");
		}
	}else{
		system("cls");
		printf("Numero de matricula ja inserido na lista!\n");
		system("pause");
	}
}

int imprimirQuantidade(LISTA *lista){
	LISTA auxiliar;
	int cont=0;
	if(*lista==NULL)
		return 0;
	else{
		auxiliar = *lista;
		while(auxiliar!=NULL){
			auxiliar = auxiliar->prox;
			cont++;
		}
		return cont;
	}
}

void imprimirLista(LISTA *lista){
	LISTA auxiliar;
	int cont;
	system("cls");
	if(*lista==NULL)
		printf("Lista vazia!\n");
	else{
		auxiliar = *lista;
		cont = 0;
		printf("POSICAO - MATRICULA - NOME\n");
		while(auxiliar!=NULL){
			printf("%03d - %010d - %s",cont,auxiliar->registro.matricula,auxiliar->registro.nomeAluno);
			auxiliar = auxiliar->prox;
			cont++;
		}
	}
	system("pause");
}

void buscarPosicao(LISTA *lista, int posicao){
	LISTA auxiliar;
	int cont, contAux, opc;
	contAux = imprimirQuantidade(&(*lista));
	system("cls");
	if(*lista==NULL){
		printf("Lista Vazia!\n");
		system("pause");
	}
	else if(posicao<contAux){
		auxiliar = *lista;
		cont = 0;
		while(auxiliar!=NULL && posicao!=cont){
			auxiliar = auxiliar->prox;
			cont++;
		}
		printf("Registo encontrado!\n");
		printf("POSICAO - MATRICULA - NOME\n");
		printf("%03d - %010d - %s\n",posicao,auxiliar->registro.matricula,auxiliar->registro.nomeAluno);
		printf("Selecione uma das opcoes abaixo:\n\n");
    	printf("1 - Editar Registro\n");
    	printf("2 - Deletar Registro\n");
    	printf("9 - Sair\n");
    	printf("Opcao: ");
    	scanf("%d",&opc);
    	switch(opc){
    		case 1:{
    			editarRegistro(lista,posicao);
				break;
			}
			case 2:{
				deletarPosicao(lista,posicao,0);
				break;
			}
			case 9:{
				system("cls");
				printf("Voce Voltara ao Menu!\n");
				system("pause");
				break;
			}
			default:{
				system("cls");
				printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
				system("pause");
				break;
			}
		}
	}else{
		printf("Registro nao encontrado!\n");
		system("pause");
	}
}

void buscarMatricula(LISTA *lista, TIPOCHAVE matricula){
	LISTA auxiliar;
	int cont;
	system("cls");
	if(*lista==NULL){
		printf("Lista Vazia!\n");
		system("pause");
	}
	else{
		auxiliar = *lista;
		cont = 0;
		while(auxiliar!=NULL && matricula!=auxiliar->registro.matricula){
			auxiliar = auxiliar->prox;
			cont++;
		}
		if(matricula==auxiliar->registro.matricula)
			buscarPosicao(lista,cont);
		else{
			printf("Registro nao encontrado!\n");
			system("pause");
		}
	}
}

void deletarPosicao(LISTA *lista, int posicao, int verificador){
	LISTA auxiliar, anterior;
	int cont, contAux;
	contAux = imprimirQuantidade(&(*lista));
	auxiliar = *lista;
	system("cls");
	if(*lista==NULL)
		printf("Lista Vazia!\n");
	else if(posicao==0){
			*lista = auxiliar->prox;
			free(auxiliar);
			if(verificador==0)
				printf("Registro deletado com sucesso!\n");
	}else if(posicao==contAux-1){
		cont = 0;
		while(auxiliar!=NULL && posicao!=cont){
			anterior = auxiliar;
			auxiliar = auxiliar->prox;
			cont++;
		}
		anterior->prox = NULL;
		free(auxiliar);
		if(verificador==0)
			printf("Registro deletado com sucesso!\n");
	}
	else if(posicao<contAux){
		cont = 0;
		while(auxiliar!=NULL && posicao!=cont){
			anterior = auxiliar;
			auxiliar = auxiliar->prox;
			cont++;
		}
		anterior->prox = auxiliar->prox;
		free(auxiliar);
		if(verificador==0)
			printf("Registro deletado com sucesso!\n");
	}else
		printf("Registro nao encontrado!\n");
	if(verificador==0)
		system("pause");
}

void deletarMatricula(LISTA *lista, TIPOCHAVE matricula){
	LISTA auxiliar;
	int cont;
	system("cls");
	if(*lista==NULL){
		printf("Lista Vazia!\n");
		system("pause");
	}
	else{
		auxiliar = *lista;
		cont = 0;
		while(auxiliar!=NULL && matricula!=auxiliar->registro.matricula){
			auxiliar = auxiliar->prox;
			cont++;
		}
		if(matricula==auxiliar->registro.matricula)
			deletarPosicao(lista,cont,0);
		else{
			printf("Registro nao encontrado!\n");
			system("pause");
		}
	}
}

void editarRegistro(LISTA *lista, int posicao){
	LISTA auxiliar;
	REGISTRO registro;
	int cont, contAux;
	contAux = imprimirQuantidade(&(*lista));
	system("cls");
	if(*lista==NULL)
		printf("Lista Vazia!\n");
	else if(posicao<contAux){
		auxiliar = *lista;
		cont = 0;
		while(auxiliar!=NULL && posicao!=cont){
			auxiliar = auxiliar->prox;
			cont++;
		}
		printf("Registo encontrado!\n");
		printf("POSICAO - MATRICULA - NOME\n");
		printf("%03d - %010d - %s\n",posicao,auxiliar->registro.matricula,auxiliar->registro.nomeAluno);
		printf("Informe o numero de Matricula do Aluno: ");
		scanf("%d",&registro.matricula);
		printf("Informe o Nome do Aluno: ");
		fflush(stdin);
		fgets(registro.nomeAluno,MAX_NOME,stdin);
		auxiliar->registro = registro;
		system("cls");
		printf("Registro editado com sucesso!\n");
	}else{
		printf("Erro!\n");
		printf("Registro nao encontrado!\n");
	}
	system("pause");
}

void reiniciarLista(LISTA *lista){
	int opc, qtd, i;
	system("cls");
	printf("Voce tem certeza que deseja Reinicializar a Estrurua?\n");
	printf("0 - SIM\n");
	printf("1 - NAO\n");
    printf("Opcao: ");
    scanf("%d",&opc);
    system("cls");
    switch(opc){
    	case 0:{
			qtd = imprimirQuantidade(&(*lista));
			for(i=qtd-1;i>=0;i--)
				deletarPosicao(&(*lista),i,1);
			printf("Lista reinicializada com Sucesso!\n");
			break;
		}
		case 1:{
			printf("Voce voltara ao Menu!\n");
			break;
		}
		default:{
			printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
			break;
		}
	}
    system("pause");
}

void gravarArquivo(LISTA *lista){
	FILE *arquivo;
	LISTA auxiliar;
	int i, cont;
	system("cls");
	if(*lista==NULL){
		printf("Lista vazia!\n");
		printf("Arquivo nao sera criado!\n");
	}else{
		arquivo = fopen ("listaEncadeada.txt","w");
		if(arquivo==NULL){
			printf("Erro ao criar arquivo.\n");
			system("pause");
		}else{
			auxiliar = *lista;
			cont = 0;
			fprintf(arquivo,"POSICAO - MATRICULA - NOME\n");
			while(auxiliar!=NULL){
				fprintf(arquivo,"%03d - %010d - %s",cont,auxiliar->registro.matricula,auxiliar->registro.nomeAluno);
				auxiliar = auxiliar->prox;
				cont++;
			}
			printf("\tArquivo gravado com sucesso!\n");
		}
		fclose(arquivo);
	}
	system("pause");
}
