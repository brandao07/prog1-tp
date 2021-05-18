/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: credito.c
 ** Ficheiro C responsável por todas as operações relacionadas com as propostas de crédito
\***********************************************************************************************/

//! HEADER
#include "headers.h"

CREDITO inserir_credito(ELEM_PRIORIDADE *iniLista)
{
    CREDITO info;
    int garantiaOpcao[MAX_GARANTIAS_TIPO];
    printf("Introduza nome:\n");
    fflush(stdin);
    scanf("%[^\n]", info.nome);
    printf("Introduza IBAN:\n");
    fflush(stdin);
    scanf("%s", info.IBAN);
    printf("Quantas garantias?\n");
    fflush(stdin);
    scanf("%d", &info.garantiaNumero);
    if (info.garantiaNumero > MAX_GARANTIAS)
    {
        printf("Numero maximo de garantias excedido!\n");
    }
    else
    {
        for (int i = 0; i < info.garantiaNumero; i++)
        {
            printf("Tipo de garantia?\n");
            printf("\n[0] - Imovel");
            printf("\n[1] - Fiador");
            printf("\n[2] - Depositos");
            printf("\n[3] - Produtos");
            fflush(stdin);
            scanf("%d", &garantiaOpcao[i]);
            if (garantiaOpcao[i] == 0)
            {
                strcpy(info.garantia[i].tipo, "Imovel");
            }
            else if (garantiaOpcao[i] == 1)
            {
                strcpy(info.garantia[i].tipo, "Fiador");
            }
            else if (garantiaOpcao[i] == 2)
            {
                strcpy(info.garantia[i].tipo, "Depositos");
            }
            else if (garantiaOpcao[i] == 3)
            {
                strcpy(info.garantia[i].tipo, "Produtos");
            }
            else if (garantiaOpcao[i] != 0 || garantiaOpcao[i] != 1 || garantiaOpcao[i] != 2 || garantiaOpcao[i] || 3)
            {
                printf("OPCAO invalida!\n");
                exit(0);
            }
            printf("Descricao sobre a proposta:\n");
            fflush(stdin);
            scanf("%[^\n]", info.garantia[i].descricao);
            printf("Valor:\n");
            fflush(stdin);
            scanf("%f", &info.garantia[i].valor);
        }
        printf("Montante:\n");
        scanf("%f", &info.montante);
        strcpy(info.prioridade, carrega_prioridade(iniLista, info.montante));
        info.analise.valor = 0;

        return info;
    }
}

void enqueue_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista, CREDITO info)
{
    ELEM_CREDITO *novo = NULL;
    novo = (ELEM_CREDITO *)calloc(1, sizeof(ELEM_CREDITO));
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

void dequeue_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista)
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

void imprime_credito(ELEM_CREDITO *iniLista, int id)
{
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
                printf("\n*------------PROPOSTA----------------*\n");
                printf("\nProposta #%d\n", aux->info.numeroSequencial);
                printf("\tNome: %s\n\tIBAN: %s\n\tMontante: %.2f\n\tPrioridade: %s\n",
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
                if (aux->info.analise.valor == 0)
                {
                    printf("\tEstado da proposta: NAO analisada\n");
                }
                else
                {
                    printf("\tEstado da proposta: Analisada\n\tSituacao: %s\n\tData: %s\n",
                           aux->info.analise.situacao,
                           aux->info.analise.data);
                }
                printf("*--------------------------------------*\n");
                system("pause");
                return;
            }
            else
            {
                printf("Proposta nao encontrada!\n");
                return;
            }
        }
    }
}

int altera_nome(ELEM_CREDITO **iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    int resposta;
    char novo[100];

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Nome atual: %s\n", aux->info.nome);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);
            if (resposta == 0)
            {
                return -1;
            }
            if (resposta == 1)
            {
                printf("Insira o novo nome: \n");
                fflush(stdin);
                scanf("%[^\n]", novo);

                strcpy(aux->info.nome, novo);
            }
        }
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

int altera_iban(ELEM_CREDITO **iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    int resposta;
    char novo[50];

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.IBAN)
        {
            printf("IBAN atual: %s\n", aux->info.IBAN);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);
            if (resposta == 0)
            {
                return -1;
            }
            if (resposta == 1)
            {
                printf("Insira o novo IBAN: \n");
                fflush(stdin);
                scanf("%[^\n]", novo);

                strcpy(aux->info.IBAN, novo);
            }
        }
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

int altera_numero_garantias(ELEM_CREDITO **iniLista, int id)
{ //Esta mal 
    ELEM_CREDITO *aux = NULL;
    int resposta;
    int novo;

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.garantiaNumero)
        {
            printf("Numero de garantias atuais: %s\n", aux->info.garantiaNumero);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);
            if (resposta == 0)
            {
                return -1;
            }
            if (resposta == 1)
            {
                printf("Insira o novo numero de garantias: \n");
                fflush(stdin);
                scanf("%d", novo);

                strcpy(aux->info.garantiaNumero, novo);
            }
        }
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

