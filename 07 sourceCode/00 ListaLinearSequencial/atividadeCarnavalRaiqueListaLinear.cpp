#include <stdio.h>
#include <stdlib.h>

/**
	* @author Raique Carvalho Queiroz - Eng Computação - 162030146
	* @description Lista Sequencial
	* @language C
	* @date 2019, February 07
*/

/* 	//NOTA//
	SE O PROJETO FOR RODAR NO ONLINEGBD AS FUNCOES "SYSTEM()" NAO FUNCIONARÃO!
*/

#define MAX_VETOR 5
#define MAX_NOME 30

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE matricula;
    char nomeAluno[MAX_NOME];
} REGISTRO;

typedef struct{
    REGISTRO vetor[MAX_VETOR];
    int nroElem;
} LISTA;

void criarLista(LISTA *lista);
void reiniciarLista(LISTA *lista);

int verificarMatricula(LISTA *lista, REGISTRO registro);

void inserirFinal(LISTA *lista, REGISTRO registro);
void inserirPosicao(LISTA *lista, REGISTRO registro, int posicao);
void inserirInicio(LISTA *lista, REGISTRO registro);

void imprimirQuantidade(LISTA lista);
void imprimirListaInicioFim(LISTA lista);
void imprimirListaFimInicio(LISTA lista);

void buscarPosicao(LISTA *lista, int posicao);
void buscarMatricula(LISTA *lista, TIPOCHAVE matricula);

void editarRegistro(LISTA *lista, int posicao);

void deletarPosicao(LISTA *lista, int posicao);
void deletarMatricula(LISTA *lista, TIPOCHAVE matricula);

void gravarArquivo(LISTA *lista, int opcao);

