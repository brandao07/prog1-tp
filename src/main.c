/*************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: main.c
 ** Data: 28-05-2021 (DD-MM-YYYY)
 ** requer ficheiro do tipo csv (ppp;mmI;mmS)
\*************************************************************/

//! HEADER
#include "headers.h"

//! MAIN
int main(int argc, char const *argv[])
{
    ELEM_UTILIZADOR *iniListaUTILIZADOR = NULL, *fimListaUTILIZADOR = NULL;
    ELEM_CREDITO *iniListaCREDITO = NULL, *fimListaCREDITO = NULL;
    ELEM_PRIORIDADE *iniListaPRIORIDADE = NULL, *fimListaPRIORIDADE = NULL;

    UTILIZADOR utilizador;
    // Teste para ver se os parâmetros introduzidos na linha de comandos foram lidos com sucesso pelo programa
    if (argc < 2)
    {
        printf("FALTAM argumentos para iniciar o programa.\n");
        return -1;
    }
    char ficheiroCSV[100];
    // Atribuição do nome do ficheiro csv
    strcpy(ficheiroCSV, argv[1]);
    recebe_csv(&iniListaPRIORIDADE, &fimListaPRIORIDADE, ficheiroCSV); // Carrega para o programa toda a informação do ficheiro csv
    int opcao[4]; //MENU INICIAL 0 MENU ENTRAR 1 MENU ADMIN 2 MENU ANALISTA 3
    do
    {
        opcao[MENU_INICIAL] = menu_inicial();
        switch (opcao[MENU_INICIAL])
        {
        case 0:
            exit(0);
            break;
        case 1:
            verifica_primeiro(iniListaUTILIZADOR, fimListaUTILIZADOR, utilizador);
            do
            {
                opcao[MENU_ENTRAR] = menu_entrar();
                switch (opcao[MENU_ENTRAR])
                {
                case 0:
                    exit(0);
                    break;
                case 1:
                    do
                    {
                        opcao[MENU_ADMIN] = menu_admin();
                        switch (opcao[MENU_ADMIN])
                        {
                        case 0:
                            exit(0);
                            break;
                        case 1:
                            utilizador = criar_utilizador(iniListaUTILIZADOR);
                            inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, utilizador);
                            gravar_utilizador(iniListaUTILIZADOR);
                            break;
                        case 2:
                            break;
                        case 3:
                            opcao[MENU_ADMIN] = 4;
                            break;
                        default:
                            printf("OPCAO invalida!\n");
                            opcao[MENU_ADMIN] = -1;
                            break;
                        }
                    } while (opcao[MENU_ADMIN] == -1 || (opcao[MENU_ADMIN] > 0 && opcao[MENU_ADMIN] < 3));
                    break;

                case 2:
                    do
                    {
                        opcao[MENU_ANALISTA] = menu_analista();
                        switch (opcao[MENU_ANALISTA])
                        {
                        case 0:
                            exit(0);
                            break;

                        case 1:
                            break;

                        case 2:
                            break;
                        case 3:
                            opcao[MENU_ANALISTA] = 4;
                            break;

                        default:
                            printf("OPCAO invalida!\n");
                            opcao[MENU_ANALISTA] = -1;
                            break;
                        }
                    } while (opcao[MENU_ANALISTA] == -1 || (opcao[MENU_ANALISTA] > 0 && opcao[MENU_ANALISTA] < 3));
                    break;
                case 3:
                    opcao[MENU_ENTRAR] = 4;
                    break;
                default:
                    printf("OPCAO invalida!\n");
                    opcao[MENU_ENTRAR] = -1;
                    break;
                }
            } while (opcao[MENU_ENTRAR] == -1 || (opcao[MENU_ENTRAR] > 0 && opcao[MENU_ENTRAR] < 3));
        default:
            break;
        }
    } while (opcao[MENU_INICIAL] == 1);
    return 0;
}