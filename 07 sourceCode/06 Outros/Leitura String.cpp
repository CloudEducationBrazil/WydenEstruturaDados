#include <stdio.h>

int main (void) {
   char nome[50];

   // Op��o 1
   printf("Digite um nome 1: ");
   scanf("%s[^\n]", nome);
   printf("O nome digitado foi 1: %s", nome);

   printf("\n");
   printf("\n");

   // Op��o 2 - Somente no SO Windows
   //printf("Digite um nome 2: ");
   //gets(nome);
   //printf("O nome digitado foi 2: %s", nome);

   printf("\n");
   printf("\n");

   // Op��o 3
   printf("Digite um nome 3: ");
   scanf("%s", &nome);
   printf("O nome digitado foi 3: %s", nome);

   printf("\n");
   printf("\n");

   // Declarando uma vari�vel do tipo String (endere�o de mem�ria)
   char sexo_string[10];
   
   // Atribuir de uma vari�vel string
   strcpy(sexo_string, "F"); // Feminino
   
   // Ou
   // Leitura de uma string STRING
   // scanf("%s", sexo_string); // N�o tem & na leitura
   // printf("%s", sexo_string);
   
   // Comparando uma vari�vel String do tipo char nome[50]
   // Na compara��o de uma vari�vel do tipo STRING utiliza-se Aspas duplas "
   if ( strcmp(sexo_string, "M") == 0) // Uma vari�vel do tipo string eh um ponteiro (refer�ncia - endere�o de mem�ria), seu conte�do eh um endere�o de mem�ria
     print("Masculino");
   else
     print("Feminino");
 
   // Declarando uma vari�vel do tipo char
   char sexo_char;  
   scanf("%c", &sexo_char); // Existe & na leitura
   
   // // Na compara��o de uma vari�vel do tipo CHAR utiliza-se aspas simples '
   if ( sexo_char == 'M' ) // Aspas simples 
     print("Masculino");
   else
     print("Feminino");
}
