#define max 50
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Programa para criar agenda de compromisssos
//Metodo de Fila First In First Out
//2ªquestão
typedef int t_chave;
typedef struct {
int dia;
int mes;
int ano;
}t_data;
typedef struct {
t_chave ID;
t_data data;
char desc_comprom[300];
}t_Comp;
typedef struct {
t_Comp v[max];
int inicio;
int nElem;
}t_FILA;
/*INICIALIZAR LISTA 1
RETORNAR A QUANTIDADE DE ELEMENTOS VALIDOS 2
EXIBIR OS ELEMENTOS DA ESTRUTURA 3
INSERIR ELEMENTOS NA ESTRUTURA (NO FIM) 4
 
EXCLUIR ELEMENTOS DA ESTRUTURA (DO INÍCIO) 5
REINICIALIZAR A ESTRUTURA 6 */
//1
void inicializarLista (t_FILA* f){
f->nElem = 0;
f->inicio = 0;
}
//2
int numElementos (t_FILA* f){
return f->nElem;
}
//3
void exibirFila (t_FILA* f){
printf("Seus Compromissos\n:");
int i = f -> inicio;
int temp;
for(temp = 0; temp < f->nElem; temp++){
printf("%d\n", f->v->ID);
printf("%d\n", f->v->data);
printf("%s\n", f->v->desc_comprom
);
i = (i+1) % max;
}
printf("\n\n");
}
//4
void inserirElementos (t_FILA* f, t_Comp* comp){
if (f->nElem >= max){
printf("Não foi possível adicional compromisso\n");
 
}else{
int pos = (f->nElem + f->inicio)% max;
f->v[pos] = *comp;
f->nElem++;
printf("Adicionado com sucesso!!\n");
}
}
//5
void excluirElemento (t_FILA* f, t_Comp* comp ){
if (f->nElem==0){
printf("A lista está vazia");
}else{
*comp = f->v[f->inicio];
f->inicio = (f->inicio+1) % max;
f->nElem--;
printf("Excluido com sucesso!\n");
}
}
//6
void reiniciarFila(t_FILA* f){
inicializarLista(f);
}

int main(){
setlocale(LC_ALL, "Portuguese");
printf("Se apareceu aqui ta de boas lá em cima !\n");
t_Comp Compro;
t_FILA f;
 
int op;
do{
printf("Bem vindo ao menu,meu querido usuário\n");
printf("Digite o número correspondente a operação desejada!\n");
printf("1- Criar Lista de ocorrências\n2- Adicionar compromisso \n3- Mostrar Compromissos\n");
printf("4- Apagar ocorrência \n5- Zerar lista de ocorrências \n6- Quantidades de ocorrência%registradas \n");
printf("7- Sair\n");
printf("Opcao: ");
scanf("%d", &op);
switch(op){
case 1:
inicializarLista(&f);
break;
case 2:
Compro.ID = f.nElem;
printf("Digite uma data!\n");
scanf("%d", &Compro.data);
printf("Digite uma descrição para o compromisso \n");
scanf("%s", &Compro.desc_comprom);
inserirElementos(&f, &Compro);
system("cls");
break;
case 4:
exibirFila(&f);
break;
 
case 5:
printf("Digite o ID do compromisso a ser excluido!\n");
scanf("%d", Compro.ID);
excluirElemento(&f, &Compro);
break;
case 6:
reiniciarFila(&f);
break;
case 7:
numElementos(&f);
case 8:
system("cls");
exit(1);
default:
break;
}
}while(op!=0);
}

