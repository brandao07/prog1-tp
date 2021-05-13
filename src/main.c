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
    int opcao;
    do
    {
        opcao = menu_inicial();
        switch (opcao)
        {
        case 0:
            exit(0);
            break;
        case 1:
            //verifica_primeiro (iniListaUTILIZADOR, fimListaUTILIZADOR, utilizador);
            do{ // Aqui wwewewewwewewe
                switch (menu_entrar())
                {
                case 0:
                    exit(0);
                    break;
                case 1:
                    do{
                        switch (menu_admin())
                        {
                            case 0:
                                exit(0);
                                break;
                            case 1:
                                utilizador = criar_utilizador(iniListaUTILIZADOR);
                                inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, utilizador);
                                gravar_utilizador(iniListaUTILIZADOR);
                                break;
                            default:
                                break;
                            case 2:
                                break;
                            case 3:
                                opcao=2;
                                break;
                        }
                    } while (opcao==2);
                    default:
                    break;   
                case 2:
                    switch (menu_analista())
                    {
                    case 0:
                        exit(0);
                        break;

                    default:
                        break;
                    
                    case 2:
                        break;
                    case 3: // case para entrar no menu entrar
                        opcao=2;
                        break;
                    }
                    break;
                case 3: // case para voltar para o menu inicial
                    opcao = 2;
                    break;
                }
            }while (opcao==2);
            default:
            break;
        }
    } while (opcao == 2);
    return 0;
}