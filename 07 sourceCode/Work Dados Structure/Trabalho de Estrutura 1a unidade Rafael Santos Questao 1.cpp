#include <stdbool.h>
#define max 50
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// 1ªquestão
typedef int tipoID;
typedef struct {
tipoID ID;
char matricula[20];
char ocorrencia [10];//perda, esquecimento, não possui, outros;
}tiporegistro;
typedef struct{
tiporegistro v[max];
int nElem;
}tipolista;
void startlista(tipolista* lista1);
int tamlista(tipolista* lista1);
void colocar_lista(tipolista* lista1, int pos, tiporegistro reg1);
void mostra_lista (tipolista* lista1);
int busca_lista(tipolista* lista1, tiporegistro chave);
void apagardalista(tipolista* lista1, tiporegistro chave);
void zerarlista(tipolista* lista1);

int main(){
setlocale(LC_ALL, "Portuguese");
 
tipolista lista1;
tiporegistro registro;
tiporegistro aa;
int posicao;
int contt;
int op;
do{
printf("Bem vindo ao menu,meu querido usuário\n");
printf("Digite o número correspondente a operação desejada!\n");
printf("1- Criar Lista de ocorrências\n2- Adicionar ocorrência\n3- Buscar ocorrência\n");
printf("4- Mostrar Lista de ocorrências\n5- Apagar ocorrência\n6- Zerar lista deocorrências\n");
printf("7- Quantidades de ocorrência%registradas\n8- Sair\n");
printf("Opcao: ");
scanf("%d", &op);
switch(op){
case 1:
startlista(&lista1);
break;
case 2:
printf("Digite uma posição!\n");
scanf("%d", &posicao);
printf("Digite um numero de Identificacao\n");
scanf("%d", &registro.ID);
printf("Digite o nome do aluno\n");
scanf("%s", &registro.matricula);
printf("Digite um tipo de ocorrencia\n");
 
scanf("%s", &registro.ocorrencia);
colocar_lista(&lista1, posicao, registro);
system("cls");
break;
case 3:
printf("Digite um ID para busca\n");
scanf("%d", &aa);
busca_lista(&lista1, aa);
break;
case 4:
mostra_lista(&lista1);
break;
case 5:
printf("Digite um ID para apagar\n");
scanf("%d", &aa);
apagardalista(&lista1, aa);
break;
case 6:
zerarlista(&lista1);
break;
case 7:
tamlista(&lista1);
case 8:
system("cls");
exit(1);
 
default:
break;
}
}while(op!=0);
system("cls");
return 0;
}
void startlista(tipolista* lista1){
lista1->nElem = 0;
if (lista1->nElem == 0){
printf("lista Criada\n");
system("pause");
system("cls");
}
}
int tamlista(tipolista* lista1){
return lista1->nElem;
}
void colocar_lista(tipolista* lista1, int pos, tiporegistro reg1){
int x;
if((lista1->nElem == max) || (pos < 0) || (pos > lista1->nElem)){
printf("Não foi possivel adicionar!!\n");
system("pause");
system("cls");
}else{
for(x = lista1->nElem; x < pos; x--){
 
lista1->v[x]=lista1->v[x-1];
lista1->v[x]=reg1;
lista1->nElem++;
printf("adicionado com sucesso!!\n");
system("pause");
system("cls");
}
}
}
void mostra_lista(tipolista *lista){
int i;
printf("Lista: \n");
for(i = 0; i < lista->nElem; i++){
printf("%d", lista->v[i].ID);
printf("\n");
}
}
int busca_lista(tipolista* lista1, tiporegistro chave){
int z;
for (z=0; z < lista1->nElem; z++){
if(lista1->v[z].ID == chave.ID){
printf("Aqui esta: %d\n", lista1->v[z].ID);
printf("Aqui esta: %s\n", lista1->v[z].matricula);
printf("Aqui esta: %s\n", lista1->v[z].ocorrencia);
system("pause");
}
else{
printf("Não foi encontrado\n");
 
system("pause");
system("cls");
}
}
}
void apagardalista(tipolista* lista1, tiporegistro chave){
int d, pos;
pos=busca_lista(lista1, chave);
if(pos == -1){
printf("Não é possível excluir\n");
}
else{
for(d=pos; d<lista1->nElem-1; d++){
lista1->v[d]=lista1->v[d+1];
}
lista1->nElem--;
printf("Excluido com sucesso\n");
}
}
void zerarlista(tipolista* lista1){
lista1->nElem=0;
}
 

