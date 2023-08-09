#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXACCESS 50
#define MAXALUNO 50

typedef int TIPOdeCHAVE;

typedef struct {				//Estrutura de acesso do usuario
	TIPOdeCHAVE chaveAccess;
	char userAccess[200];			// User
	char descriptionAccess[10]; //
//	dataRef dataAcesso; 	// Data de Acesso
}userAccessHeader;

typedef struct {				//Lista de acesso do usuario
	userAccessHeader B[MAXACCESS];
	int nroElemAccess;
}LISTAACCESS;

typedef struct {				//Estrutura de cadastro de alunos
	TIPOdeCHAVE matricula;
	int RG;
	char aluno[200];			// User
	//	dataRef dataAcesso; 	// Data de Acesso
} userCreateAluno;

typedef struct {				//Lista de acesso do aluno
	userCreateAluno C[MAXALUNO];
	int nroElemAluno;
}LISTAALUNO;

int chamaCabecalho2(){
	printf("*************************************************\n");
	printf("*\t\t WYDEM | AREA 1 \t\t*\n");
	printf("*\tControle de Acesso Academico\t\t*\n");
	printf("*************************************************\n");
}

void inicializarListaAccess(LISTAACCESS *listaaccess){
	listaaccess->nroElemAccess=0;
}

void inicializarListaAluno(LISTAALUNO *listaaluno){
	listaaluno->nroElemAluno=0;
}

bool inserirAccessListaOrd(LISTAACCESS *listaaccess, userAccessHeader useraccess){
	if(listaaccess->nroElemAccess >= MAXACCESS) return false;
	int posaccess = listaaccess->nroElemAccess;
	while(posaccess>0&&listaaccess->B[posaccess-1].chaveAccess>useraccess.chaveAccess){
		listaaccess->B[posaccess] = listaaccess->B[posaccess-1];
		posaccess--;
	}
	listaaccess->B[posaccess]=useraccess;
	listaaccess->nroElemAccess++;
	return true;
}

int searchMatricula(LISTAALUNO *listaaluno, int matricula){
	int i=0;
	//if(listaaluno->nroElemAluno==0)
	//	return -1;
	while (i<listaaluno->nroElemAluno){
		if(listaaluno->C[i].matricula == matricula) return i;
		else i++;
	}
	return -1;
}

int searchRG(LISTAALUNO *listaaluno, int rg){
	int i=0;
	//if(listaaluno->nroElemAluno==0)
	//	return -1;
	while (i<listaaluno->nroElemAluno){
		if(listaaluno->C[i].RG == rg) return i;
		else i++; 
	}
	return -1;
}

bool inserirCreateListaOrd(LISTAALUNO *listaaluno, userCreateAluno usercreatealuno){
	if(listaaluno->nroElemAluno >= MAXALUNO) return false;
	int posaluno = listaaluno->nroElemAluno;
	while(posaluno>0&&listaaluno->C[posaluno-1].matricula>usercreatealuno.matricula){
		listaaluno->C[posaluno] = listaaluno->C[posaluno-1];
		posaluno--;
	}
	listaaluno->C[posaluno]=usercreatealuno;
	listaaluno->nroElemAluno++;
	return true;
}

void exibirListaAluno(LISTAALUNO *listaaluno){
	system("clear||cls");
	chamaCabecalho2();
	if (listaaluno->nroElemAluno==0){
		printf("* Lista vazia!\n");
	}else{
		int i;
		printf("* MATRICULA | RG | NOME\n");
		for (i=0;i<listaaluno->nroElemAluno;i++) {
			printf("* %i %i %s\n", listaaluno->C[i].matricula, listaaluno->C[i].RG, listaaluno->C[i].aluno);
		//	printf("%s ", listaaluno->C[i].user);	
		//	printf("%s \n", listaaluno->C[i].pass);
		}
	}
	system("pause");
}

