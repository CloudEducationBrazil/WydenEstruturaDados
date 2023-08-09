#include <stdio.h>
#include <malloc.h>

int main(){
	int x=25;
	int *y = (int*) malloc(sizeof(int));
	y = &x; 
	
    printf("Qtd em bytes %i, Conteúdo Y: %d Endereço Y: %p", sizeof(int), *y, &y);
	return 0;	
}
