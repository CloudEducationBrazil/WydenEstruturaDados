#include <stdio.h>

typedef struct {
	int c1;
	int c2;
} teste, *pont;

int main(){
	teste y;
	y.c1 = 10;
	y.c2 = 12;
	printf("c1: %i, c2: %i\n", y.c1, y.c2);
	return 0;
}
