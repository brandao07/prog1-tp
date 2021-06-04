/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: users.c
 ** Ficheiro C responsável pelo funcionamento dos utilizadores
\********************************************************************************/

//! HEADER
#include "headers.h"

UTILIZADOR criar_utilizador(ELEM_UTILIZADOR *iniLista) //*
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
    while (info.tipoID != 4 && info.tipoID != 5)
    {
        printf("Introduza o tipo de utilizador\n [4] - Administrador\n [5] - Analista\n");
        fflush(stdin);
        scanf("%d", &info.tipoID);
        if (info.tipoID == 4)
        {
            strcpy(info.tipo, "Administrador");
        }
        else if (info.tipoID == 5)
        {
            strcpy(info.tipo, "Analista");
        }
        else
        {
            printf("OPCAO invalida!\n");
        }
    }
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        res++;
    }
    info.rank = 0;
    info.ID = res;
    return info;
}

void inserir_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista, UTILIZADOR *info) //*
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

void gravar_utilizador(ELEM_UTILIZADOR *iniLista) //*
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

int verifique_username(ELEM_UTILIZADOR *iniLista, char username[]) //*
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

int carregar_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista) //*
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

UTILIZADOR login_utilizador(ELEM_UTILIZADOR **iniLista) //*
{
    ELEM_UTILIZADOR *aux = NULL;
    UTILIZADOR erro;
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
    ////system("pause");
    erro.tipoID = 0;
    return erro;
}

int remove_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista, UTILIZADOR sessao) //*
{
    char username[20];
    int ctrl = 0;
    ELEM_UTILIZADOR *aux = NULL;
    printf("Insira o username a ser removido: ");
    fflush(stdin);
    scanf("%s", username);
    if (strcmp(username, sessao.username) == 0)
    {
        printf("Nao se pode remover a si mesmo!\n");
        return -1;
    }
    aux = *iniLista;
    while (aux != NULL && strcmp(aux->info.username, username) != 0)
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

void altera_nome_utilizador(ELEM_UTILIZADOR **iniLista, int id)
{
    int ctrl = 0;
    ELEM_UTILIZADOR *aux = NULL;
    int resposta;
    char novo[100];

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Utilizador #%d\n", aux->info.ID);
            printf("Nome atual: %s\n", aux->info.nome);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);

            if (resposta == 0)
            {
                return;
            }
            else if (resposta == 1)
            {
                printf("Insira o novo nome: \n");
                fflush(stdin);
                scanf("%[^\n]", novo);
                strcpy(aux->info.nome, novo);
            }
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

void altera_username_utilizador(ELEM_UTILIZADOR **iniLista, int id)
{
    int ctrl = 0;
    ELEM_UTILIZADOR *aux = NULL;
    int resposta;
    char novo[100];

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Utilizador #%d\n", aux->info.ID);
            printf("Username atual: %s\n", aux->info.username);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);

            if (resposta == 0)
            {
                return;
            }
            else if (resposta == 1)
            {
                printf("Insira o novo username: \n");
                fflush(stdin);
                scanf("%[^\n]", novo);
                strcpy(aux->info.username, novo);
            }
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

void altera_password_utilizador(ELEM_UTILIZADOR **iniLista, int id)
{
    int ctrl = 0;
    ELEM_UTILIZADOR *aux = NULL;
    int resposta;
    char novo[100];

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Utilizador #%d\n", aux->info.ID);
            printf("Password atual: %s\n", aux->info.password);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);

            if (resposta == 0)
            {
                return;
            }
            else if (resposta == 1)
            {
                printf("Insira a nova password: \n");
                fflush(stdin);
                scanf("%[^\n]", novo);
                strcpy(aux->info.nome, novo);
            }
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

void altera_tipo_utilizador(ELEM_UTILIZADOR **iniLista, int id)
{
    int ctrl = 0;
    ELEM_UTILIZADOR *aux = NULL;
    int resposta, tipo;

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Utilizador #%d\n", aux->info.ID);
            printf("Tipo atual: %s\n", aux->info.tipo);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);

            if (resposta == 0)
            {
                return;
            }
            else if (resposta == 1)
            {
                while (tipo != 4 && tipo != 5)
                {
                    printf("Introduza o tipo de utilizador\n [4] - Administrador\n [5] - Analista\n");
                    fflush(stdin);
                    scanf("%d", &tipo);
                    if (tipo == 4)
                    {
                        strcpy(aux->info.tipo, "Administrador");
                        aux->info.tipoID = 4;
                    }
                    else if (tipo == 5)
                    {
                        strcpy(aux->info.tipo, "Analista");
                        aux->info.tipoID = 5;
                    }
                    else
                    {
                        printf("OPCAO invalida!\n");
                    }
                }
            }
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}