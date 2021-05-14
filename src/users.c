/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: headers.h
 ** Ficheiro C responsável pelo funcionamento dos utilizadores
\********************************************************************************/

//! HEADER
#include "headers.h"

UTILIZADOR criar_utilizador(ELEM_UTILIZADOR *iniLista)
{
    UTILIZADOR info;
    int res = 0;
    ELEM_UTILIZADOR *aux = NULL;

    printf("Introduza um username!\n");
    fflush(stdin);
    scanf("%s", info.username);
    while (verifique_username(iniLista, info.username) == 1)
    {
        printf("Username ja existente!\n");
        printf("\nIntroduza um username!\n");
        fflush(stdin);
        scanf("%s", info.username);
    }
    printf("Introduza um nome!\n");
    fflush(stdin);
    scanf("%[^\n]", info.nome);

    printf("Introduza uma password!\n");
    fflush(stdin);
    scanf("%s", info.password);

    printf("Introduza o tipo de utilizador\n [4] - Administrador\n [5] - Analista\n");
    fflush(stdin);
    scanf("%d", &info.tipoID);
    if (info.tipoID == 4)
    {
        strcpy(info.tipo, "Administrador");
        info.rank = -99;
    }
    else if (info.tipoID == 5)
    {
        strcpy(info.tipo, "Analista");
        info.rank = 0;
    }
    else
    {
        printf("OPCAO invalida!\n");
        exit(0);
    }

    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        res++;
    }

    info.ID = res + 1;
    return info;
}

void inserir_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista, UTILIZADOR info)
{
    ELEM_UTILIZADOR *novo = NULL;

    novo = (ELEM_UTILIZADOR *)calloc(1, sizeof(ELEM_UTILIZADOR));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (UTILIZADOR)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }

    novo->info = info; // Atribuição do utilizador recebido
    novo->anterior = NULL;
    novo->seguinte = NULL;

    if (*iniLista == NULL) // Caso a lista esteja vazia atribui o primeiro elemento da lista ao elemento criado
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

void gravar_utilizador(ELEM_UTILIZADOR *iniLista)
{
    ELEM_UTILIZADOR *aux = NULL;
    FILE *fp = NULL;

    fp = fopen("files\\users.dat", "w+b"); // w - acrescenta ao ficheiro users.txt

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }

    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        fwrite(&(aux->info), sizeof(UTILIZADOR), 1, fp);
    }

    fclose(fp);
}

int verifique_username(ELEM_UTILIZADOR *iniLista, char username[])
{
    ELEM_UTILIZADOR *aux = NULL;

    //Percorre a lista
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (strcmp(aux->info.username, username) == 0) //Verifica se o username já existe
        {
            return 1;
        }
    }
    return 0;
}

int carregar_utilizador(ELEM_UTILIZADOR **iniLista)
{
    ELEM_UTILIZADOR *aux = NULL;
    ELEM_UTILIZADOR *aux2 = NULL;
    int res = 0;

    FILE *fp = NULL;

    fp = fopen("files\\users.dat", "r+b"); // rb - apenas lê do ficheiro

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");

        return -1;
    }

    // Percorre e lê o ficheiro users.txt
    /*  for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        fread(&(aux->info), sizeof(UTILIZADOR), 1, fp);
        res++;
    }*/

    aux = (ELEM_UTILIZADOR *)calloc(1, sizeof(ELEM_UTILIZADOR));
    aux->seguinte = NULL;
    aux->anterior = NULL;
    while (fread(&(aux->info), sizeof(UTILIZADOR), 1, fp) == 1)
    {
        if (*iniLista == NULL)
        {
            *iniLista = aux;
        }
        else
        {
            aux->seguinte = *iniLista;
            *iniLista = aux;
            aux->anterior = *iniLista;
        }
        aux = aux->seguinte;
        aux = (ELEM_UTILIZADOR *)calloc(1, sizeof(ELEM_UTILIZADOR));
    }

    if (iniLista == NULL)
    {
        return -1;
    }
    printf("Foram lidos %d com sucesso!\n", res);

    fclose(fp);
    return 0;
}

void verifica_primeiro(ELEM_UTILIZADOR *iniListaUTILIZADOR, ELEM_UTILIZADOR *fimListaUTILIZADOR, UTILIZADOR info)
{

    UTILIZADOR utilizador;

    if (carregar_utilizador(&iniListaUTILIZADOR) == -1)
    {
        utilizador = criar_utilizador(iniListaUTILIZADOR);
        inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, utilizador);
        gravar_utilizador(iniListaUTILIZADOR);
    }
}