void createAccessAluno(LISTAALUNO *listaaluno){
	
	int matricula,rg;
	char nome[200], suporte[205];
//	LISTAALUNO listaaluno;
	userCreateAluno usercreatealuno;
	
	system("clear||cls");
	chamaCabecalho2();
	printf("* MATRICULA: ");
	scanf("%i", &matricula);
	if (searchMatricula(listaaluno,matricula)==-1){	
		printf("* RG: ");
		scanf("%i", &rg);
		if(searchRG(listaaluno,rg)==-1){
			printf("* NOME: ");
			fflush(stdin);
			fgets(suporte, sizeof(suporte), stdin);
			sscanf(suporte, "%[^\n]", &nome);
			
			usercreatealuno.matricula=matricula;
			usercreatealuno.RG=rg;
			strcpy (usercreatealuno.aluno,nome);
			
			printf("*\n* Cadastro realizado!\n\n");
			inserirCreateListaOrd(listaaluno, usercreatealuno);
			system("pause");
		} else {
			printf("*\n* Matricula e/ou RG ja cadastrado.\n* Por favor, tente novamente!\n");
			system("pause");
		}
	} else {
		printf("*\n* Matricula e/ou RG ja cadastrado.\n* Por favor, tente novamente!\n");
		system("pause");
	}
}


void gravarArquivoAluno(LISTAALUNO *listaaluno){
	FILE *arquivoaluno;
	arquivoaluno = fopen ("ArqListaAluno.txt","wt");
	int i=0;
	for(i=0;i<listaaluno->nroElemAluno;i++){
		fprintf(arquivoaluno, "%i;%i;%s\n", listaaluno->C[i].matricula, listaaluno->C[i].RG, listaaluno->C[i].aluno);
	}
	fclose(arquivoaluno);
}

int readArqAluno(LISTAALUNO *listaaluno){
	FILE *arquivoaluno = fopen("ArqListaAluno.txt", "r");
	int i=0, j=0;
	if(arquivoaluno != NULL) {
		while(!feof(arquivoaluno)){
			//printf("%i",i);
			fscanf(arquivoaluno,"%i;%i; ", &listaaluno->C[i].matricula,&listaaluno->C[i].RG);
			fscanf(arquivoaluno,";%[^\n]s",&listaaluno->C[i].aluno);
			
			printf("%i %i %s", listaaluno->C[i].matricula, listaaluno->C[i].RG, listaaluno->C[i].aluno);
			system("pause");
			i++	;			
		}
		listaaluno->nroElemAluno=i-1;
		fclose(arquivoaluno);
			
	}  else{
		system("clear||cls");
		chamaCabecalho2();
		printf("* Nao foi possivel abrir o arquivo.\n");
		system("pause");
		return 0;
	}   
}

bool excluirElemListaAlunoMat(LISTAALUNO *listaaluno, int matricula) {
	int pos, j;
	pos = searchMatricula(listaaluno, matricula);
	if(pos == -1) return false;
	for(j=pos; j < listaaluno->nroElemAluno-1; j++) listaaluno->C[j] = listaaluno->C[j+1];
	listaaluno->nroElemAluno--;
	printf("* Registro excluido!\n");
return true;
}

bool excluirElemListaAlunoRG(LISTAALUNO *listaaluno, int rg) {
	int pos, j;
	pos = searchRG(listaaluno, rg);
	if(pos == -1) return false;
	for(j=pos; j < listaaluno->nroElemAluno-1; j++) listaaluno->C[j] = listaaluno->C[j+1];
	listaaluno->nroElemAluno--;
	printf("* Registro excluido!\n");
return true;
}

