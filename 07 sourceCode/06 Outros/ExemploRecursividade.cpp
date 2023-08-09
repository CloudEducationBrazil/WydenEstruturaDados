#include <stdio.h>
int multiplica(int a, int b){
  int resp = 0;
  if ( b == 0 ) return resp;
  resp = a + multiplica(a, b-1);
}

int main(void){
  int resposta, a = 7, b =5;
  resposta = multiplica(7,5);
  printf("Resultado %d x %d = %d ", resposta);
}
/*  PILHA
    https://www.youtube.com/watch?v=ny0LDwUXbIg
    https://www.youtube.com/watch?v=45E0mCv1uRk
    https://stock.adobe.com/mx/search?k=recursivo&load_type=tagged%20keyword&prev_url=detail
    https://giphy.com/explore/fibonacci    

    retorno função multiplica(7,0) = 0; resp = 0;
    retorno função multiplica(7,1) => 7 + multiplica(7,0) => 7 +  0 = 7;  resp = 6;
    retorno função multiplica(7,2) => 7 + multiplica(7,1) => 7 +  7 = 14; resp = 14;
    retorno função multiplica(7,3) => 7 + multiplica(7,2 )=> 7 + 14 = 21; resp = 21;
    retorno função multiplica(7,4) => 7 + multiplica(7,3 )=> 7 + 21 = 28; resp = 28;
    retorno função multiplica(7,5) => 7 + multiplica(7,4 )=> 7 + 28 = 35; resp = 35;
*/
