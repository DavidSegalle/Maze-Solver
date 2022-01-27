#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 25

typedef struct
{
    int x;
    int y;
} Point;

typedef struct stack
{
    Point p;
    struct stack *next;
} Stack;

/*Cria um Stack vazio.*/
Stack *createStack();

/*Adiciona um item na cabeça da lista.*/
Stack *push(Stack *q, Point p);

/*Remove um item da cabeça da lista.*/
Stack *pop(Stack *q);

/*Retorna 1 se a stack tem 1 elementos*/
int size_one(Stack *q);

/*Retorna sem remover o item na cabeça da lista.*/
Point get(Stack *q);

#endif