void chooseEditAlunoMat(LISTAALUNO *listaaluno, int matricula){
	int opcChoose=0, opcChooseEdit=0;
	printf("*\n* ESCOLHA UMA DAS OPCOES ABAIXO:\n*\n");
	printf("* 1 - Editar\n");
	printf("* 2 - Excluir\n");
	printf("* 9 - Sair\n");
	printf("* Opcao: ");
	scanf("%i", &opcChoose);
	switch(opcChoose){
		case 1:{	//Chamar funcao editarAluno();
			printf("*\n* ESCOLHA UMA DAS OPCOES ABAIXO:\n*\n");
			printf("* 1 - Alterar matricula\n");
			printf("* 2 - Alterar RG\n");
			printf("* 3 - Alterar nome\n");
			printf("* 9 - Sair\n");
			printf("* Opcoe: ");
			scanf("%i",&opcChooseEdit);
			switch(opcChooseEdit){
				case 1:{	//Alterar matricula
					system("clear||cls");
					chamaCabecalho2();
					printf("*\n* Matricula atual: %i\n",listaaluno->C[searchMatricula(listaaluno, matricula)].matricula);
					printf("* Nova matricula: ");
					scanf("%i",&listaaluno->C[searchMatricula(listaaluno,matricula)].matricula);
					printf("*\n* Cadastro atualizado!\n");
					break;
				}
				case 2:{	//Alterar RG
					system("clear||cls");
					chamaCabecalho2();
					printf("*\n* RG atual: %i\n",listaaluno->C[searchMatricula(listaaluno, matricula)].RG);
					printf("* Novo RG: ");
					scanf("%i",&listaaluno->C[searchMatricula(listaaluno,matricula)].RG);
					printf("*\n* Cadastro atualizado!\n");
					break;
				}
				case 3:{	//Alterar nome
					char suporte2[205], newname[200];
					system("clear||cls");
					chamaCabecalho2();
					printf("*\n* Nome atual: %s\n",listaaluno->C[searchMatricula(listaaluno, matricula)].aluno);
					printf("* Novo nome: ");
					fflush(stdin);
					fgets(suporte2, sizeof(suporte2), stdin);
					sscanf(suporte2, "%[^\n]", &newname);
					strcpy(listaaluno->C[searchMatricula(listaaluno, matricula)].aluno,newname);
					printf("*\n* Cadastro atualizado!\n");
					break;
				}
				case 9:{
					break;
				}
				default:{
					printf("* Opcao invalida!\n");
					system("pause");
					break;
				}
			}
			break;
		}
		case 2:{	//Chamar funcao excluirAluno();
			excluirElemListaAlunoMat(listaaluno, matricula);
			break;
		}
		case 9:{	//Sair
			break;
		}
		default:{
			printf("* Opcao invalida!\n");
			system("pause");
			break;
		}
	}
}

void chooseEditAlunoRG(LISTAALUNO *listaaluno, int rg){
	int opcChoose=0, opcChooseEditRG=0;
	printf("*\n* ESCOLHA UMA DAS OPCOES ABAIXO:\n*\n");
	printf("* 1 - Editar\n");
	printf("* 2 - Excluir\n");
	printf("* 9 - Sair\n");
	printf("* Opcao: ");
	scanf("%i", &opcChoose);
	switch(opcChoose){
		case 1:{	//Chamar funcao editarAluno();
			printf("*\n* ESCOLHA UMA DAS OPCOES ABAIXO:\n*\n");
			printf("* 1 - Alterar matricula\n");
			printf("* 2 - Alterar RG\n");
			printf("* 3 - Alterar nome\n");
			printf("* 9 - Sair\n");
			printf("* Opcoe: ");
			scanf("%i",&opcChooseEditRG);
			switch(opcChooseEditRG){
				case 1:{	//Alterar matricula
					system("clear||cls");
					chamaCabecalho2();
					printf("*\n* Matricula atual: %i\n",listaaluno->C[searchRG(listaaluno, rg)].matricula);
					printf("* Nova matricula: ");
					scanf("%i",&listaaluno->C[searchRG(listaaluno,rg)].matricula);
					printf("*\n* Cadastro atualizado!\n");
					break;
				}
				case 2:{
					system("clear||cls");
					chamaCabecalho2();
					printf("*\n* RG atual: %i\n",listaaluno->C[searchRG(listaaluno, rg)].RG);
					printf("* Novo RG: ");
					scanf("%i",&listaaluno->C[searchRG(listaaluno,rg)].RG);
					printf("*\n* Cadastro atualizado!\n");
					break;
				}
				case 3:{
					char suporte2[205], newname[200];
					system("clear||cls");
					chamaCabecalho2();
					printf("*\n* Nome atual: %s\n",listaaluno->C[searchRG(listaaluno, rg)].aluno);
					printf("* Novo nome: ");
					fflush(stdin);
					fgets(suporte2, sizeof(suporte2), stdin);
					sscanf(suporte2, "%[^\n]", &newname);
					strcpy(listaaluno->C[searchRG(listaaluno, rg)].aluno,newname);
					printf("*\n* Cadastro atualizado!\n");
					break;
				}
				case 9:{
					break;
				}
				default:{
					printf("* Opcao invalida!\n");
					system("pause");
					break;
				}
			}
			break;
		}
		case 2:{	//Chamar funcao excluirAluno();
			excluirElemListaAlunoRG(listaaluno, rg);
			break;
		}
		case 9:{	//Sair
			break;
		}
		default:{
			printf("* Opcao invalida!\n");
			system("pause");
			break;
		}
	}
}

