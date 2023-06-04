/* programa usamem.c */
#include <stdio.h>
#include <stdlib.h>
#define N 240000
#define BSIZE 4096
#define SMALL 4
char *pp;
main()
{
    int i, j, k;
    int c = getpid();
    printf("pid : %i", c);
    printf("i: %0x", &i);
    printf("j: %0x", &j);
    pp = malloc(N * BSIZE);
    if (pp == NULL)
    {
        printf("Error al reservar memoria.\n");
        exit(1);
    }
    /* RECORREMOS y modificamos todo el segmento solicitado */
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < BSIZE; j++)
        {
            *(pp + i * BSIZE + j) = 2; // pp[i][j] = 2;
        }
    }
    /* RECORREMOS y VERIFICAMOS QUE HEMOS MODIFICADO todo el segmento solicitado */
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < BSIZE; j++)
        {
            if (*(pp + i * BSIZE + j) != 2)
            { // if (pp[i][j] != 2)
                printf("ERROR! \n");
                exit(1);
            }
        }
    }
    printf("OK \n");
    return 0;
}
