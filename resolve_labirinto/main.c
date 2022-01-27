#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labirinto.h"
#include "stack.h"

int main()
{

    FILE *labin = fopen("maze.txt", "r");

    int lin, col;
    char lixo;

    fscanf(labin, "%d %d", &lin, &col);
    char **labirinto = aloca_matriz(lin, col);

    //Passa txt para matriz
    int i, j;
    for (i = 0; i < lin; i++)
    {
        fscanf(labin, "%c", &lixo);
        for(j = 0; j < col; j++){
            fscanf(labin, "%c", &labirinto[i][j]);
        }
    }

    //Agora resolve o labirinto
    Stack *caminho;
    caminho = createStack();
    Point inicio;

    inicio.x = 0;
    inicio.y = 1;

    caminho = push(caminho, inicio);

    caminha(labirinto, caminho, lin, col);

    trata_labirinto(labirinto, lin, col);

    //Fazer txt
    FILE *fout = fopen("solved_maze.txt", "w");

    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            fprintf(fout, "%c", labirinto[i][j]);
        }
        fprintf(fout, "\n");
    }

    free_matriz(labirinto, lin, col);

    return 0;
}