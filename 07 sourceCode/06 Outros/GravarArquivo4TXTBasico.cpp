// Bibliotecas da linguagem C
#include <stdio.h>
#include <stdlib.h>

// Fun��o Principal de um programa na linguagem C
int main(void){
    // Cria uma vari�vel ponteiro do tipo Arquivo 
  	FILE *Arquivo;

    // Declara��o de Vari�veis
	char nome[100]; // Vari�vel string
	char sexo; // Vari�vel literal tamanho 1 caractere
	int idade; // Vari�vel string

     // Cria o Arquivo LISTA.txt no HD - wt (Arquivo craido para grava��o - Se o arquivo n�o existir ser� criado e se existir ser� sobreposto)
     Arquivo = fopen("LISTA.txt", "wt");
  
     // Cria o Arquivo LISTA.txt
	 if ( Arquivo == NULL ) printf("Erro na cria��o do arquivo");
	
     // Estrutura de Repetia��o Para com contagem inicial e final
	 for (int x=1; x<=3; x++) { 
	   printf("Digite Convidado: "); scanf("%s", nome); // Leitura Vari�vel nome do Tipo String (j� eh um ponteiro - N�o PRECISA do & na leitura da vari�vel)
	   printf("Digite Sexo: ");      scanf(" %c", &sexo); // Leitura Vari�vel sexo do Tipo Literal (1 Caractere) (n�o eh ponteiro, PRECISA do & na leitura)
	   printf("Digite Idade: ");     scanf("%d", &idade); // Leitura Vari�vel idade do Tipo Inteiro (n�o eh ponteiro, PRECISA do & na leitura)
	
	   // Grava��o de Dados no Arquivo LISTA.txt
	   fprintf(Arquivo, "%s\t%c\t%d \n", nome, sexo, idade);
	 
	   // Imprime uma linha em branco
	   printf("\n");
	 }
	
	 // Fecha o Arquivo LISTA.txt
	 fclose(Arquivo);
	
	 printf("Grava��o do arquivo LISTA.txt com sucesso");
}
