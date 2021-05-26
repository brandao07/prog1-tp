/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: users.c
 ** Ficheiro C responsável pelo funcionamento dos utilizadores
\********************************************************************************/

//! HEADER
#include "headers.h"

UTILIZADOR criar_utilizador(ELEM_UTILIZADOR *iniLista)
{
    UTILIZADOR info;
    int res = 0;
    ELEM_UTILIZADOR *aux = NULL;
    printf("Introduza um username:\n");
    fflush(stdin);
    scanf("%s", info.username);
    while (verifique_username(iniLista, info.username) == 1)
    {
        printf("Username ja existente!\n");
        printf("\nIntroduza um username:\n");
        fflush(stdin);
        scanf("%s", info.username);
    }
    printf("Introduza um nome:\n");
    fflush(stdin);
    scanf("%[^\n]", info.nome);
    printf("Introduza uma password:\n");
    fflush(stdin);
    scanf("%s", info.password);
    printf("Introduza o tipo de utilizador\n [4] - Administrador\n [5] - Analista\n");
    fflush(stdin);
    scanf("%d", &info.tipoID);
    if (info.tipoID == 4)
    {
        strcpy(info.tipo, "Administrador");
        info.rank = NULL;
    }
    else if (info.tipoID == 5)
    {
        strcpy(info.tipo, "Analista");
        info.rank = 0;
    }
    else
    {
        printf("OPCAO invalida!\n");
        return;
    }
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        res++;
    }
    info.ID = res;
    return info;
}

void inserir_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista, UTILIZADOR *info)
{
    ELEM_UTILIZADOR *novo = NULL;
    novo = (ELEM_UTILIZADOR *)calloc(1, sizeof(ELEM_UTILIZADOR));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (UTILIZADOR)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }
    novo->info = *info; // Atribuição do utilizador recebido
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
    fp = fopen("files/users.dat", "w+b");

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }
    aux = iniLista;
    while (aux != NULL)
    {
        fwrite(&(aux->info), sizeof(UTILIZADOR), 1, fp);
        aux = aux->seguinte;
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

int carregar_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista)
{
    UTILIZADOR info;
    int res = 0;
    FILE *fp = NULL;
    fp = fopen("files/users.dat", "r+b");
    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("Ficheiro inexistente.\n");

        return -1;
    }
    while (fread(&info, sizeof(UTILIZADOR), 1, fp) == 1)
    {
        inserir_utilizador(iniLista, fimLista, &info);
        res++;
    }

    if (iniLista == NULL)
    {
        return -1;
    }
    printf("Foram lidos %d  utilizadores com sucesso!\n", res);
    fclose(fp);
    return 0;
}

UTILIZADOR login_utilizador(ELEM_UTILIZADOR **iniLista)
{
    ELEM_UTILIZADOR *aux = NULL;
    char username[20], password[20];

    printf("Username: ");
    fflush(stdin);
    scanf("%s", username);
    printf("Password: ");
    fflush(stdin);
    scanf("%s", password);
    for (aux = *iniLista; aux != NULL; aux = aux->seguinte)
    {
        if (strcmp(username, aux->info.username) == 0)
        {
            if (strcmp(password, aux->info.password) == 0)
            {
                printf("Login efetuado com sucesso!!\n");
                return aux->info;
            }
        }
    }
    printf("Os dados de login nao sao validos !!\n");
    //system("pause");
    return;
}

int remove_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista)
{
    char username[20];
    ELEM_UTILIZADOR *aux = *iniLista;

    printf("Insira o username a ser removido: ");
    fflush(stdin);
    scanf("%s", username);
    while (aux != NULL && aux->info.username != username)
    {
        aux = aux->seguinte;
    }
    if (aux == NULL) // não existe elemento num ou a lista é vazia
    {
        printf("Lista vazia!");
        return -1;
    }
    if (aux->anterior == NULL) // vai remover o 1º elemento
    {
        *iniLista = aux->seguinte;
        if (*iniLista != NULL)
        {
            (*iniLista)->anterior = NULL;
        }
    }
    else
    {
        aux->anterior->seguinte = aux->seguinte;
    }
    if (aux->seguinte == NULL) // vai remover o ultimo elemento
    {
        *fimLista = aux->anterior;
        if (*fimLista != NULL)
        {
            (*fimLista)->seguinte = NULL;
        }
    }
    else
    {
        aux->seguinte->anterior = aux->anterior;
    }
    free(aux);
    return 0;
}