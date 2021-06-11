/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: free.c
 ** Ficheiro C responsável pela libertação de memória ao fechar o programa
\********************************************************************************/

#include "headers.h"

void libertaLista_CREDITO(ELEM_CREDITO **iniLista)
{
    ELEM_CREDITO *aux = NULL;
    ELEM_CREDITO *proximo = NULL;
    aux = *iniLista;
    while (aux != NULL)
    {
        proximo = aux->seguinte;
        free(aux);
        aux = proximo;
    }
}

void libertaLista_PRIORIDADE(ELEM_PRIORIDADE **iniLista)
{
    ELEM_PRIORIDADE *aux = NULL;
    ELEM_PRIORIDADE *proximo = NULL;
    aux = *iniLista;
    while (aux != NULL)
    {
        proximo = aux->seguinte;
        free(aux);
        aux = proximo;
    }
}

void libertaLista_UTILIZADOR(ELEM_UTILIZADOR **iniLista)
{
    ELEM_UTILIZADOR *aux = NULL;
    ELEM_UTILIZADOR *proximo = NULL;
    aux = *iniLista;
    while (aux != NULL)
    {
        proximo = aux->seguinte;
        free(aux);
        aux = proximo;
    }
}

void libertaLista_QUEUES(QUEUES **iniLista)
{
    QUEUES *aux = NULL;
    QUEUES *proximo = NULL;
    aux = *iniLista;
    while (aux != NULL)
    {
        proximo = aux->seguinte;
        free(aux);
        aux = proximo;
    }
}