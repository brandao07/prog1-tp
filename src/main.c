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
int main(int argc, char const *argv[]) //TODO FREE DE TODAS LISTAS
{
    ELEM_UTILIZADOR *iniListaUTILIZADOR = NULL, *fimListaUTILIZADOR = NULL;
    ELEM_CREDITO *iniListaCREDITO = NULL, *fimListaCREDITO = NULL;
    ELEM_PRIORIDADE *iniListaPRIORIDADE = NULL, *fimListaPRIORIDADE = NULL;
    QUEUES *iniQueue = NULL;
    UTILIZADOR sessao, utilizador; // sessao = para o programa saber quem é que está com a sessão iniciada
    CREDITO credito;
    int id;
    int opcao[9]; //MENU INICIAL 0 MENU ENTRAR 1 MENU ADMIN 2 MENU ANALISTA 3 MENU ALTERA 4 MENU LISTAR 5
    char ficheiroCSV[100];

    // Teste para ver se os parâmetros introduzidos na linha de comandos foram lidos com sucesso pelo programa
    if (argc < 2)
    {
        printf("Programa sem ficheiro CSV!\n\n");
        carrega_prioridades(&iniQueue, &iniListaPRIORIDADE, &fimListaPRIORIDADE);
    }
    else
    {
        strcpy(ficheiroCSV, argv[1]);                                                 // Atribuição do nome do ficheiro csv
        recebe_csv(&iniQueue, &iniListaPRIORIDADE, &fimListaPRIORIDADE, ficheiroCSV); // Carrega para o programa toda a informação do ficheiro csvS
        printf("Ficheiro CSV carregado com sucesso!\n\n");
    }

    carregar_queues(&iniQueue);
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
                    gravar_prioridades(iniListaPRIORIDADE);
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
                                gravar_prioridades(iniListaPRIORIDADE);
                                return 0;
                            case 1: //CRUD menu utilizador
                                do
                                {
                                    opcao[CRUD_UTILIZADOR] = CRUD_utilizador();
                                    switch (opcao[CRUD_UTILIZADOR])
                                    {
                                    case 0: //Sair
                                        gravar_credito(iniListaCREDITO);
                                        gravar_utilizador(iniListaUTILIZADOR);
                                        gravar_queues(iniQueue);
                                        gravar_prioridades(iniListaPRIORIDADE);
                                        return 0;
                                        break;

                                    case 1: //Inserir utilizador
                                        utilizador = criar_utilizador(iniListaUTILIZADOR);
                                        inserir_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, &utilizador);
                                        break;
                                    case 2: //Remover utilizador
                                        remove_utilizador(&iniListaUTILIZADOR, &fimListaUTILIZADOR, sessao);
                                        break;
                                    case 3: //Menu alterar
                                        printf("\nInsira o ID: ");
                                        fflush(stdin);
                                        scanf("%d", &id);
                                        do
                                        {
                                            opcao[MENU_ALETRA_UTILIZADOR] = menu_altera_utilizador();
                                            switch (opcao[MENU_ALETRA_UTILIZADOR])
                                            {
                                            case 0: //Sair
                                                gravar_credito(iniListaCREDITO);
                                                gravar_utilizador(iniListaUTILIZADOR);
                                                gravar_queues(iniQueue);
                                                gravar_prioridades(iniListaPRIORIDADE);
                                                return 0;
                                                break;
                                            case 1: //Alterar nome
                                                altera_nome_utilizador(&iniListaUTILIZADOR, id);
                                                break;
                                            case 2: //Alterar username
                                                altera_username_utilizador(&iniListaUTILIZADOR, id);
                                                break;
                                            case 3: //Alterar password
                                                altera_password_utilizador(&iniListaUTILIZADOR, id);
                                                break;
                                            case 4: //Alterar tipo
                                                altera_tipo_utilizador(&iniListaUTILIZADOR, id);
                                                break;
                                            case 5: //Voltar ao menu anterior
                                                opcao[MENU_ALETRA_UTILIZADOR] = 6;
                                                break;
                                            default:
                                                printf("OPCAO invalida!\n");
                                                opcao[MENU_ALETRA_UTILIZADOR] = -1;
                                                break;
                                            }
                                        } while (opcao[MENU_ALETRA_UTILIZADOR] == -1 || (opcao[MENU_ALETRA_UTILIZADOR] > 0 && opcao[MENU_ALETRA_UTILIZADOR] < 5));
                                        break;
                                    case 4: //Voltar ao menu anterior
                                        opcao[CRUD_UTILIZADOR] = 5;
                                        break;
                                    default:
                                        printf("OPCAO invalida!\n");
                                        opcao[CRUD_UTILIZADOR] = -1;
                                        break;
                                    }
                                } while (opcao[CRUD_UTILIZADOR] == -1 || (opcao[CRUD_UTILIZADOR] > 0 && opcao[CRUD_UTILIZADOR] < 4));
                                break;

                            case 2: //CRUD propostas de credito
                                do
                                {
                                    opcao[CRUD_PROP_CREDITO] = CRUD_prop_credito();
                                    switch (opcao[CRUD_PROP_CREDITO])
                                    {
                                    case 0: //Sair
                                        gravar_credito(iniListaCREDITO);
                                        gravar_utilizador(iniListaUTILIZADOR);
                                        gravar_queues(iniQueue);
                                        gravar_prioridades(iniListaPRIORIDADE);
                                        return 0;
                                        break;
                                    case 1: //Inserir proposta de credito
                                        credito = criar_credito(iniListaCREDITO, iniQueue, iniListaPRIORIDADE);
                                        enqueue_credito(&iniQueue, credito);
                                        break;
                                    case 2: //Alterar proposta de credito
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
                                                gravar_prioridades(iniListaPRIORIDADE);
                                                return 0;
                                            case 1: //Alterar o nome
                                                altera_nome(&iniListaCREDITO, id);
                                                break;
                                            case 2: //Alterar o IBAN
                                                altera_iban(&iniListaCREDITO, id);
                                                break;
                                            case 3: //Aletrar as garantias
                                                altera_garantias(&iniListaCREDITO, id);
                                                break;
                                            case 4: //Alterar o montante
                                                altera_montante(iniListaPRIORIDADE, &iniListaCREDITO, id);
                                                break;
                                            case 5: //Alterar erro na analise
                                                corrigir_erro_analise(&iniListaCREDITO, id);
                                                break;
                                            case 6: //Voltar ao menu anterior
                                                opcao[MENU_ALTERA] = 7;
                                                break;
                                            default:
                                                printf("OPCAO invalida!\n");
                                                opcao[MENU_ALTERA] = -1;
                                                break;
                                            }
                                        } while (opcao[MENU_ALTERA] == -1 || (opcao[MENU_ALTERA] > 0 && opcao[MENU_ALTERA] < 6));
                                        break;
                                    case 3: //Apagar proposta de credito
                                        apagar_credito(&iniListaCREDITO, &fimListaCREDITO);
                                        break;
                                    case 4: //Pesquisa proposta de credito
                                        pesquisar_credito(iniListaCREDITO);
                                        break;
                                    case 5: //Voltar ao menu anterior
                                        opcao[CRUD_PROP_CREDITO] = 6;
                                        break;
                                    default:
                                        printf("OPCAO invalida!\n");
                                        opcao[CRUD_PROP_CREDITO] = -1;
                                        break;
                                    }
                                } while (opcao[CRUD_PROP_CREDITO] == -1 || (opcao[CRUD_PROP_CREDITO] > 0 && opcao[CRUD_PROP_CREDITO] < 5));
                                break;
                            case 3: //Relatório para propostas de crédito
                                relatorio_proposta(iniListaCREDITO);
                                break;
                            case 4: //Menu Listagens
                                do
                                {
                                    opcao[MENU_LISTAR] = menu_listar();
                                    switch (opcao[MENU_LISTAR])
                                    {
                                    case 0: //Sair
                                        gravar_credito(iniListaCREDITO);
                                        gravar_utilizador(iniListaUTILIZADOR);
                                        gravar_queues(iniQueue);
                                        gravar_prioridades(iniListaPRIORIDADE);
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
                                        listar_ranking(iniListaUTILIZADOR);
                                        break;
                                    case 7:
                                        printf("\nInsira o tipo do utilizador(4 - ADMINISTRADOR / 5 - ANALISTA): ");
                                        fflush(stdin);
                                        scanf("%d", &id);
                                        listar_utilizadores(iniListaUTILIZADOR, id);
                                        break;
                                    case 8: //Voltar ao menu anterior
                                        opcao[MENU_LISTAR] = 9;
                                        break;
                                    default:
                                        printf("OPCAO invalida!\n");
                                        opcao[MENU_LISTAR] = -1;
                                        break;
                                    }
                                } while (opcao[MENU_LISTAR] == -1 || (opcao[MENU_LISTAR] > 0 && opcao[MENU_LISTAR] < 8));
                                break;
                            case 5: //Voltar
                                opcao[MENU_ADMIN] = 6;
                                break;
                            default:
                                printf("OPCAO invalida!\n");
                                opcao[MENU_ADMIN] = -1;
                                break;
                            }
                        } while (opcao[MENU_ADMIN] == -1 || (opcao[MENU_ADMIN] > 0 && opcao[MENU_ADMIN] < 5));
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
                                gravar_prioridades(iniListaPRIORIDADE);
                                return 0;
                            case 1: //Analisar proposta de credito
                                if (insere_propcredito(&iniListaCREDITO, &fimListaCREDITO, &iniQueue, &iniListaUTILIZADOR, sessao) == 0)
                                {
                                    printf("Proposta de credito introduzida com sucesso!\n");
                                }
                                else
                                {
                                    printf("ERRO ao introduzir proposta de credito!\n");
                                }
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
    gravar_prioridades(iniListaPRIORIDADE);

    return 0;
}