void mgmAlunos(LISTAALUNO *listaaluno){
	int opcaomgmAlunos=0, opcaomgmAlunosAux=0, matricula=0, rg=0;
	//LISTAALUNO listaaluno;
	do{
		system("clear||cls");
		chamaCabecalho2();
		printf("* ESCOLHA UMA DAS OPCOES ABAIXO:\n*\n");
		printf("* 1 - Cadastrar aluno\n");
		printf("* 2 - Buscar aluno\n");
		printf("* 9 - Sair\n");
		printf("* Opcao: ");
		scanf("%i", &opcaomgmAlunos);
		switch(opcaomgmAlunos){
			case 1:{
				createAccessAluno(listaaluno);
				break;
			}
			case 2:{
				do{	
					system("clear||cls");
					chamaCabecalho2();
					printf("* ESCOLHA UMA DAS OPCOES ABAIXO:\n*\n");
					printf("* 1 - Exibir todos\n");
					printf("* 2 - Buscar por matricula\n");
					printf("* 3 - Buscar por RG\n");
					printf("* 9 - Sair\n");
					printf("* Opcoes: ");
					scanf("%i",&opcaomgmAlunosAux); 
					switch(opcaomgmAlunosAux){
						case 1:{	//Chamar metodo exibir lista
						//	LISTAALUNO listaaluno;
							exibirListaAluno(listaaluno);
							break;
						}
						case 2:{	//Chamar metodo buscar por matricula
							system("clear||cls");
							chamaCabecalho2();
							printf("* Matricula: ");
							scanf("%i",&matricula);
							if (searchMatricula(listaaluno, matricula)==-1) printf("* Aluno nao cadastrado!\n");
							else {
								printf("*\n*\tRG\t|\tNOME\n");
								printf("* %i\t  %s \n", listaaluno->C[searchMatricula(listaaluno, matricula)].RG, listaaluno->C[searchMatricula(listaaluno, matricula)].aluno);
								chooseEditAlunoMat(listaaluno, matricula);
							}
							system("pause");
							break;
						}
						case 3:{	//Chamar metodo Buscar por RG
							system("clear||cls");
							chamaCabecalho2();
							printf("* RG: ");
							scanf("%i",&rg);
							if (searchRG(listaaluno, rg)==-1) printf("* Aluno nao cadastrado!\n");
							else {
								printf("*\n* MATRICULA\t|\tNOME\n");
								printf("* %i\t  %s \n", listaaluno->C[searchRG(listaaluno, rg)].matricula, listaaluno->C[searchRG(listaaluno, rg)].aluno);
								chooseEditAlunoRG(listaaluno, rg);
							}
							system("pause");
							break;
						}
						case 9:{
							
							break;
						}
						default:{
							printf("*\n* Opcao invalida!\n");
							system("pause");
							break;
						}
					}
				} while (opcaomgmAlunosAux!=9);
				break;
			}
			
		}
	}while (opcaomgmAlunos!=9);

}

