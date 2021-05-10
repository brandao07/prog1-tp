/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: headers.h
 ** Ficheiro C responsável pelo funcionamento dos utilizadores
\********************************************************************************/

void criarUtilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista, UTILIZADOR info)
{
    int res = 0;
    ELEM_UTILIZADOR *aux = NULL;
    
    printf("Introduza um username!\n");
    fflush(stdin);
    scanf("%s", info.username);
    if (verifiqueUsername(*iniLista, info.username) == 1)
    {
        printf("Username ja existente!\n");
        return;
    }

    printf("Introduza um nome!\n");
    fflush(stdin);
    scanf("%[^\n]", info.nome);

    printf("Introduza uma password!\n");
    fflush(stdin);
    scanf("%s", info.password);

    printf("Introduza o tipo de utilizador\n [4] - Administrador\n [5] - Analista\n");
    scanf("%i", info.tipoID);
    if (info.tipoID == 4)
    {
        strcpy(info.tipo, "Administrador");
    }
    if (info.tipoID == 5)
    {
        strcpy(info.tipo, "Analista");
    }
    else
    {
        printf("OPCAO invalida!\n");
        return;
    }

    for (aux; aux != NULL; aux = aux->seguinte)
    {
        res++;
    }

    info.ID = res + 1;

    inserirUtilizador(iniLista, fimLista, info);
    gravarUtilizador((*iniLista), info);
}

void gravarUtilizador(ELEM_UTILIZADOR *iniLista, UTILIZADOR info)
{
    ELEM_UTILIZADOR *aux = NULL;
    FILE *fp = NULL;

    fp = fopen("files\\users.txt", "a"); // a - acrescenta ao ficheiro users.txt

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }

    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        fprintf(fp, "%d %s %s %s %s %i %i\n",
                aux->info.ID,
                aux->info.username,
                aux->info.nome,
                aux->info.password,
                aux->info.tipo,
                aux->info.tipoID,
                aux->info.rank);
    }
    fclose(fp);
}

void inserirUtilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista, UTILIZADOR info)
{
    ELEM_UTILIZADOR *novo = NULL;

    novo = (ELEM_UTILIZADOR *)calloc(1, sizeof(ELEM_UTILIZADOR));
    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (UTILIZADOR)
    if (novo == NULL)
    {
        printf("FALTA de memória!\n");
        return;
    }

    novo->info = info; // Atribuição do utilizador recebido
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

int verifiqueUsername(ELEM_UTILIZADOR *iniLista, char username[])
{
    ELEM_UTILIZADOR *aux = NULL;

    if (iniLista == NULL)
    {
        printf("Lista vazia\n");
        return 0;
    }

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

void carregarUser(ELEM_UTILIZADOR *iniLista, UTILIZADOR info)
{
    ELEM_UTILIZADOR *aux = NULL;
    int res = 0;

    FILE *fp = NULL;

    fp = fopen("files\\users.txt", "r"); // r - apenas lê do ficheiro

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }

    // Percorre e lê o ficheiro users.txt
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        fscanf(fp, "%d %s %s %s %s %i %i",
               aux->info.ID,
               aux->info.username,
               aux->info.nome,
               aux->info.password,
               aux->info.tipo,
               aux->info.tipoID,
               aux->info.rank);
        res++;
    }

    printf("Foram lidos %i com sucesso!\n", res);

    fclose(fp);
}