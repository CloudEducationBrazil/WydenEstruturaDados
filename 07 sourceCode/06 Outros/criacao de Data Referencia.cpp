#include <stdio.h>

typedef int TIPOCHAVE;

typedef struct {
	int dia;
	int mes;
	int ano;
} dataRef;

typedef struct {
	dataRef dataAcesso; // Data de Acesso
	char nomePorteiro[200]; // Nome Porteiro
} dadosEntrada;

typedef struct {
	TIPOCHAVE matricula;            // Matr�cula do Aluno
     // Descri��o da Ocorr�ncia (Esqueceu/Perdeu/NaoPossui/Outros cart�o)
	char TipoOcorrencia[100]; 
} Registro;

int main(void){
  dataRef data;
  dadosEntrada cabecalho;
  
  printf("Digite uma Data: ");	
  scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
  
  printf("Digite o Nome do Porteiro: ");	
  scanf("%s", cabecalho.nomePorteiro);
  
  printf("\nData %.2d/%.2d/%.2d", data.dia, data.mes, data.ano);
  printf("\nCabe�alho %s", cabecalho.nomePorteiro);
  
  return 0;
}
