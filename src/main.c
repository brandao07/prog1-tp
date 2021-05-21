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
    QUEUE_CREDITO *iniQueueCREDITO = NULL, *fimQueueCREDITO = NULL;
    UTILIZADOR sessao, utilizador; // sessao = para o programa saber quem é que está com a sessão iniciada
    CREDITO credito;
    int id;
    // Teste para ver se os parâmetros introduzidos na linha de comandos foram lidos com sucesso pelo programa
    if (argc < 2)
    {
        printf("FALTAM argumentos para iniciar o programa.\n");
        return;
    }
    char ficheiroCSV[100];
    // Atribuição do nome do ficheiro csv
    strcpy(ficheiroCSV, argv[1]);
    recebe_csv(&iniListaPRIORIDADE, &fimListaPRIORIDADE, ficheiroCSV); // Carrega para o programa toda a informação do ficheiro csv
    int opcao[6];                                                      //MENU INICIAL 0 MENU ENTRAR 1 MENU ADMIN 2 MENU ANALISTA 3 MENU ALTERA 4 MENU LISTAR 5
    do
    {
        opcao[MENU_INICIAL] = menu_inicial();
        switch (opcao[MENU_INICIAL])
        {
        case 0:
            exit(0);
            break;
        case 1:
            //verifica_primeiro(&iniListaUTILIZADOR, &fimListaUTILIZADOR);
            if (carregar_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR) == -1)
            {
                utilizador = criar_utilizador(iniListaUTILIZADOR);
                inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, &utilizador);
                gravar_utilizador(iniListaUTILIZADOR);
            }
            do
            {
                opcao[MENU_ENTRAR] = menu_entrar();
                switch (opcao[MENU_ENTRAR])
                {
                case 0:
                    exit(0);
                    break;
                case 1:
                    sessao = login_utilizador(&iniListaUTILIZADOR);
                    if (sessao.tipoID == 4)
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
                                inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, &utilizador);
                                gravar_utilizador(iniListaUTILIZADOR);
                                break;

                            case 2: //Remover utilizador
                                remove_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR);
                                break;

                            case 3: //Inserir proposta de credito
                                credito = criar_credito(iniListaPRIORIDADE);
                                enqueue_credito(&iniQueueCREDITO, &fimQueueCREDITO, credito);
                                gravar_queue(iniQueueCREDITO);
                                break;

                            case 4: //Alterar proposta de credito
                                printf("\nInsira o ID: ");
                                fflush(stdin);
                                scanf("%d", &id);

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
                                        altera_montante(&iniListaCREDITO, id);
                                        break;

                                    case 6: //Alterar erro na analise
                                        altera_garantias(&iniListaCREDITO, id);
                                        break;

                                    case 7: //Voltar ao menu anterior
                                        opcao[MENU_ALTERA] = 8;
                                        break;

                                    default:
                                        printf("OPCAO invalida!\n");
                                        opcao[MENU_ALTERA] = -1;
                                        break;
                                    }
                                    //? FALTA GRAVAR NO FICHEIRO
                                } while (opcao[MENU_ALTERA] == -1 || (opcao[MENU_ALTERA] > 0 && opcao[MENU_ALTERA] < 7));
                                break;

                            case 5: //Apagar proposta de credito
                                apagar_credito(&iniListaCREDITO, &fimListaCREDITO);
                                break;

                            case 6: //Pesquisa proposta de credito
                                //? Fiz apenas a listagem por NOME é o que pede naquelas listagens
                                //* Podem ter varaias proposta com o mesmo nome temos de ver se a funcao resulta
                                pesquisar_credito(iniListaCREDITO);
                                break;

                            case 7: //Menu Listagens
                                do
                                {
                                    opcao[MENU_LISTAR] = menu_listar();
                                    switch (opcao[MENU_LISTAR])
                                    {
                                    case 0: //sair
                                        exit(0);
                                        break;

                                    case 1: //Listar proposta de credito por analisar
                                        listar_por_analisar(iniQueueCREDITO);
                                        break;

                                    case 2: //Listar proposta de credito analisada
                                        listar_analisadas(iniListaCREDITO);
                                        break;

                                    case 3: //Listar proposta de credito por uma determinada prioridade
                                        listar_prioridade(iniListaCREDITO);
                                        break;

                                    case 4: //Listar proposta de credito acima de um determinado montante
                                        listar_acima_montante(iniListaCREDITO);
                                        break;

                                    case 5: //Listar proposta de credito analisada por um determinado utilizador
                                        listar_todas_ordenadas(iniListaCREDITO);
                                        break;

                                    case 6: //Voltar ao menu anterior
                                        opcao[MENU_LISTAR] = 7;
                                        break;

                                    default:
                                        printf("OPCAO invalida!\n");
                                        opcao[MENU_LISTAR] = -1;
                                        break;
                                    }

                                } while (opcao[MENU_LISTAR] = -1 || (opcao[MENU_LISTAR] > 0 && opcao[MENU_LISTAR] < 6));
                                break;

                            case 8: //Voltar
                                opcao[MENU_ADMIN] = 9;
                                break;
                            default:
                                printf("OPCAO invalida!\n");
                                opcao[MENU_ADMIN] = -1;
                                break;
                            }
                        } while (opcao[MENU_ADMIN] == -1 || (opcao[MENU_ADMIN] > 0 && opcao[MENU_ADMIN] < 8));
                    }
                    break;

                case 2:
                    sessao = login_utilizador(&iniListaUTILIZADOR);
                    if (sessao.tipoID == 5)
                    {
                        do
                        {
                            opcao[MENU_ANALISTA] = menu_analista();
                            switch (opcao[MENU_ANALISTA])
                            {
                            case 0:
                                exit(0);
                                break;

                            case 1: //Analisar proposta de credito
                                insere_credito(&iniListaCREDITO, &fimListaCREDITO, &iniQueueCREDITO, &fimQueueCREDITO, &iniListaUTILIZADOR, sessao);
                                break;

                            case 2: //? Array de lista
                                //...
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
            break;
        case 2:
            ajuda();
            break;
        default:
            break;
        }
    } while (opcao[MENU_INICIAL] == 1 || opcao[MENU_INICIAL] == 2);
    return 0;
}