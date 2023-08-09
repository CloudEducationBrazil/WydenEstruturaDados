#include <stdio.h>
#include <conio.h> 

int fibonacci(int num);

main()
{
   int n,i;
   printf("Digite a quantidade de termos da sequência de Fibonacci: ");
   scanf("%d", &n);
   printf("\nA sequência de Fibonacci e: \n");
   for(i=0; i<n; i++)
       printf("%d ", fibonacci(i+1));
   return 0;
} 

int fibonacci(int num)
{ int retorno;
   if (num==1) || (num==2) 
       return 1;
   else {
       retorno = fibonacci(num-1) + fibonacci(num-2);
       return retorno; 
   }
}

