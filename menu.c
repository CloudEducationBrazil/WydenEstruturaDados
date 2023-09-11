#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {   
    int opc = 1;
    while (opc >= 1 && opc <= 2 || opc > 3) {
        system("clear");
        printf("Digite opção entre [1-2]: "); scanf("%d", &opc);

        switch (opc) {
            case 1:  {printf("Opção 1 \n"); break;}
            case 2:  {printf("Opção 2 \n"); break;}
            case 3:  {printf("Fim do Programa \n"); exit; break;}
            default: {printf("inválida \n"); break;}
        }
        sleep(1);
   }    
    printf("Fim");
    return 0;
}