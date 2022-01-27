#include "labirinto.h"

/*Aloca a matriz*/
char **aloca_matriz(int lin, int col)
{

    char **matriz = (char **)malloc(sizeof(char *) * lin);
    for (int i = 0; i < lin; i++)
    {
        matriz[i] = (char *)malloc(sizeof(char) * col);
    }

    return matriz;
}

/*Procura a solução do labirinto e a coloca na stack*/
int caminha(char **labirinto, Stack *caminho, int lin, int col)
{

    Point atual = get(caminho);
    Point seguir;

    labirinto[atual.y][atual.x] = '.';

    //Se chegar ao fim imprime o caminho
    if (atual.y == lin - 2 && atual.x == col - 1)
    {
        return tracing_pop(labirinto, caminho);
    }

    //Tenta ir para a direita
    if (atual.x + 1 < col && labirinto[atual.y][atual.x + 1] == ' ')
    {
        seguir.x = atual.x + 1;
        seguir.y = atual.y;
        caminho = push(caminho, seguir);
        if (caminha(labirinto, caminho, lin, col))
        {
            return 1;
        }
        caminho = pop(caminho);
    }

    //Tenta ir para baixo
    if (atual.y + 1 < lin && labirinto[atual.y + 1][atual.x] == ' ')
    {
        seguir.x = atual.x;
        seguir.y = atual.y + 1;
        caminho = push(caminho, seguir);
        if (caminha(labirinto, caminho, lin, col))
        {
            return 1;
        }
        caminho = pop(caminho);
    }

    //Tenta ir para cima
    if (atual.y - 1 > 0 && labirinto[atual.y - 1][atual.x] == ' ')
    {
        seguir.x = atual.x;
        seguir.y = atual.y - 1;
        caminho = push(caminho, seguir);
        if (caminha(labirinto, caminho, lin, col))
        {
            return 1;
        }
        caminho = pop(caminho);
    }

    //Tenta ir para a esquerda
    if (atual.x - 1 > 0 && labirinto[atual.y][atual.x - 1] == ' ')
    {
        seguir.x = atual.x - 1;
        seguir.y = atual.y;
        caminho = push(caminho, seguir);
        if (caminha(labirinto, caminho, lin, col))
        {
            return 1;
        }
        caminho = pop(caminho);
    }

    return 0;
}

/*Volta marcando o caminho da pilha no labirinto*/
int tracing_pop(char **labirinto, Stack *caminho)
{

    if (size_one(caminho))
    {
        return 1;
    }

    Point solucao = get(caminho);

    labirinto[solucao.y][solucao.x] = '@';

    caminho = pop(caminho);

    tracing_pop(labirinto, caminho);

    return 1;
}

/*Limpa as posições que não são parte do caminho da solução do labirinto*/
void trata_labirinto(char **labirinto, int lin, int col)
{

    int i, j;
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (labirinto[i][j] == '.')
            {
                labirinto[i][j] = ' ';
            }
        }
    }
    labirinto[1][0] = '@';
}

/*Desaloca a matriz*/
void free_matriz(char **labirinto, int lin, int col)
{

    int i;

    for (i = 0; i < lin; i++)
    {
        free(labirinto[i]);
    }
    free(labirinto);
}