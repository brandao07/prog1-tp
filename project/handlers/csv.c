/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: csv.c
 ** Ficheiro C responsável por todas as operações com a informação recebida do ficheiro CSV
\*******************************************************************************************/

void recebeCSV(char ficheiroCSV[])
{
    // Variáveis necessárias para operar com o ficheiro csv
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
        //criarPrioridade(prioridade,montanteInferior,montanteSuperior);
    }
}