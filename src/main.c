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
int main(int argc, char const *argv[]) //TODO
{
    ELEM_UTILIZADOR *iniListaUTILIZADOR = NULL, *fimListaUTILIZADOR = NULL;
    ELEM_CREDITO *iniListaCREDITO = NULL, *fimListaCREDITO = NULL;
    ELEM_PRIORIDADE *iniListaPRIORIDADE = NULL, *fimListaPRIORIDADE = NULL;
    QUEUES *iniQueue = NULL;
    UTILIZADOR sessao, utilizador; // sessao = para o programa saber quem é que está com a sessão iniciada
    CREDITO credito;
    int id;
    int opcao[6]; //MENU INICIAL 0 MENU ENTRAR 1 MENU ADMIN 2 MENU ANALISTA 3 MENU ALTERA 4 MENU LISTAR 5
    char ficheiroCSV[100];

    // Teste para ver se os parâmetros introduzidos na linha de comandos foram lidos com sucesso pelo programa
    if (argc < 2)
    {
        printf("Programa sem ficheiro CSV!\n\n");
        carrega_priridades(&iniListaPRIORIDADE, &fimListaPRIORIDADE);//? Ver se esta ready to go
    }
    else
    {
        strcpy(ficheiroCSV, argv[1]);                                                 // Atribuição do nome do ficheiro csv
        recebe_csv(&iniQueue, &iniListaPRIORIDADE, &fimListaPRIORIDADE, ficheiroCSV); // Carrega para o programa toda a informação do ficheiro csvS
        printf("Ficheiro CSV carregado com sucesso!\n\n");
    }

    //carregar_queues(&iniQueue);
    carregar_credito(&iniListaCREDITO, &fimListaCREDITO);
    do
    {
        opcao[MENU_INICIAL] = menu_inicial();
        switch (opcao[MENU_INICIAL])
        {
        case 0:
            opcao[MENU_INICIAL] = 3;
            break;
        case 1:
            if (carregar_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR) == -1)
            {
                utilizador = criar_utilizador(iniListaUTILIZADOR);
                inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, &utilizador);
            }
            do
            {
                opcao[MENU_ENTRAR] = menu_entrar();
                switch (opcao[MENU_ENTRAR])
                {
                case 0:
                    gravar_credito(iniListaCREDITO);
                    gravar_utilizador(iniListaUTILIZADOR);
                    gravar_queues(iniQueue);
                    gravar_prioridade(iniListaPRIORIDADE);
                    return 0;
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
                                gravar_credito(iniListaCREDITO);
                                gravar_utilizador(iniListaUTILIZADOR);
                                gravar_queues(iniQueue);
                                gravar_prioridade(iniListaPRIORIDADE);
                                return 0;
                            case 1: //Inserir utilizador
                                utilizador = criar_utilizador(iniListaUTILIZADOR);
                                inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, &utilizador);
                                break;
                            case 2: //Remover utilizador
                                remove_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR);
                                break;
                            case 3: //Inserir proposta de credito
                                credito = criar_credito(iniListaPRIORIDADE);
                                enqueue_credito(&iniQueue, credito);
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
                                    case 0: //Sair
                                        gravar_credito(iniListaCREDITO);
                                        gravar_utilizador(iniListaUTILIZADOR);
                                        gravar_queues(iniQueue);
                                        gravar_prioridade(iniListaPRIORIDADE);
                                        return 0;
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
                                } while (opcao[MENU_ALTERA] == -1 || (opcao[MENU_ALTERA] > 0 && opcao[MENU_ALTERA] < 7));
                                break;
                            case 5: //Apagar proposta de credito
                                apagar_credito(&iniListaCREDITO, &fimListaCREDITO);
                                break;
                            case 6: //Pesquisa proposta de credito
                                pesquisar_credito(iniListaCREDITO);
                                break;
                            case 7:
                                //? FALTA JUSTIFICAÇÂO MONTANTE
                                break;
                            case 8: //Menu Listagens
                                do
                                {
                                    opcao[MENU_LISTAR] = menu_listar();
                                    switch (opcao[MENU_LISTAR])
                                    {
                                    case 0: //Sair
                                        gravar_credito(iniListaCREDITO);
                                        gravar_utilizador(iniListaUTILIZADOR);
                                        gravar_queues(iniQueue);
                                        gravar_prioridade(iniListaPRIORIDADE);
                                        return 0;
                                    case 1: //Listar proposta de credito por analisar
                                        listar_por_analisar(iniQueue);
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
                                        bubbleSort_listas_credito(iniListaCREDITO);
                                        break;
                                    case 6: //Listar os analistas por ordem decrescente do rank
                                        bubbleSort_rank(iniListaUTILIZADOR);
                                        break;
                                    case 7: //Voltar ao menu anterior
                                        opcao[MENU_LISTAR] = 8;
                                        break;
                                    default:
                                        printf("OPCAO invalida!\n");
                                        opcao[MENU_LISTAR] = -1;
                                        break;
                                    }
                                } while (opcao[MENU_LISTAR] == -1 || (opcao[MENU_LISTAR] > 0 && opcao[MENU_LISTAR] < 7));
                                break;
                            case 9: //Voltar
                                opcao[MENU_ADMIN] = 10;
                                break;
                            default:
                                printf("OPCAO invalida!\n");
                                opcao[MENU_ADMIN] = -1;
                                break;
                            }
                        } while (opcao[MENU_ADMIN] == -1 || (opcao[MENU_ADMIN] > 0 && opcao[MENU_ADMIN] < 9));
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
                            case 0: //Sair
                                gravar_credito(iniListaCREDITO);
                                gravar_utilizador(iniListaUTILIZADOR);
                                gravar_queues(iniQueue);
                                gravar_prioridade(iniListaPRIORIDADE);
                                return 0;
                            case 1: //Analisar proposta de credito
                                insere_propcredito(iniListaPRIORIDADE, &iniListaCREDITO, &fimListaCREDITO, &iniQueue, &iniListaUTILIZADOR, sessao);
                                gravar_credito(iniListaCREDITO);
                                break;
                            case 2:
                                opcao[MENU_ANALISTA] = 3;
                                break;
                            default:
                                printf("OPCAO invalida!\n");
                                opcao[MENU_ANALISTA] = -1;
                                break;
                            }
                        } while (opcao[MENU_ANALISTA] == -1 || (opcao[MENU_ANALISTA] > 0 && opcao[MENU_ANALISTA] < 2));
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

    gravar_credito(iniListaCREDITO);
    gravar_utilizador(iniListaUTILIZADOR);
    gravar_queues(iniQueue);
    gravar_prioridade(iniListaPRIORIDADE);

    return 0;
}