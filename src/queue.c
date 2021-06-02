/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: queue.c
 ** Ficheiro C responsável por todas as operações relacionadas com a fila de processamento
\***********************************************************************************************/
#include "headers.h"

void enqueue_credito(QUEUES **queue, CREDITO info) //*
{
    QUEUE_CREDITO *novo = NULL;
    QUEUES *aux = NULL;
    QUEUE_CREDITO *aux2 = NULL;
    int res = 0;
    novo = (QUEUE_CREDITO *)calloc(1, sizeof(QUEUE_CREDITO));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (CREDITO)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }
    novo->info = info;
    novo->seguinte = NULL;
    novo->anterior = NULL;
    for (aux = (*queue); aux != NULL; aux = aux->seguinte)
    {
        if (strcmp(aux->prioridade.nome, info.prioridade) == 0)
        {
            for (aux2 = aux->iniLista; aux2 != NULL; aux2 = aux2->seguinte)
            {
                res++;
            }
            novo->info.numeroSequencial = res;
            if ((aux->iniLista == NULL) && (aux->fimLista == NULL))
            {
                aux->iniLista = aux->fimLista = novo;
            }
            else
            {
                novo->anterior = aux->fimLista;
                aux->fimLista->seguinte = novo;
                aux->fimLista = novo;
            }
        }
    }
}

void enqueue_prioridade(QUEUES **queue, PRIORIDADE info) //*
{
    QUEUES *novo = NULL;
    QUEUES *aux = NULL;

    novo = (QUEUES *)calloc(1, sizeof(QUEUES));
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }
    novo->prioridade = info;
    novo->seguinte = NULL;
    if (*queue == NULL)
    {
        (*queue) = novo;
    }
    else
    {
        aux = *queue;

        while (aux->seguinte != NULL) // para adicionar no fim
        {
            aux = aux->seguinte;
        }
        aux->seguinte = novo;
    }
}

void dequeue_credito(QUEUES **queue, char prioridade[]) //*
{
    QUEUE_CREDITO *temp = NULL;
    QUEUES *aux = NULL;
    for (aux = queue; aux != NULL; aux = aux->seguinte)
    {
        if (strcmp(prioridade, aux->prioridade.nome) == 0)
        {
            temp = aux->iniLista;
            if ((aux->iniLista == NULL) && (aux->fimLista == NULL))
            {
                printf("Fila vazia!\n");
            }
            else
            {
                aux->iniLista = aux->iniLista->seguinte;
                free(temp);
            }
        }
    }
}

void insere_propcredito(ELEM_PRIORIDADE *iniListaP, ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista, QUEUES **queue, ELEM_UTILIZADOR **iniListaU, UTILIZADOR sessao) //*
{
    char prioridade[20];
    CREDITO info;
    ANALISE analise;
    QUEUES *aux = NULL;
    imprime_prioridades(iniListaP);
    printf("Introduza o tipo de prioridade que pretende analisar: \n");
    fflush(stdin);
    scanf("%s", prioridade);
    /*
    Tem agora de verificar em qual das listas 
    é que se encontra a prioridade strcmp com for
    */
    for (aux = (*queue); aux != NULL; aux = aux->seguinte)
    {
        if (strcmp(prioridade, aux->prioridade.nome) == 0)
        {
            /* passa informacao do primeiro elemento da fila de processamento de uma determinada prioridade para o 
            novo no que sera inserido no fim da lista de propostas de credito*/
            info = aux->iniLista->info;
        }
    }
    dequeue_credito(queue, prioridade);
    analise = analisar_credito(iniListaU, sessao);
    inserir_credito(iniLista, fimLista, &info, &analise);
}

void gravar_queues(QUEUES *queue) //*
{
    QUEUES *aux_out = NULL;       // percorre lista de queues
    QUEUE_CREDITO *aux_in = NULL; // percorre queue
    FILE *fp = NULL;
    fp = fopen("files/queues.dat", "wb");
    FILE *fp1 = NULL;
    fp1 = fopen("files/queuesCredito.dat", "wb");

    if (fp == NULL && fp1 == NULL) // Teste para ver se houve problema ao criar o ficheiro
    {
        printf("ERRO ao criar o ficheiro queues.dat ou queuesCredito.dat!\n");
        return;
    }
    for (aux_out = queue; aux_out != NULL; aux_out = aux_out->seguinte) // percorre a lista simples (QUEUES)
    {
        fwrite(&(aux_out->prioridade), sizeof(PRIORIDADE), 1, fp);                  // Escreve o indicador da lista simples (prioridade)
        for (aux_in = aux_out->iniLista; aux_in != NULL; aux_in = aux_in->seguinte) // percorre a lista duplamente ligada (QUEUE_CREDITO)
        {
            fwrite(&(aux_in->info), sizeof(CREDITO), 1, fp1); // Escreve a informacao de cada elemento da lista simples
        }
    }
    fclose(fp);
    fclose(fp1);
}

void carregar_queues(QUEUES **queue) //*
{
    PRIORIDADE info;
    CREDITO infoCredito;
    QUEUES *aux = NULL;
    int res = 0;
    FILE *fp = NULL;
    fp = fopen("files/queues.dat", "r+b");
    FILE *fp1 = NULL;
    fp1 = fopen("files/queuesCredito.dat", "r+b");

    if (fp == NULL && fp1 == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar queues.dat ou queuesCredito.dat!\n");
        return;
    }

    while (fread(&info, sizeof(PRIORIDADE), 1, fp) == 1) // Enquanto os elementos tiverem a mesma identificacao (prioridade x) adiciona na QUEUE_CREDITO dessa prioridade
    {
        enqueue_prioridade(queue, info);

        res++;
    }
    while (fread(&infoCredito, sizeof(CREDITO), 1, fp1) == 1) // Lê propostas de crédito por analisar a x queue
    {
        enqueue_credito(queue, infoCredito);
    }
    printf("Foram lidas %d queues com sucesso!\n", res);
    fclose(fp);
    fclose(fp1);
}