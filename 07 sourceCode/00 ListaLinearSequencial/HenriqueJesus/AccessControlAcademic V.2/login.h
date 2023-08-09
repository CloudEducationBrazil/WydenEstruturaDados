#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include"accessRegister.h"

#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
	int dia;
	int mes;
	int ano;	
}dataRef;

char* dataReferenc(int *dia, int* mes, int *ano) {
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    char novoId[11];
  	
	dataRef dataref;
	
	dataref.dia=tm.tm_mday;
	dataref.mes=tm.tm_mon+1;
	dataref.ano=tm.tm_year+1900;
	
	char diaAux = dataref.dia+'0';
	char mesAux = dataref.mes+'0';
	char anoAux = dataref.ano+'0';
	
	strcat (novoId, &diaAux);
	strcat (novoId, &mesAux);
	strcat (novoId, &anoAux);
	
	printf("%s", novoId);
	system("pause");
	
	return (novoId);
}

typedef struct {
	TIPOCHAVE chave;
	char dataAcesso[11]; 	// Data de Acesso
	char user[200];			// User
	char pass[17];
	char type[9];
	
} userHeaderf;

typedef struct {
	userHeaderf A[MAX];
	int nroElem;
}LISTA;

int chamaCabecalho(){
	printf("*************************************************\n");
	printf("*\t\t WYDEM | AREA 1 \t\t*\n");
	printf("*\tControle de Acesso Academico\t\t*\n");
	printf("*************************************************\n");
}

void inicializarListaUser(LISTA *lista){
	lista->nroElem=0;
}

int buscaAdmin(LISTA *lista){
	int i=0;
	while (i<lista->nroElem){
		system("pause");
		if(strcmp(lista->A[i].user, "admin") == 0) {
			printf("%i", strcmp(lista->A[i].user, "admin"));	
			return i;
		}
		else i++;
	}
	return -1;
}

bool inserirUserListaOrd(LISTA *lista, userHeaderf userheaderf){
	if(lista->nroElem >= MAX) return false;
	int pos = lista->nroElem;
	while(pos>0&&lista->A[pos-1].chave>userheaderf.chave){
		lista->A[pos] = lista->A[pos-1];
		pos--;
	}
	lista->A[pos]=userheaderf;
	lista->nroElem++;
	return true;
}

int accessAccount(LISTA *lista, char usr[200]){
	int i=0;
	//strncpy(lista->A[lista->nroElem].user,usr,200);
	strncpy(lista->A[lista->nroElem].user,usr,200);
	//printf("\n%s\n", lista->A[lista->nroElem].user);
	while(strcmp(lista->A[i].user,usr)!=0){
	//	printf("nroElem: %i\n", lista->nroElem);
	//	printf("i: %i\n", i);	
		i++	;
	} 
	if(i==lista->nroElem)return-1;
	else return i;
}

int validPass(LISTA *lista, char senha[17]){
	int i=0;
	strncpy(lista->A[lista->nroElem].pass,senha,17);
	while(strcmp(lista->A[i].pass,senha)!=0) i++;
	if(i==lista->nroElem)return-1;
	else {
		
		return i;	
	}
}


void exibirLista(LISTA *lista){
	system("clear||cls");
	chamaCabecalho();
	if (lista->nroElem==0){
		printf("* Lista vazia!\n");
		system("pause");
	}else{
		int i;
		printf("* DATA | USER | PASS | TIPO\n");
		for (i=0;i<lista->nroElem;i++) {
			printf("*%s %s %s\n", lista->A[i].user, lista->A[i].pass, lista->A[i].type);
		//	printf("%s ", lista->A[i].user);	
		//	printf("%s \n", lista->A[i].pass);
		}
		
	}
}

