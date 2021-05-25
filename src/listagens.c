#include "headers.h"

void listar_credito(ELEM_CREDITO *aux)
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
    printf("\n*------------ANALISE----------------*\n");
    printf("Analise da proposta #%d\n", aux->info.numeroSequencial);
    printf("\tEstado da proposta: Analisada\n\tSituacao: %s\n\tJustificacao: %s\n\tData: %s\n",
           aux->analise.situacao,
           aux->analise.justificacao,
           aux->analise.data);
    printf("*--------------------------------------*\n");
    system("pause");
}

void imprime_credito(ELEM_CREDITO *iniLista, int id)
{
    int ctrl = 0;
    ELEM_CREDITO *aux = NULL;
    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for (aux = iniLista; aux != NULL; aux = aux->seguinte)
        {
            if (aux->info.ID == id)
            {
                listar_credito(aux);
                ctrl = 1;
            }
        }
        if (ctrl == 0)
        {
            printf("Proposta nao encontrada!\n");
        }
    }
}

void pesquisar_credito(ELEM_CREDITO *iniLista)
{
    int ctrl = 0;
    char nome[100];
    ELEM_CREDITO *aux = NULL;
    if (iniLista == NULL)
    {
        printf("Nao existem propostas de credito registadas!!\n");
        return;
    }
    printf("Insira o nome da proposta de credito a pesquisar: \n");
    fflush(stdin);
    scanf("%[^\n]", nome);
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (strcmp(aux->info.nome, nome) == 0)
        {
            listar_credito(aux);
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("A proposta de credito cujo nome e %s nao se encontra registado", nome);
    }
}

void listar_analisadas(ELEM_CREDITO *iniLista)
{
    ELEM_CREDITO *aux = NULL;
    int ctrl = 0;
    int id;
    printf("Insira o ID: ");
    fflush(stdin);
    scanf("%d", &id);
    if (iniLista == NULL)
    {
        printf("Nao existem propostas de credito registadas!!\n");
        return;
    }
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (aux->info.ID == id)
        {
            listar_credito(aux);
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Nao foram encontradas propostas de credito analisadas por este ID(%d)!", id);
    }
}

void listar_prioridade(ELEM_CREDITO *iniLista)
{
    int ctrl = 0;
    char prioridade[20];
    ELEM_CREDITO *aux = NULL;
    if (iniLista == NULL)
    {
        printf("Nao existem propostas de credito registadas!!\n");
        return;
    }
    printf("Insira o tipo de prioridade que pretende listar: \n");
    fflush(stdin);
    scanf("%s", prioridade);
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (strcmp(aux->info.prioridade, prioridade) == 0)
        {
            listar_credito(aux);
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("O tipo de prioridade que pretende listar(%s) nao se encontra registado", prioridade);
    }
}

void listar_acima_montante(ELEM_CREDITO *iniLista)
{
    float montante;
    int ctrl = 0;
    ELEM_CREDITO *aux = NULL;
    if (iniLista == NULL)
    {
        printf("Nao existem propostas de credito registadas!!\n");
        return;
    }
    printf("Insira o montante para que as propostas acima desse valor sejam listada: \n");
    fflush(stdin);
    scanf("%f", &montante);
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (aux->info.montante > montante)
        {
            listar_credito(aux);
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Nao foram registadas propostas com valor acima de %.2f!", montante);
    }
}

void listar_por_utilizador(ELEM_CREDITO *iniLista)
{
    int id;
    int ctrl = 0;
    ELEM_CREDITO *aux = NULL;
    if (iniLista == NULL)
    {
        printf("Nao existem propostas de credito registadas!!\n");
        return;
    }
    printf("Insira o ID: \n");
    fflush(stdin);
    scanf("%d", &id);
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (aux->analise.utilizador == id)
        {
            listar_credito(aux);
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Nao foram registadas propostas com valor acima de !");
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

void bubbleSort_listas_credito(ELEM_CREDITO *iniLista)
{
    ELEM_CREDITO *aux = NULL;
    int ctrl = 0;
    int id;
    printf("Insira o ID: ");
    fflush(stdin);
    scanf("%d", &id);
    if (iniLista == NULL)
    {
        printf("Nao existem propostas de credito registadas!!\n");
        return;
    }
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (aux->info.ID == id)
        {
            bubbleSort_data(iniLista);
            bubbleSort_situacao(iniLista);
            listar_credito(aux);
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Nao foram encontradas propostas de credito analisadas por este ID(%d)!", id);
    }
}