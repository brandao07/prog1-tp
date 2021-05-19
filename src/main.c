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
    ELEM_CREDITO *iniListaCREDITO = NULL;
    ELEM_CREDITO *fimListaCREDITO = NULL;
    ELEM_PRIORIDADE *iniListaPRIORIDADE = NULL, *fimListaPRIORIDADE = NULL;
    UTILIZADOR utilizador;
    int id;
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
    int opcao[5];                                                      //MENU INICIAL 0 MENU ENTRAR 1 MENU ADMIN 2 MENU ANALISTA 3
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
                    login_utilizador(iniListaUTILIZADOR);
                    if (login_utilizador == 0)
                    {
                        do
                        {
                            opcao[MENU_ADMIN] = menu_admin();
                            switch (opcao[MENU_ADMIN])
                            {
                            case 0: //Sair
                                exit(0);
                                break;
                            case 1: //Inserir utilizador
                                utilizador = criar_utilizador(iniListaUTILIZADOR);
                                inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, utilizador);
                                gravar_utilizador(iniListaUTILIZADOR);
                                break;

                            case 2: //Remover utilizador
                                remove_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR);
                                break;

                            case 3: //Inserir proposta de credito
                                inserir_credito(iniListaCREDITO);
                                break;

                            case 4: //Alterar proposta de credito
                                printf("Insira o ID: ");
                                fflush(stdin);
                                scanf("%d", id);

                                do
                                {
                                    opcao[MENU_ALTERA] = menu_altera();
                                    switch (opcao[MENU_ALTERA])
                                    {
                                    case 0: // sair
                                        exit(0);
                                        break;

                                    case 1: //Alterar o nome
                                        altera_nome(&iniListaCREDITO, id);
                                        break;

                                    case 2: //Alterar o IBAN
                                        break;
                                        altera_iban(&iniListaCREDITO, id);
                                    case 3: //Alterar o numero de garantias
                                        altera_numero_garantias(&iniListaCREDITO, id);
                                        break;

                                    case 4: //Aletrar as garantias
                                        altera_garantias(&iniListaCREDITO, id);
                                        break;

                                    case 5: //Alterar o montante
                                        altera_montante(iniListaCREDITO, id);
                                        break;

                                    case 6: //Alterar erro na analise

                                        break;

                                    case 7: //Voltar ao menu anterior
                                        opcao[MENU_ALTERA] = 8;
                                        break;

                                    default:

                                        printf("OPCAO invalida!\n");
                                        opcao[MENU_ALTERA] = -1;
                                        break;
                                    }
                                    //! FALTA GRAVAR NO FICHEIRO
                                } while (opcao[MENU_ALTERA] == -1 || (opcao[MENU_ALTERA] > 0 && opcao[MENU_ALTERA] < 7));
                                break;

                            case 5: //Apagar proposta de credito
                                break;

                            case 6: //Pesquisa proposta de credito
                                break;
                            case 7: //Voltar
                                opcao[MENU_ADMIN] = 8;
                                break;
                            default:
                                printf("OPCAO invalida!\n");
                                opcao[MENU_ADMIN] = -1;
                                break;
                            }
                        } while (opcao[MENU_ADMIN] == -1 || (opcao[MENU_ADMIN] > 0 && opcao[MENU_ADMIN] < 7));
                    }
                    break;

                case 2:
                    login_utilizador(iniListaUTILIZADOR);
                    if (login_utilizador == 0)
                    {
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
                    }
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