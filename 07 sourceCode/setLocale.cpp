#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#include <string.h>
int main(void)
{
 // printf("\n****** Verificando a localidade corrente ********\n\n");
 // printf ("Localidade corrente: %s\n", setlocale(LC_ALL,NULL) );
 // printf("Não é possível usar acentuação ou ç corretamente…\n\n");
  
 // printf("\n****** Alterando para a localidade do sistema ********\n\n");
  
  //alterando para o padrão do sistema operacional
//  printf("A localidade corrente agora é %s \n",setlocale(LC_ALL,""));
  //printf("%s \n",setlocale(LC_ALL,""));
  setlocale(LC_ALL,"");
  
  char texto[30];
  
  strcpy(texto, "Hoje tem Almoço segunda");
  
  if (strcmp(texto, "Almoço") == 1 )
    printf("\n Ok \n");
 
  printf("Júlia Cachaça Pão Salário Almoço Já é quarta vou dormir \n");
  printf("Agora não tem mais problema algum!\n");
  printf("Já posso usar acentuação e também o caracter ç…\n\n\n");
  
  system("pause");
  return 0;
}
