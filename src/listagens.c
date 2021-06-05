/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: listagens.c
 ** Ficheiro C responsável pelas listagens do programa
\***********************************************************************************************/

#include "headers.h"

void listar_credito(ELEM_CREDITO *aux) //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("PROPOSTAS");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("----------------*\n");
    printf("\nProposta #%d\n", aux->info.numeroSequencial);
    printf("\tID: %d\n\tNome: %s\n\tIBAN: %s\n\tMontante: %.2f\n\tPrioridade: %s\n",
           aux->info.ID,
           aux->info.nome,
           aux->info.IBAN,
           aux->info.montante,
           aux->info.prioridade);
    printf("Numero de garantias: %d\n", aux->info.garantiaNumero);
    printf("*--------------------------------------*\n");
    //system("pause");
    for (int i = 0; i < aux->info.garantiaNumero; i++)
    {
        printf("\n*------------");
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        printf("GARANTIAS");
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        printf("----------------*\n");
        printf("\nGarantia #%i\n", i + 1);
        printf("\tTipo:%s\n\tDescricao:%s\n\tValor:%.2f\n",
               aux->info.garantia[i].tipo,
               aux->info.garantia[i].descricao,
               aux->info.garantia[i].valor);
        printf("*--------------------------------------*\n");
        //system("pause");
    }
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("ANALISE");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("----------------*\n");
    printf("Analise da proposta #%d\n", aux->info.numeroSequencial);
    printf("\n\tAnalisada por: %s\n\tSituacao: %s\n\tJustificacao: %s\n\tData: %d/%d/%d\n",
           aux->analise.utilizador,
           aux->analise.situacao,
           aux->analise.justificacao,
           aux->analise.data.dia,
           aux->analise.data.mes,
           aux->analise.data.ano);
    printf("*--------------------------------------*\n");
    //system("pause");
}

void listar_por_analisar_aux(QUEUE_CREDITO *aux) //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("PROPOSTAS");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("----------------*\n");
    printf("\nProposta #%d\n", aux->info.numeroSequencial);
    printf("\tID: %d\n\tNome: %s\n\tIBAN: %s\n\tMontante: %.2f\n\tPrioridade: %s\n",
           aux->info.ID,
           aux->info.nome,
           aux->info.IBAN,
           aux->info.montante,
           aux->info.prioridade);
    printf("Numero de garantias: %d\n", aux->info.garantiaNumero);
    printf("*--------------------------------------*\n");
    //system("pause");
    for (int i = 0; i < aux->info.garantiaNumero; i++)
    {
        printf("\n*------------");
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        printf("GARANTIAS");
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        printf("----------------*\n");
        printf("\nGarantia #%i\n", i + 1);
        printf("\tTipo:%s\n\tDescricao:%s\n\tValor:%.2f\n",
               aux->info.garantia[i].tipo,
               aux->info.garantia[i].descricao,
               aux->info.garantia[i].valor);
        printf("*--------------------------------------*\n");
        //system("pause");
    }
}

void print_utilizador(ELEM_UTILIZADOR *aux)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("UTILIZADOR");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("----------------*\n");
    printf("\tID: %d\n\tUsername: %s\n\tNome: %s\n\tTipo: %s",
           aux->info.ID,
           aux->info.username,
           aux->info.nome,
           aux->info.tipo);
    printf("\n*--------------------------------------*\n");
    //system("pause");
}

void listar_propcredito(CREDITO *info)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("PROPOSTA");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("----------------*\n");
    printf("\nProposta #%d\n", info->numeroSequencial);
    printf("\tID: %d\n\tNome: %s\n\tIBAN: %s\n\tMontante: %.2f\n\tPrioridade: %s\n",
           info->ID,
           info->nome,
           info->IBAN,
           info->montante,
           info->prioridade);
    printf("Numero de garantias: %d\n", info->garantiaNumero);
    printf("*--------------------------------------*\n");
    //system("pause");
    for (int i = 0; i < info->garantiaNumero; i++)
    {
        printf("\n*------------");
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        printf("GARANTIAS");
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        printf("----------------*\n");
        printf("\nGarantia #%i\n", i + 1);
        printf("\tTipo:%s\n\tDescricao:%s\n\tValor:%.2f\n",
               info->garantia[i].tipo,
               info->garantia[i].descricao,
               info->garantia[i].valor);
        printf("*--------------------------------------*\n");
        //system("pause");
    }
}

void pesquisar_credito(ELEM_CREDITO *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Lista de propostas de credito vazia!\n");
    }
    else
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        int ctrl = 0;
        char nome[100];
        ELEM_CREDITO *aux = NULL;

        printf("Insira o nome: \n");
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        fflush(stdin);
        scanf("%[^\n]", nome);
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

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
}

