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

void gravar_queue(QUEUE_CREDITO **iniQueue)
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

void listar_por_analisar(QUEUE_CREDITO *iniQueue)
{
    int ctrl = 0;
    int id;
    QUEUE_CREDITO *aux = NULL;

    printf("Insira o ID: ");
    fflush(stdin);
    scanf("%d", id);

    if (iniQueue == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        for (aux = iniQueue; aux != NULL; aux = aux->seguinte)
        {
            if (aux->info.ID == id)
            {
                printf("\n*------------PROPOSTA----------------*\n");
                printf("\nProposta #%d\n", aux->info.numeroSequencial);
                printf("\tID: %d\n\tNome: %s\n\tIBAN: %s\n\tMontante: %.2f\n\tPrioridade: %s\n",
                       aux->info.ID,
                       aux->info.nome,
                       aux->info.IBAN,
                       aux->info.montante,
                       aux->info.prioridade);
                printf("Numero de garantias: %d\n", aux->info.garantiaNumero);
                printf("*--------------------------------------*\n");
                system("pause");
                for (int i = 0; i < aux->info.garantiaNumero; i++)
                {
                    printf("\n*------------GARANTIAS----------------*\n");
                    printf("\nGarantia #%i\n", i + 1);
                    printf("\tTipo:%s\n\tDescricao:%s\n\tValor:%.2f€\n",
                           aux->info.garantia[i].tipo,
                           aux->info.garantia[i].descricao,
                           aux->info.garantia[i].valor);
                    printf("*--------------------------------------*\n");
                    system("pause");
                }
                ctrl = 1;
            }
        }
        if (ctrl == 0)
        {
            printf("Proposta nao encontrada!\n");
        }
    }
}