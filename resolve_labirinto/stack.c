#include "stack.h"

Stack *createStack()
{
    return NULL;
}

/*Retorna ponto da cabeça da lista encadeada*/
Point get(Stack *d)
{
    return d->p;
}

/*Inserir elemento na cabeça da lista encadeada*/
Stack *push(Stack *d, Point p)
{

    Stack *new_head = (Stack *)malloc(sizeof(Stack));

    new_head->p = p;

    //Define para onde aponta o ponteiro pois se for o primeiro ele nao aponta para nada
    if (d == NULL)
    {
        new_head->next = NULL;
    }
    else
    {
        new_head->next = d;
    }

    return new_head;
}

/*Remove a cabeça da lista encadeada!*/
Stack *pop(Stack *d)
{

    if (d == NULL)
    {
        return d;
    }

    Stack *new_head = d->next;
    free(d);

    return new_head;
}

/*Retorna um valor quando a stack só tem 1 posição*/
int size_one(Stack *q)
{

    if (q->next == NULL)
    {
        return 1;
    }
    return 0;
}