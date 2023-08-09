#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include<assert.h>
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
    char novoId[12];

	dataRef dataref;

	dataref.dia=tm.tm_mday;
	dataref.mes=tm.tm_mon+1;
	dataref.ano=tm.tm_year+1900;

	char diaAux[04];
	char mesAux[04];
	char anoAux[06];

	 strcpy(novoId, strcat(  strcat( strcat(
                                               strcat( diaAux, "/" ),
	                                    mesAux ),
	                                    "/"),
	                         anoAux) );
	//mesAux = (char)dataref.mes+'0';
	//anoAux = (char)dataref.ano+'0';

	//strcat (novoId, &diaAux);
	//strcat (novoId, &mesAux);
	//strcat (novoId, &anoAux);

	//getchar();
	getchar();

	return (novoId);
}

typedef struct {
	TIPOCHAVE chave;
	dataRef dataAcesso; 	// Data de Acesso
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
		//getchar();
		getchar();
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
		//getchar();
		getchar();
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
   char linha[200];
	FILE *arquivo = (FILE*) malloc(sizeof(FILE)); // Heleno
    arquivo = fopen("ArqListaUser.txt", "r");

	int i=0, j=0;
	if(arquivo != NULL) {
		//fscanf(arquivo,"%i;%[^;]s ", &lista->A[i].chave,&lista->A[i].user);

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
		//getchar();
		getchar();
		return 0;
	}
}

void gravarArquivo(LISTA *lista){
	FILE *arquivo;
	arquivo = fopen ("ArqListaUser.txt","wt");
	int i=0;
	for(i=0;i<lista->nroElem;i++){
		printf("%i;%s;%s;%s\n", lista->A[i].chave, lista->A[i].user, lista->A[i].pass, lista->A[i].type);
		//getchar();
		getchar();
		fprintf(arquivo, "%i;%s;%s;%s\n", lista->A[i].chave, lista->A[i].user, lista->A[i].pass, lista->A[i].type);
	}
	fclose(arquivo);
}

int login(){
	LISTA lista;
	userHeaderf userheaderf;
	LISTAACCESS listaaccess;
	LISTAALUNO listaaluno;
	dataRef data;
	char dataAux[18];

	char usr[200], senha[17], repetSenha[17], deposito[22], depost[205], type[9];
	int doWhile;

//	chamaCabecalho();

	readArqUser(&lista);
//	exibirLista(&lista);

	if(buscaAdmin(&lista)==-1) {
		inicializarListaAccess(&listaaccess);
		inicializarListaAluno(&listaaluno);
//		getchar();

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
				//dataRef dataref;

				strcpy (userheaderf.user,userA);
				strcpy (userheaderf.pass,senha);
				strcpy (userheaderf.type,type);

                printf("Acesso");
                getchar();

				printf("%s", userheaderf.dataAcesso);
                printf("Aquiaaaaaaaaaaaa");
                getchar();

                //dataReferenc(&data.dia,&data.mes,&data.ano);
                //strcat(dataAux,&data.dia);
                //strcat(dataAux,"\\");
                //strcat(dataAux,&data.mes);
                //strcat(dataAux,"\\");
                //strcat(dataAux,&data.ano);

                //printf("Data refsssssssssss \n %s", dataAux);

				//strcpy (userheaderf.dataAcesso, dataReferenc(&data.dia,&data.mes,&data.ano));

                //printf("Aquissss");
                //getchar();

				//printf("%s", userheaderf.dataAcesso);
				//getchar();
				//getchar();

				printf("* Usuario 'admin' criado!\n\n");
				inserirUserListaOrd(&lista, userheaderf);
				doWhile = 0 ;
				//getchar();
				getchar();
			}else{
				printf("* \n* As senhas nao conferem e/ou excedem o limite permitido!\n\n");
				//getchar();
				getchar();
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
			//getchar();
			getchar();
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
			//getchar();
			getchar();
		}


	} while(validPass(&lista, senha)==-1);

		menuGerencial();

		exibirLista(&lista);
		gravarArquivo(&lista);


}
