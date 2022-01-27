#ifndef labirinto_h
#define labirinto_h

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

char **aloca_matriz(int lin, int col);

int caminha(char **labirinto, Stack *caminho, int lin, int col);

int tracing_pop(char **labirinto, Stack *caminho);

void trata_labirinto(char **labirinto, int lin, int col);

void free_matriz(char **labirinto, int lin, int col);

#endif