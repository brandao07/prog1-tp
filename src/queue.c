/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: queue.c
 ** Ficheiro C responsável por todas as operações relacionadas com a fila de processamento
\***********************************************************************************************/
#include "headers.h"

void enqueue_credito(QUEUES **queue, CREDITO info)
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
    if (((*queue)->iniLista == NULL) && ((*queue)->fimLista == NULL))
    {
        (*queue)->iniLista = (*queue)->fimLista = novo;
    }
    else
    {
        (*queue)->fimLista->seguinte = novo;
        (*queue)->fimLista = novo;
    }
}

void dequeue_credito(QUEUES **queue)
{
    QUEUE_CREDITO *temp = NULL;
    temp = (*queue)->iniLista;
    if (((*queue)->iniLista == NULL) && ((*queue)->fimLista == NULL))
    {
        printf("Fila vazia!\n");
    }
    else
    {
        (*queue)->iniLista = (*queue)->iniLista->seguinte;
        free(temp);
    }
}

void insere_propcredito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista, QUEUES **queue, ELEM_UTILIZADOR **iniListaU, UTILIZADOR sessao)
{
    char prioridade[20];
    CREDITO info;
    ELEM_CREDITO *novo = NULL;
    novo = (ELEM_CREDITO *)calloc(1, sizeof(ELEM_CREDITO));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (CREDITO)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }
    printf("Introduza o tipo de prioridade que pretende analisar: \n");
    fflush(stdin);
    scanf("%s", &prioridade);
    /*
    Tem agora de verificar em qual das listas 
    é que se encontra a prioridade strcmp com for
    */

   

    /* passa informacao do primeiro elemento da fila de processamento de uma determinada prioridade para o 
    novo no que sera inserido no fim da lista de propostas de credito*/
    info = (*queue)->iniLista->info;
    novo->info = info;
    novo->anterior = NULL;
    novo->seguinte = NULL;
    if ((*queue)->fimLista == NULL)
    {
        (*queue)->iniLista = novo;
        (*queue)->fimLista = novo;
    }
    else
    {
        novo->anterior = (*queue)->fimLista;
        (*queue)->fimLista->seguinte = novo;
        (*queue)->fimLista = novo;
    }
    dequeue_credito(queue);
    analisar_credito(fimLista, iniListaU, sessao);
}

void gravar_queues(QUEUES *queue)
{
    QUEUES *aux = NULL;
    QUEUE_CREDITO *aux2 = NULL;
    FILE *fp = NULL;
    fp = fopen("files/queues.dat", "w+b"); // w - acrescenta ao ficheiro queues.dat

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }
    for (aux = queue; aux != NULL; aux = aux->seguinte)
    {
        fwrite(&(aux->prioridade), sizeof(PRIORIDADE), 1, fp);
        for (aux2 = queue->iniLista; aux2 != NULL; aux2 = aux2->seguinte)
        {
            fwrite(&(aux2->info), sizeof(CREDITO), 1, fp);
        }
    }
    fclose(fp);
}

int carregar_queues(QUEUES **queue)
{
    PRIORIDADE info;
    QUEUES *aux = NULL;
    int res = 0;
    FILE *fp = NULL;
    fp = fopen("files/queues.dat", "r+b"); // rb - apenas lê do ficheiro
    if (fp == NULL)                        // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("Ficheiro inexistente.\n");

        return -1;
    }
    while (fread(&info, sizeof(PRIORIDADE), 1, fp) == 1)
    {
        for (aux = (*queue)->iniLista; aux != NULL; aux->iniLista = aux->iniLista->seguinte)
        {
            fread(&aux->iniLista, sizeof(QUEUE_CREDITO), 1, fp) == 1;
        }

        ini_queue(queue, &info, aux->iniLista);
        res++;
    }

    if (res==0)
    {
        printf("Lista vazia\n");
        fclose(fp);
        return -1;
    }
    printf("Foram lidas %d prioridades com sucesso!\n", res);
    fclose(fp);
    return 0;
}

void ini_queue(QUEUES **queue, PRIORIDADE *info, QUEUE_CREDITO *infoLista)
{
    QUEUES *novo = NULL;
    novo = (QUEUES *)calloc(1, sizeof(QUEUES));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (UTILIZADOR)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }
    novo->prioridade = *info; // Atribuição do utilizador recebido
    novo->seguinte = NULL;

    for (novo = (*queue)->iniLista; novo != NULL; novo->iniLista = novo->iniLista->seguinte)
    {
        novo->iniLista = infoLista;
    }
    if ((*queue)->iniLista == NULL) // Caso a lista esteja vazia atribui o primeiro elemento da lista ao elemento criado
    {
        (*queue)->iniLista = novo;
        (*queue)->fimLista = novo;
    }
    else
    {
        (*queue)->fimLista->seguinte = novo;
        (*queue)->fimLista = novo;
    }
}
