/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: prioridade.c
 ** Ficheiro C responsável por todas as operações com a informação recebida do ficheiro CSV
\***********************************************************************************************/

//! HEADER
#include "headers.h"

void recebe_csv(QUEUES **queue, ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, char ficheiroCSV[]) //*
{
    FILE *fp = NULL;
    fp = fopen(ficheiroCSV, "r"); // r - apenas lê do ficheiro
    // Teste para ver se houve problema ao carregar o ficheiro
    if (fp == NULL)
    {
        printf("ERRO ao carregar o ficheiro CSV!\n");
        return;
    }
    else
    {
        PRIORIDADE info;
        char tamanhoCSV[100], prioridade[50], *ptr = NULL, *token = NULL;
        float montanteInferior, montanteSuperior;

        while (fscanf(fp, "%s", tamanhoCSV) != EOF) // Percorre o ficheiro até ao fim (EOF)
        {
            // O ";" é o nosso delimitador
            token = strtok(tamanhoCSV, ";");
            strcpy(prioridade, token);
            token = strtok(NULL, ";");
            montanteInferior = strtoll(token, &ptr, 10); // strtoll para converter caracter em inteiro do montante inferior
            token = strtok(NULL, ";");
            montanteSuperior = strtoll(token, &ptr, 10); // strtoll para converter caracter em inteiro do montante superior
            info = criar_prioridade(queue, prioridade, montanteInferior, montanteSuperior);
            inserir_prioridade(iniLista, fimLista, &info);
        }
    }
}

PRIORIDADE criar_prioridade(QUEUES **queue, char prioridade[], int montanteInferior, int montanteSuperior) //*
{
    PRIORIDADE info;
    //Atribuição da informação recebida para a estrutura PRIORIDADE
    strcpy(info.nome, prioridade);
    info.montanteInferior = montanteInferior;
    info.montanteSuperior = montanteSuperior;
    enqueue_prioridade(queue, info);
    return info;
}

void inserir_prioridade(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, PRIORIDADE *info) //*
{
    ELEM_PRIORIDADE *novo = NULL;
    novo = (ELEM_PRIORIDADE *)calloc(1, sizeof(ELEM_PRIORIDADE));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (PRIORIDADE)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }
    novo->info = *info; // Atribuição da prioridade recebida
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

void imprime_prioridades(QUEUES **queue) //TODO
{
    QUEUES *aux = NULL;
    if (queue == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    printf("\n*------------PRIORIDADES---------------*\n");
    for (aux = (*queue); aux != NULL; aux = aux->seguinte)
    {
        printf("%s;%.2f;%.2f\n", // print com estrutura CSV
               aux->prioridade.nome,
               aux->prioridade.montanteInferior,
               aux->prioridade.montanteSuperior);
    }
    printf("*---------------------------------------*\n");
}

const char *carrega_prioridade(ELEM_PRIORIDADE *iniLista, float montante) //! return NULL duvidoso..
{
    ELEM_PRIORIDADE *aux = NULL;
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (montante >= aux->info.montanteInferior && montante < aux->info.montanteSuperior)
        {
            return aux->info.nome;
        }
    }
    return '\0';
}

/* int conta_prioridade(ELEM_PRIORIDADE *iniLista) //?
{
    if (iniLista == NULL)
    {
        printf("Sem prioridades!\n");
    }
    else
    {
        int res = 0;
        ELEM_PRIORIDADE *aux = NULL;

        for (aux = iniLista; aux != NULL; aux = aux->seguinte)
        {
            res++;
        }

        return res;
    }
} */

void gravar_prioridades(ELEM_PRIORIDADE *iniLista) //*
{
    ELEM_PRIORIDADE *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("files/prioridade.dat", "w+b");

    if (fp == NULL) // Teste para ver se houve problema ao gravar o ficheiro
    {
        printf("ERRO ao gravar o ficheiro prioridade.dat!\n");
        return;
    }
    aux = iniLista;
    while (aux != NULL)
    {
        fwrite(&(aux->info), sizeof(PRIORIDADE), 1, fp);
        aux = aux->seguinte;
    }
    fclose(fp);
}

int carrega_prioridades(QUEUES **queue, ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista) //*
{
    PRIORIDADE info;
    int res = 0;
    FILE *fp = NULL;

    fp = fopen("files/prioridade.dat", "r+b");
    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("Ficheiro prioridade.dat inexistente!\n");
        return -1;
    }

    while (fread(&info, sizeof(PRIORIDADE), 1, fp) == 1)
    {
        enqueue_prioridade(queue, info);
        inserir_prioridade(iniLista, fimLista, &info);
        res++;
    }

    if (iniLista == NULL)
    {
        return -1;
    }

    printf("Foram lidas %d prioridades com sucesso!\n", res);
    fclose(fp);

    return 0;
}