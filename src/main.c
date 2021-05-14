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
    int opcao_inicial, opcao_entrar, opcao_admin, opcao_analista;
    do
    {
        opcao_inicial = menu_inicial();
        switch (opcao_inicial)
        {
        case 0:
            exit(0);
            break;
        case 1:
            verifica_primeiro(iniListaUTILIZADOR, fimListaUTILIZADOR, utilizador);
            do
            {
                opcao_entrar = menu_entrar();
                switch (opcao_entrar)
                {
                case 0:
                    exit(0);
                    break;
                case 1:
                    do
                    {
                        opcao_admin = menu_admin();
                        switch (opcao_admin)
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
                            opcao_admin = 4;
                            break;
                        default:
                            printf("OPCAO invalida!\n");
                            opcao_admin = -1;
                            break;
                        }
                    } while (opcao_admin == -1 || (opcao_admin > 0 && opcao_admin < 3));
                    break;

                case 2:
                    do
                    {
                        opcao_analista = menu_analista();
                        switch (opcao_analista)
                        {
                        case 0:
                            exit(0);
                            break;

                        case 1:
                            break;

                        case 2:
                            break;
                        case 3:
                            opcao_analista = 4;
                            break;

                        default:
                            printf("OPCAO invalida!\n");
                            opcao_analista = -1;
                            break;
                        }
                    } while (opcao_analista == -1 || (opcao_analista > 0 && opcao_analista < 3));
                    break;
                case 3:
                    opcao_entrar = 4;
                    break;
                default:
                    printf("OPCAO invalida!\n");
                    opcao_entrar = -1;
                    break;
                }
            } while (opcao_entrar == -1 || (opcao_entrar > 0 && opcao_entrar < 3));
        default:
            break;
        }
    } while (opcao_inicial == 1);
    return 0;
}