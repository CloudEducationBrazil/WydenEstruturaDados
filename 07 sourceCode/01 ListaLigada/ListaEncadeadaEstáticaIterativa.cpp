/******************************************************************************
//     usaListaLigadaInterativo.c
// Este programa interage com o usuario para o gerenciamento de uma lista.
******************************************************************************/
#include "listaLigadaEstaticaBiblioteca.c"
#include <stdio.h>
#include <stdlib.h>

void inserir(LISTA *l){
  TIPOCHAVE ch;
  
  printf("Digite Elemento ? ");
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElemListaOrd(l,reg)) printf("Elemento %i inserido corretamente.\n \n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n \n",ch);
  
  getchar();
}

void excluir(LISTA *l){
  TIPOCHAVE ch;
  
  printf("Digite Elemento ? ");
  scanf("%i",&ch);
  if (excluirElemLista(l,ch)) printf("Elemento %i excluido corretamente.\n \n",ch);
  else printf("Nao foi possivel excluir elemento %i.\n \n",ch);
  
  getchar();
}

void exibir(LISTA *l){
  exibirLista(l);
}

void meuLog(LISTA *l){
  printf("Numero de elementos na lista: %i.\n",tamanho(l));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(l));
  printf("\n\n");
  getchar();
}

void help(){
  system("CLS");
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1\n");
  printf("   e <chave1>: excluir elemento com chave=chave1\n");
  printf("   p : imprimir lista\n");
  printf("   d : destruir (zerar) lista\n");
  printf("   l : exibir log de utilizacao da lista\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   q : sair do programa\n");

  printf("\n \n");
}

void destruir(LISTA *l){
     reinicializarLista(l);
     printf("Lista zerada.\n");
}

int main(){
  LISTA lista;
  inicializarLista(&lista);
  help();
  char comando = ' ';
  printf("Digite Opcao ? ");
  scanf("%c",&comando);
  while (comando != 'q'){
    help();
    switch (comando) {
      case 'i' : inserir(&lista); break;
      case 'e' : excluir(&lista); break;
      case 'p' : exibir(&lista); break;
      case 'd' : destruir(&lista); break;
      case 'l' : meuLog(&lista); break;
      case 'h' : help(); break;
      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    
    printf("Digite Opcao ? "); scanf("%c",&comando);
  }

  return 0;
}
