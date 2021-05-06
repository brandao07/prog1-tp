/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: csv.c
 ** Ficheiro C responsável por todas as operações com a informação recebida do ficheiro CSV
\*******************************************************************************************/

void recebeCSV(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, char ficheiroCSV[])
{
    // Variáveis necessárias para operar com o ficheiro csv
    PRIORIDADE info;
    char tamanhoCSV[100], prioridade[50], *ptr = NULL, *token = NULL;
    int montanteInferior, montanteSuperior;
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
        info = criarPrioridade(prioridade, montanteInferior, montanteSuperior);
        inserePrioridade(&iniLista, &fimLista, info);
    }
}

PRIORIDADE criarPrioridade(char prioridade[], int montanteInferior, int montanteSuperior)
{
    PRIORIDADE info;
    /* 
    TODO: ATRIBUIR VALOR AS VARIAVEIS
    */
    return info;
}

void inserePrioridade(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, PRIORIDADE info)
{
    ELEM_PRIORIDADE *novo = NULL;

    novo = (ELEM_PRIORIDADE *)calloc(1, sizeof(ELEM_PRIORIDADE));

    if (novo == NULL)
    {
        printf("ERRO falta de memória!");
        return;
    }

    novo->info = info;
    novo->anterior = NULL;
    novo->seguinte = NULL;

    if (*fimLista == NULL)
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