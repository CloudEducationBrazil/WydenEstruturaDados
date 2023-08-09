#include <stdio.h>

typedef struct horario {
   	   int hora;
   	   int minuto;
   	   int segundo;
   } ;


int main(void) {

   horario agora, *depois;
 
   depois = &agora;
   
   (*depois).hora = 20;
   (*depois).minuto = 10;
   (*depois).segundo = 30;
   
   printf("%d:%d:%d", depois->hora, depois->minuto, depois->segundo);
	//return 0;
}

