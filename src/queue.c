/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: queue.c
 ** Ficheiro C responsável por todas as operações relacionadas com a fila de processamento
\***********************************************************************************************/
#include "headers.h"

void enqueue_credito(QUEUE_CREDITO **iniQueue, QUEUE_CREDITO **fimQueue, CREDITO info)
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
    if ((*iniQueue == NULL) && (*fimQueue == NULL))
    {
        *iniQueue = *fimQueue = novo;
    }
    else
    {
        (*fimQueue)->seguinte = novo;
        *fimQueue = novo;
    }
}

void dequeue_credito(QUEUE_CREDITO **iniQueue, QUEUE_CREDITO **fimQueue)
{
    QUEUE_CREDITO *temp = NULL;
    temp = *iniQueue;
    if ((*iniQueue == NULL) && (*fimQueue == NULL))
    {
        printf("Fila vazia!\n");
    }
    else
    {
        *iniQueue = (*iniQueue)->seguinte;
        free(temp);
    }
}

void gravar_queue(QUEUE_CREDITO *iniQueue)
{
    QUEUE_CREDITO *aux = NULL;
    FILE *fp = NULL;

    fp = fopen("files\\queue.dat", "w+b"); // w - acrescenta ao ficheiro users.txt

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }

    for (aux = iniQueue; aux != NULL; aux = aux->seguinte)
    {
        fwrite(&(aux->info), sizeof(CREDITO), 1, fp);
    }

    fclose(fp);
}
