#include <stdio.h>
#include <stdlib.h>

int main2() {
    int seq[4] = {1, 2, 3, 4};

    int pilha[4];
    for (int elemento = 0; elemento < 4; elemento++) {
        pilha[elemento] = seq[elemento];
    }
    
    for (int elemento = 0; elemento < 4; elemento++)
       printf("%d ", pilha[elemento]);
       
    printf("\n \n");
    
    int x=3;
    while (x > -1) {
        pilha[x] = 0;
        for (int elemento = 0; elemento < 4; elemento++)
            printf("%d ", pilha[elemento]);
        
        printf("\n \n");
        x--;
    }    
}

int main()
{
    main2();

    return 0;
}
