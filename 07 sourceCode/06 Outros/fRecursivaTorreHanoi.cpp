#include <stdio.h>
   2 #include <stdlib.h>
   3 
   4 void hanoi(int n, char a, char b, char c)
   5 {
   6 /* mova n discos do pino a para o pino b usando
   7    o pino c como intermediario                    */
   8   if (n == 1)
   9     printf("mova disco %d de %c para %c\n", n, a, b);
  10   else
  11   {
  12     hanoi(n - 1, a, c, b);                            // H1
  13     printf("mova disco %d de %c para %c\n", n, a, b);
  14     hanoi(n - 1, c, b, a);                            // H2
  15   }
  16 }
  17 
  18 int main(void)
  19 {
  20   int numDiscos;
  21   scanf("%d", &numDiscos);
  22   hanoi(numDiscos, 'A', 'B', 'C');
  23   return 0;
  24 }
  
  https://sites.google.com/a/liesenberg.biz/cjogos/home/materiais-de-apoio/topicos-relativos-a-c/recursao/torre-de-hanoi