void mgmAccess(){
	LISTAALUNO listaaluno;
	char usrAccess[200], descriptAccess[10], depositoaccess[22], depostaccess[205];
	int opcAccess, opcAccessAux, matricula, resultsearch, opcAuxList;

	system("clear||cls");
	chamaCabecalho2();
	printf("* DEFINA O TIPO DO USUARIO\n*\n");
	printf("* 1 - Aluno\n");
	printf("* 2 - Visitante\n");
	printf("* Opcao: ");
	scanf("%i", &opcAccess);
	switch(opcAccess){
		case 1:{
			do{
				system("clear||cls");
				chamaCabecalho2();
				printf("* Matricula: ");
				scanf("%i", &matricula);
				//fgets(depositoaccess, sizeof(depositoaccess), stdin);
				//sscanf(depositoaccess, "%s", &usrAccess);
				if(searchMatricula(&listaaluno, matricula)==-1)	printf("* Aluno nao cadastrado!\n");
				//printf("%d",searchMatricula(&listaaluno, matricula));
				system("pause");
			}while (resultsearch==-1);
			
			printf("*\n* INFORME O MOTIVO DO ACESSO ALTERNATIVO\n*\n");
			printf("* 1 - Esqueceu o cartao\n");
			printf("* 2 - Perdeu o cartao\n");
			printf("* 3 - Outro\n");
			printf("* 9 - Sair\n");
			printf("* Opcao: ");
			scanf("%i", &opcAccessAux);
			switch(opcAccess){
				case 1:{
					//descriptAccess[10]="esqueceu";
					break;
				}
				case 2:{
					//descriptAccess[10]="perdeu";
					break;
				}
				case 3:{
					//descriptAccess[10]="outro";
					break;
				}
				case 9:{
					break;
				}
				default:{
					system("clear||cls");
					chamaCabecalho2();
					printf("* Opcao invalida!\n");
					system("pause");
					break;
				}
			}
			break;
		}
		case 2:{
			
			break;
		}
		default:{
			
			break;
		}
	}	
	
}

void menuGerencial(){
	LISTAACCESS listaaccess;
	LISTAALUNO listaaluno;
	userAccessHeader useraccess;
	readArqAluno(&listaaluno);	
	
	int opc=0,opcAux=0;
	do{
		
		system("clear||cls");
		chamaCabecalho2();
		printf("* ESCOLHA UMA DAS OPCOES \n*\n");
		printf("* 1 - Gerenciar usuarios\n");
		printf("* 2 - Gerenciar alunos\n");
		printf("* 3 - Gerenciar acessos\n");
		printf("* 9 - Sair\n");
		printf("* Opcao: ");
		scanf("%i",&opc);
		switch(opc){
			case 1:{
				system("clear||cls");
				chamaCabecalho2();
				printf("* ESCOLHA UMA DAS OPCOES \n*\n");
				printf("* ESCOLHA UMA DAS OPCOES ABAIXO:\n*\n");
				printf("* 1 - Cadastrar usuario\n");
				printf("* 2 - Buscar usuario\n");
				printf("* 9 - Sair\n");
				scanf("%i",&opcAux);
				switch(opcAux){
					case 1:{
						//createAccess();
						break;
					}
				}
				break;
			} case 2:{
				mgmAlunos(&listaaluno);
				break;
			} case 3:{
				mgmAccess();
				break;
			}case 9:{
			
				break;
			}default:{
			
				
			}
		}
	}while (opc!=9);
	
	gravarArquivoAluno(&listaaluno);
}
