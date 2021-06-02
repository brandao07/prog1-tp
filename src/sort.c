/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: sort.c
 ** Ficheiro C responsável pela ordenação de listas
\***********************************************************************************************/

//! HEADER
#include "headers.h"

void troca_montante(ELEM_CREDITO *a, ELEM_CREDITO *b) //*
{
    float temp = a->info.montante;
    a->info.montante = b->info.montante;
    b->info.montante = temp;
}

void bubbleSort_montante(ELEM_CREDITO *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        int trocada, i;
        ELEM_CREDITO *x = NULL;
        ELEM_CREDITO *y = NULL;
        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (x->info.montante > x->seguinte->info.montante)
                {
                    troca_montante(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void troca_situacao(ELEM_CREDITO *a, ELEM_CREDITO *b) //*
{
    char temp[20];
    strcpy(temp, a->analise.situacao);
    strcpy(a->analise.situacao, b->analise.situacao);
    strcpy(b->analise.situacao, temp);
}

void bubbleSort_situacao(ELEM_CREDITO *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        int trocada, i;
        ELEM_CREDITO *x = NULL;
        ELEM_CREDITO *y = NULL;
        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (strcmp(x->analise.situacao, x->seguinte->analise.situacao) > 0)
                {
                    troca_situacao(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void troca_data_ano(ELEM_CREDITO *a, ELEM_CREDITO *b) //?Verificar se está correto
{
    int temp = a->analise.data.ano;
    a->analise.data.ano = b->analise.data.ano;
    b->analise.data.ano = temp;
}

void bubbleSort_data_ano(ELEM_CREDITO *iniLista) //?Verificar se está correto
{
    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        int trocada, i;
        ELEM_CREDITO *x = NULL;
        ELEM_CREDITO *y = NULL;

        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (x->analise.data.ano > x->seguinte->analise.data.ano)
                {
                    troca_data_ano(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void troca_data_mes(ELEM_CREDITO *a, ELEM_CREDITO *b) //?Verificar se está correto
{
    int temp = a->analise.data.mes;
    a->analise.data.mes = b->analise.data.mes;
    b->analise.data.mes = temp;
}

void bubbleSort_data_mes(ELEM_CREDITO *iniLista) //?Verificar se está correto
{
    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        int trocada, i;
        ELEM_CREDITO *x = NULL;
        ELEM_CREDITO *y = NULL;

        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (x->analise.data.mes > x->seguinte->analise.data.mes)
                {
                    troca_data_mes(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void troca_data_dia(ELEM_CREDITO *a, ELEM_CREDITO *b) //?Verificar se está correto
{
    int temp = a->analise.data.dia;
    a->analise.data.dia = b->analise.data.dia;
    b->analise.data.dia = temp;
}

void bubbleSort_data_dia(ELEM_CREDITO *iniLista) //?Verificar se está correto
{
    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        int trocada, i;
        ELEM_CREDITO *x = NULL;
        ELEM_CREDITO *y = NULL;

        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (x->analise.data.dia > x->seguinte->analise.data.dia)
                {
                    troca_data_mes(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void troca_rank(ELEM_UTILIZADOR *a, ELEM_UTILIZADOR *b) //*
{
    int temp = a->info.rank;
    a->info.rank = b->info.rank;
    b->info.rank = temp;
}

void bubbleSort_rank(ELEM_UTILIZADOR *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        int trocada, i;
        ELEM_UTILIZADOR *x = NULL;
        ELEM_UTILIZADOR *y = NULL;
        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (x->info.rank < x->seguinte->info.rank)
                {
                    troca_rank(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}