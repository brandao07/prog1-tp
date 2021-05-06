/*************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: main.c
 ** Data: 28-05-2021 (DD-MM-YYYY)
 ** requer ficheiro do tipo csv (ppp;mmI;mmS)
\*************************************************************/

//! HEADER
#include "handlers\headers.h"

//! HANDLERS
#include "handlers\csv.c"

//! MAIN
int main(int argc, char const *argv[])
{
    // Teste para ver se os parâmetros introduzidos na linha de comandos foram lidos com sucesso pelo programa
    if (argc < 2)
    {
        printf("FALTAM argumentos para iniciar o programa.\n");
        return -1;
    }
    // Inicializa os apontadores das estruturas das listas (UTILIZADOR CREDITO PRIORIDADE)
    ELEM_UTILIZADOR *iniListaUTILIZADOR = NULL, *fimListaUTILIZADOR = NULL;
    ELEM_CREDITO *iniListaCREDITO = NULL, *fimListaCREDITO = NULL;
    ELEM_PRIORIDADE *iniListaPRIORIDADE = NULL, *fimListaPRIORIDADE = NULL;

    char ficheiroCSV[100];
    strcpy(ficheiroCSV, argv[1]);                                     // Atribuição do nome do ficheiro  csv
    recebeCSV(&iniListaPRIORIDADE, &fimListaPRIORIDADE, ficheiroCSV); // Carrega para o programa toda a informação do ficheiro csv

    return 0;
}