int main(){
    LISTA lista;
    REGISTRO registro;
    TIPOCHAVE matricula;
    int opc, posicao, opcAux;
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
    	        imprimirQuantidade(lista);
    	        break;
    	    }	
    	    case 2:{
    	       	system("cls");
    	        printf("Selecione uma das opcoes abaixo: \n\n");
    	        printf("1 - Exibir Registros a partir do Inicio\n");
    	        printf("2 - Exibir Registros a partir do Fim\n");
    	        printf("Opcao: ");
    	    	scanf("%d",&opcAux);
    	    	system("cls");
    	    	switch(opcAux){
    	    		case 1:{
    	    			imprimirListaInicioFim(lista);
						break;
					}
					case 2:{
						imprimirListaFimInicio(lista);
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
    	    	printf("Informe o numero de Matricula do Aluno: ");
    	    	scanf("%d",&registro.matricula);
    	    	printf("Informe o Nome do Aluno: ");
    	    	fflush(stdin);
    	    	fgets(registro.nomeAluno,MAX_NOME,stdin);
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
						deletarPosicao(&lista,posicao);
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
				gravarArquivo(&lista,1);
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
    					gravarArquivo(&lista,0);
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

void criarLista(LISTA *lista){
    lista->nroElem = 0;
    system("cls");
    printf("Sucesso!\n");
    system("pause");
}

void reiniciarLista(LISTA *lista){
	int opc;
	system("cls");
	printf("Voce tem certeza que deseja Reiniciar a Estrurua?\n");
	printf("0 - SIM\n");
	printf("1 - NAO\n");
    printf("Opcao: ");
    scanf("%d",&opc);
    system("cls");
    switch(opc){
    	case 0:{
    		lista->nroElem = 0;
    		printf("Sucesso!\n");
			break;
		}case 1:{
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

int verificarMatricula(LISTA *lista, REGISTRO registro){
	int i;
	for(i=0;i<lista->nroElem;i++)
		if(registro.matricula==lista->vetor[i].matricula)
			return 1;
	return 0;
}

void inserirFinal(LISTA *lista, REGISTRO registro){
	int verificador = verificarMatricula(lista,registro);
	system("cls");
	if(verificador==0){
		if(lista->nroElem<MAX_VETOR){
	    	lista->vetor[lista->nroElem] = registro;
    		lista->nroElem = lista->nroElem+1;
    		printf("Sucesso!\n");
		}else{
			printf("Erro!\n");		
			printf("Lista Cheia!\n");
		}
	}else{
		printf("Erro!\n");
		printf("Numero de Matricula ja registrado!\n");
	}	
	system("pause");
}

void inserirPosicao(LISTA *lista, REGISTRO registro, int posicao){
	int i;
	int verificador = verificarMatricula(lista,registro);
	if(verificador==0){
    	if(posicao>=lista->nroElem)
        	inserirFinal(lista,registro);
    	else{
    		system("cls");
    		if(lista->nroElem<MAX_VETOR){
    			printf("Sucesso!\n");
        		for(i=lista->nroElem;i>posicao;i--)
            		lista->vetor[i] = lista->vetor[i-1];
        		lista->vetor[posicao] = registro;
        		lista->nroElem++;
    		}else{
				printf("Erro!\n");		
				printf("Lista Cheia!\n");
			}
			system("pause");
    	}
    }else{
    	system("cls");
		printf("Erro!\n");
		printf("Numero de Matricula ja registrado!\n");
		system("pause");
	}
}

void inserirInicio(LISTA *lista, REGISTRO registro){
    inserirPosicao(lista,registro,0);
}

void imprimirQuantidade(LISTA lista){
	system("cls");
	if(lista.nroElem==0)
		printf("Lista Vazia!\n");
	else
    	printf("Quantidade de Registros: %d\n",lista.nroElem);
    system("pause");
}

void imprimirListaInicioFim(LISTA lista){
	int i;
	if(lista.nroElem==0)
		printf("Lista Vazia!\n");
	else{
	    printf("Registros:\n");
		printf("POSICAO - MATRICULA - NOME\n");
    	for(i=0; i<lista.nroElem;i++)
        	printf("%03d - %010d - %s",i,lista.vetor[i].matricula,lista.vetor[i].nomeAluno);
	}
	printf("\n");
	system("pause");
}

void imprimirListaFimInicio(LISTA lista){
	int i;
	if(lista.nroElem==0)
		printf("Lista Vazia!\n");
	else{
	    printf("Registros:\n");
		printf("POSICAO - MATRICULA - NOME\n");
    	for(i=lista.nroElem-1;i>=0;i--)
        	printf("%03d - %010d - %s",i,lista.vetor[i].matricula,lista.vetor[i].nomeAluno);
	}
	printf("\n");
	system("pause");
}

void buscarPosicao(LISTA *lista, int posicao){
	int opc;
	system("cls");
    if(posicao<lista->nroElem){
		printf("Registo encontrado!\n");
		printf("POSICAO - MATRICULA - NOME\n");
		printf("%03d - %010d - %s\n",posicao,lista->vetor[posicao].matricula,lista->vetor[posicao].nomeAluno);
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
				deletarPosicao(lista,posicao);
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
	int i, verifica=0;
	system("cls");
	for(i=0;i<lista->nroElem;i++){
		if(matricula==lista->vetor[i].matricula){
			buscarPosicao(lista,i);
			verifica=1;
		}
	}
	if(verifica==0){
		printf("Erro!\n");
		printf("Registro nao encontrado!\n");
		system("pause");
	}
}

void editarRegistro(LISTA *lista, int posicao){
	REGISTRO registro;
	system("cls");
	if(posicao<lista->nroElem){
		printf("Registro encontrado!\n");
		printf("POSICAO - MATRICULA - NOME\n");
		printf("%03d - %010d - %s\n",posicao,lista->vetor[posicao].matricula,lista->vetor[posicao].nomeAluno);
		printf("Informe o numero de Matricula do Aluno: ");
		scanf("%d",&registro.matricula);
		printf("Informe o Nome do Aluno: ");
		fflush(stdin);
		fgets(registro.nomeAluno,MAX_NOME,stdin);
		lista->vetor[posicao] = registro;
		system("cls");
		printf("Sucesso!\n");
	}else{
		printf("Erro!\n");
        printf("Registro nao encontrado!\n");
	}
	system("pause");
}

void deletarPosicao(LISTA *lista, int posicao){
	int i = 0;
	system("cls");
	if(posicao<lista->nroElem){
		if(posicao==(lista->nroElem-1))
			lista->nroElem = lista->nroElem-1;
		else{
			for(i=posicao;i<lista->nroElem-1;i++)
				lista->vetor[i] = lista->vetor[i+1];
			lista->nroElem = lista->nroElem-1;
		}
		printf("Sucesso!\n");
	}else{
		printf("Erro!\n");
		printf("Registro nao encontrado!\n");
	}
	system("pause");
}

void deletarMatricula(LISTA *lista, TIPOCHAVE matricula){
	int i, verifica=0;
	system("cls");
	for(i=0;i<lista->nroElem;i++){
		if(matricula==lista->vetor[i].matricula){
			deletarPosicao(lista,i);
			verifica=1;
		}
	}
	if(verifica==0){
		printf("Erro!\n");
		printf("Registro nao encontrado!\n");	
		system("pause");
	}
}

void gravarArquivo(LISTA *lista, int opcao){
	FILE *arquivo;
	int i;
	system("cls");
	if(lista->nroElem==0){
		printf("Lista Vazia!\n");
		printf("Arquivo nao sera criado!\n");
	}else{
		arquivo = fopen ("atividadeCarnaval.txt","w");
		if(arquivo==NULL){
			printf("Erro ao criar arquivo.\n");
			system("pause");
		}else{
			fprintf(arquivo,"%s","POSICAO - MATRICULA - NOME\n");
			for(i=0;i<lista->nroElem;i++){
				fprintf(arquivo,"%03d - %010d - %s",i,lista->vetor[i].matricula,lista->vetor[i].nomeAluno);
			}
			printf("\tArquivo gravado com sucesso!\n");
		}
		fclose(arquivo);
	}
	if(opcao==0){
		printf("Programa encerrado!\n");
		system("pause");
		exit(1);
	}else{
		printf("Voce Voltara ao Menu!\n");
		system("pause");
	}
}
