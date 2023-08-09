#include <string.h>
#include <stdio.h>

int main()
{

    FILE *file = fopen("/home/unifacsmestrado/Documents/EstudoC/ArqListaEstatica.txt", "r");

    char *linha, *conteudoDoArquivo;

    while ((fscanf(file, "%s", linha) != EOF) ) {
                printf("Linha %s \n", linha);
}
    fclose(file);

    return 0;
}
