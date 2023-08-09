/******************************************************************************
//     usaListaLigadaInterativoCC.c
// Este programa interage com o usuario para o gerenciamento de uma lista.
******************************************************************************/
#include "listaLigadaCircularBiblioteca.c"
#include <stdio.h>
#include <stdlib.h>

void inserir(LISTA *l){
  TIPOCHAVE ch;
  printf("Digite Elemento ? ");
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElemListaOrd(l,reg)) printf("Elemento %i inserido corretamente.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n \n",ch);
  
  getchar();
}

void buscar(LISTA *l){
  TIPOCHAVE ch;
  printf("Digite Elemento ? ");
  scanf("%i",&ch);
  PONT posicao = buscaSentinela(l,ch);
  if (posicao != NULL) printf("Elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar elemento %i.\n \n",ch);
  
  getchar();
}

void exibirPrimeiro(LISTA *l){
  TIPOCHAVE ch;
  PONT posicao = retornarPrimeiro(l,&ch);
  if (posicao != NULL) printf("Primeiro elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (lista vazia).\n \n");
  
  getchar();
}

void exibirUltimo(LISTA *l){
  TIPOCHAVE ch;
  PONT posicao = retornarUltimo(l,&ch);
  if (posicao != NULL) printf("Ultimo elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o ultimo elemento (lista vazia).\n \n");
  
  getchar();
}

void excluir(LISTA *l){
  TIPOCHAVE ch;
  printf("Digite Elemento ? ");
  scanf("%i",&ch);
  if (excluirElemLista(l,ch)) printf("Elemento %i excluido corretamente.\n",ch);
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
  printf("   b <chave1>: exibir posicao do elemento com chave=chave1\n");
  printf("   0 : exibir a chave e o endereco do primeiro elemento\n");
  printf("   u : exibir a chave e o endereco do ultimo elemento\n");
  printf("   q : sair do programa\n");
  
  printf("\n");  
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
      case 'b' : buscar(&lista); break;
      case '0' : exibirPrimeiro(&lista); break;
      case 'u' : exibirUltimo(&lista); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    printf("Digite Opcao ? "); 
    scanf("%c",&comando);
  }

  return 0;
}
