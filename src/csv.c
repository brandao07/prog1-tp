/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: csv.c
 ** Ficheiro C responsável por todas as operações com a informação recebida do ficheiro CSV
\***********************************************************************************************/

//! HEADER
#include "headers.h"

void recebe_csv(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, char ficheiroCSV[])
{
    // Variáveis necessárias para operar com o ficheiro csv
    PRIORIDADE info;
    char tamanhoCSV[100], prioridade[50], *ptr = NULL, *token = NULL;
    float montanteInferior, montanteSuperior;
    FILE *fp = NULL;

    fp = fopen(ficheiroCSV, "r"); // r - apenas lê do ficheiro

    // Teste para ver se houve problema ao carregar o ficheiro
    if (fp == NULL)
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }
    while (fscanf(fp, "%s", tamanhoCSV) != EOF) // Percorre o ficheiro até ao fim (EOF)
    {
        // O ";" é o nosso delimitador
        token = strtok(tamanhoCSV, ";");
        strcpy(prioridade, token);
        token = strtok(NULL, ";");
        montanteInferior = strtoll(token, &ptr, 10); // strtoll para converter caracter em inteiro do montante inferior
        token = strtok(NULL, ";");
        montanteSuperior = strtoll(token, &ptr, 10); // strtoll para converter caracter em inteiro do montante superior
        info = criar_prioridade(prioridade, montanteInferior, montanteSuperior);
        inserir_prioridade(iniLista, fimLista, info);
    }
}

PRIORIDADE criar_prioridade(char prioridade[], int montanteInferior, int montanteSuperior)
{
    PRIORIDADE info;

    //Atribuição da informação recebida para a estrutura PRIORIDADE
    strcpy(info.nome, prioridade);
    info.montanteInferior = montanteInferior;
    info.montanteSuperior = montanteSuperior;
    return info;
}

void inserir_prioridade(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, PRIORIDADE info)
{
    ELEM_PRIORIDADE *novo = NULL;

    novo = (ELEM_PRIORIDADE *)calloc(1, sizeof(ELEM_PRIORIDADE));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (PRIORIDADE)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }

    novo->info = info; // Atribuição da prioridade recebida
    novo->anterior = NULL;
    novo->seguinte = NULL;

    if (*fimLista == NULL) // Caso a lista esteja vazia atribui o primeiro elemento da lista ao elemento criado
    {
        *iniLista = novo;
        *fimLista = novo;
    }
    else
    {
        novo->anterior = *fimLista;
        (*fimLista)->seguinte = novo;
        *fimLista = novo;
    }
}

void imprime_prioridades(ELEM_PRIORIDADE *iniLista)
{
    ELEM_PRIORIDADE *aux = NULL;

    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    printf("\n*------------PRIORIDADES---------------*\n");
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        printf("%s;%.2f;%.2f\n", // print com estrutura CSV
               aux->info.nome,
               aux->info.montanteInferior,
               aux->info.montanteSuperior);
    }
    printf("*---------------------------------------*\n");
}

char *carrega_prioridade(ELEM_PRIORIDADE *iniLista, float montante)
{
    PRIORIDADE prioridade;
    ELEM_PRIORIDADE *aux = NULL;
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (montante >= prioridade.montanteInferior && montante < prioridade.montanteSuperior)
        {
            return prioridade.nome;
        }       
    }
    return NULL;
}

int conta_prioridade(ELEM_PRIORIDADE *iniLista)
{
    int res = 0;
    ELEM_PRIORIDADE *aux = NULL;

    if (iniLista == NULL)
    {
        printf("Sem prioridades!\n");
        return;
    }

    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        res++;
    }
    return res;
}