int readArqUser(LISTA *lista){
	FILE *arquivo = fopen("ArqListaUser.txt", "r");
	int i=0, j=0;
	if(arquivo != NULL) {
		while(!feof(arquivo)){
			fscanf(arquivo,"%i;%[^;]s ", &lista->A[i].chave,&lista->A[i].user);
			fscanf(arquivo,";%[^;]s ;%s",&lista->A[i].pass,&lista->A[i].type);
			i++	;			
		}
		lista->nroElem=i-1;
		fclose(arquivo);		
	}  
	else {
		chamaCabecalho();
		lista->nroElem=0;
		printf("* Nao foi possivel abrir o arquivo.\n");
		system("pause");
		return 0;
	}   
}

void gravarArquivo(LISTA *lista){
	FILE *arquivo;
	arquivo = fopen ("ArqListaUser.txt","wt");
	int i=0;
	for(i=0;i<lista->nroElem;i++){
		printf("%i;%s;%s;%s\n", lista->A[i].chave, lista->A[i].user, lista->A[i].pass, lista->A[i].type);
		system("pause");
		fprintf(arquivo, "%i;%s;%s;%s\n", lista->A[i].chave, lista->A[i].user, lista->A[i].pass, lista->A[i].type);
	}
	fclose(arquivo);
}

int login(){
	LISTA lista;
	userHeaderf userheaderf;
	LISTAACCESS listaaccess;
	LISTAALUNO listaaluno;
	
	char usr[200], senha[17], repetSenha[17], deposito[22], depost[205], type[9];
	int doWhile;
	
//	chamaCabecalho();

	readArqUser(&lista);
//	exibirLista(&lista);
	if(buscaAdmin(&lista)==-1) {
		inicializarListaAccess(&listaaccess);
		inicializarListaAluno(&listaaluno);
//		system("pause");
		do{
			system("clear||cls");
			chamaCabecalho();
			
			printf("* CRIAR USER 'ADMIN':\n");
			printf("* A senha deve contar no maximo 16 caracteres!\n* \n");
			printf("* Senha: ");
			fgets(deposito, sizeof(deposito), stdin);
			sscanf(deposito, "%s", &senha);
			
			printf("* Repetir senha: ");
			fgets(deposito, sizeof(deposito), stdin);
			sscanf(deposito, "%s", &repetSenha);
			
			if(strcmp(senha,repetSenha)==0){
				
				char userA[] = "admin";
				char type[] = "admin";
				dataRef dataref;
				
				strcpy (userheaderf.user,userA);
				strcpy (userheaderf.pass,senha);
				strcpy (userheaderf.type,type);
				
				strcpy (userheaderf.dataAcesso,dataReferenc(&dataref.dia,&dataref.mes,&dataref.ano));
				
				printf("%s", userheaderf.dataAcesso);
				system("pause");
				
				printf("* Usuario 'admin' criado!\n\n");
				inserirUserListaOrd(&lista, userheaderf);
				doWhile = 0 ;
				system("pause");
			}else{
				printf("* \n* As senhas nao conferem e/ou excedem o limite permitido!\n\n");
				system("pause");
				doWhile = 1	;
			} 
		} while (doWhile==1);

		
	}//criarAdmin(&lista, registro);
	do {
		system("clear||cls");
		chamaCabecalho();	
		
		printf("* USUARIO: ");
		fgets(depost, sizeof(depost), stdin);
		sscanf(depost, "%s", &usr);	
		int result=accessAccount(&lista, usr);
		//printf("result: %i\n",result);
		if(result==-1) {
			printf("* Usuario inexisnte!\n");	
			system("pause");
		}
	
		
	}while(accessAccount(&lista, usr)==-1);
	do {
		system("clear||cls");
		chamaCabecalho();
		printf("* USUARIO: %s",usr);
		printf("\n* SENHA: ");	
		fgets(deposito, sizeof(deposito), stdin);
		sscanf(deposito,"%s",&senha);
		int result=validPass(&lista, senha);
		if(result==-1) {
			printf("* Senha incorreta!\n");	
			system("pause");
		}
	
		
	} while(validPass(&lista, senha)==-1);
		
		menuGerencial();
	
		exibirLista(&lista);
		gravarArquivo(&lista);
		
		
}
