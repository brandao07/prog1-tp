#include "headers.h"

void enqueue_credito(QUEUE_CREDITO **iniLista, QUEUE_CREDITO **fimLista, CREDITO info)
{
    QUEUE_CREDITO *novo = NULL;
    novo = (QUEUE_CREDITO *)calloc(1, sizeof(QUEUE_CREDITO));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (CREDITO)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }
    novo->info = info;
    novo->seguinte = NULL;
    if ((*iniLista == NULL) && (*fimLista == NULL))
    {
        *iniLista = *fimLista = novo;
    }
    else
    {
        (*fimLista)->seguinte = novo;
        *fimLista = novo;

    }
}

void dequeue_credito(QUEUE_CREDITO **iniLista, QUEUE_CREDITO **fimLista)
{
    ELEM_CREDITO *temp = NULL;
    temp = *iniLista;
    if ((*iniLista == NULL) && (*fimLista == NULL))
    {
        printf("Fila vazia!\n");
    }
    else
    {
        *iniLista = (*iniLista)->seguinte;
        free(temp);
    }
}