#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necess�rio para usar setlocale
#include <string.h>
int main(void)
{
 // printf("\n****** Verificando a localidade corrente ********\n\n");
 // printf ("Localidade corrente: %s\n", setlocale(LC_ALL,NULL) );
 // printf("N�o � poss�vel usar acentua��o ou � corretamente�\n\n");
  
 // printf("\n****** Alterando para a localidade do sistema ********\n\n");
  
  //alterando para o padr�o do sistema operacional
//  printf("A localidade corrente agora � %s \n",setlocale(LC_ALL,""));
  //printf("%s \n",setlocale(LC_ALL,""));
  setlocale(LC_ALL,"");
  
  char texto[30];
  
  strcpy(texto, "Hoje tem Almo�o segunda");
  
  if (strcmp(texto, "Almo�o") == 1 )
    printf("\n Ok \n");
 
  printf("J�lia Cacha�a P�o Sal�rio Almo�o J� � quarta vou dormir \n");
  printf("Agora n�o tem mais problema algum!\n");
  printf("J� posso usar acentua��o e tamb�m o caracter �\n\n\n");
  
  system("pause");
  return 0;
}