void listar_analisadas(ELEM_CREDITO *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Lista de propostas de credito vazia!\n");
    }
    else
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        ELEM_CREDITO *aux = NULL;
        int ctrl = 0;
        int id;

        printf("Insira o ID: ");
        fflush(stdin);
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        scanf("%d", &id);
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

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
}

void listar_prioridade(ELEM_CREDITO *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Lista de propostas de credito vazia!\n");
    }
    else
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        int ctrl = 0;
        char prioridade[20];
        ELEM_CREDITO *aux = NULL;

        printf("Insira o tipo de prioridade que pretende listar: \n");
        fflush(stdin);
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        scanf("%s", prioridade);
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

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
}

void listar_acima_montante(ELEM_CREDITO *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Lista de propostas de credito vazia!\n");
    }
    else
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        float montante;
        int ctrl = 0;
        ELEM_CREDITO *aux = NULL;

        printf("Insira o montante para que as propostas acima desse valor sejam listada: \n");
        fflush(stdin);
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        scanf("%f", &montante);
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

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
}

void listar_por_utilizador(ELEM_CREDITO *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Nao existem propostas de credito registadas!!\n");
    }
    else
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        int id;
        int ctrl = 0;
        ELEM_CREDITO *aux = NULL;

        printf("Insira o ID: \n");
        fflush(stdin);
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        scanf("%d", &id);
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

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
            printf("Nao foram encontradas propostas analisdas por este utilizador!");
        }
    }
}

void listar_por_analisar(QUEUES *queue) //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int ctrl = 0;
    int id;
    QUEUE_CREDITO *aux_in = NULL; // ciclo for para a lista de listas duplamente ligadas (percorre linhas)
    QUEUES *aux_out = NULL;       // ciclo for para a lista duplamente ligada (percorre colunas)

    printf("Insira o ID: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &id);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

    for (aux_out = queue; aux_out != NULL; aux_out = aux_out->seguinte) // percorre a lista ligada de listas duplamente ligadas
    {
        for (aux_in = (aux_out)->iniLista; aux_in != NULL; aux_in = aux_in->seguinte) // percorre a lista duplamente ligadas
        {
            if (aux_in->info.ID == id)
            {
                listar_por_analisar_aux(aux_in);
                ctrl = 1;
            }
        }
    }
    if (ctrl == 0)
    {
        printf("Proposta nao encontrada!\n");
    }
}

void bubbleSort_listas_credito(ELEM_CREDITO *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Nao existem propostas de credito registadas!!\n");
    }
    else
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        ELEM_CREDITO *aux = NULL;
        int ctrl = 0;
        char username[30];

        printf("Insira o username: ");
        fflush(stdin);
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        scanf("%s", username);
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

        // primeiro ordena por data e depois por situação
        bubbleSort_data_dia(iniLista);
        bubbleSort_data_mes(iniLista);
        bubbleSort_data_ano(iniLista);
        bubbleSort_situacao(iniLista); // ordena por situação

        for (aux = iniLista; aux != NULL; aux = aux->seguinte)
        {
            if (strcmp(aux->analise.utilizador, username) == 0)
            {
                listar_credito(aux);
                ctrl = 1;
            }
        }

        if (ctrl == 0)
        {
            printf("Nao foram encontradas propostas de credito analisadas por este ID(%s)!", username);
        }
    }
}

void listar_ranking(ELEM_UTILIZADOR *iniLista) //*
{
    if (iniLista == NULL)
    {
        printf("Lista de Utilizadores vazia!\n");
    }
    else
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        int ctrl = 0;
        ELEM_UTILIZADOR *aux = NULL;

        bubbleSort_rank(iniLista); // ordena por montante

        printf("\n*-------------");
        SetConsoleTextAttribute(console, FOREGROUND_RED);
        printf("RANKING");
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        printf("-------------*\n");

        for (aux = iniLista; aux != NULL; aux = aux->seguinte)
        {

            if (aux->info.tipoID == 5)
            {
                printf("%s - (%d)------- #%d\n",
                       aux->info.nome,
                       aux->info.ID,
                       aux->info.rank);
                ctrl = 1;
            }
        }

        printf("\n*-------------------------------*\n");
        //system("pause");

        if (ctrl == 0)
        {
            printf("Nao se encontram analistas registados!\n");
        }
    }
}

void listar_utilizadores(ELEM_UTILIZADOR *iniLista, int tipo) //*
{
    ELEM_UTILIZADOR *aux = NULL;

    if (iniLista == NULL)
    {
        printf("Lista de utilizadores vazia !\n");
    }
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (tipo == aux->info.tipoID)
        {
            print_utilizador(aux);
        }
    }
}
