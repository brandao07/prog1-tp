/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: credito.c
 ** Ficheiro C responsável por todas as operações relacionadas com as propostas de crédito
\***********************************************************************************************/

//! HEADER
#include "headers.h"

CREDITO inserir_credito(ELEM_PRIORIDADE *iniLista)
{
    CREDITO info;
    int garantiaOpcao;
    printf("Introduza identificador:\n");
    fflush(stdin);
    scanf("%d",info.ID);
    printf("Introduza nome:\n");
    fflush(stdin);
    scanf("%[^\n]", info.nome);
    printf("Introduza IBAN:\n");
    fflush(stdin);
    scanf("%s", info.IBAN);
    printf("Quantas garantias?\n");
    fflush(stdin);
    scanf("%d", &info.garantiaNumero);
    if (info.garantiaNumero > MAX_GARANTIAS)
    {
        printf("Numero maximo de garantias excedido!\n");
    }
    else
    {
        for (int i = 0; i < info.garantiaNumero; i++)
        {
            printf("Tipo de garantia?\n");
            printf("\n[0] - Imovel");
            printf("\n[1] - Fiador");
            printf("\n[2] - Depositos");
            printf("\n[3] - Produtos");
            fflush(stdin);
            scanf("%d", &garantiaOpcao);
            if (garantiaOpcao == 0)
            {
                strcpy(info.garantia[i].tipo, "Imovel");
            }
            else if (garantiaOpcao == 1)
            {
                strcpy(info.garantia[i].tipo, "Fiador");
            }
            else if (garantiaOpcao == 2)
            {
                strcpy(info.garantia[i].tipo, "Depositos");
            }
            else if (garantiaOpcao == 3)
            {
                strcpy(info.garantia[i].tipo, "Produtos");
            }
            else if (garantiaOpcao != 0 || garantiaOpcao != 1 || garantiaOpcao != 2 || garantiaOpcao || 3)
            {
                printf("OPCAO invalida!\n");
                exit(0);
            }
            printf("Descricao sobre a proposta:\n");
            fflush(stdin);
            scanf("%[^\n]", &info.garantia[i].descricao);
            printf("Valor:\n");
            fflush(stdin);
            scanf("%f", &info.garantia[i].valor);
        }
        printf("Montante:\n");
        scanf("%f", &info.montante);
        strcpy(info.prioridade, carrega_prioridade(iniLista, info.montante));
        return info;
    }
}

void imprime_credito(ELEM_CREDITO *iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for (aux = iniLista; aux != NULL; aux = aux->seguinte)
        {
            if (aux->info.ID == id)
            {
                printf("\n*------------PROPOSTA----------------*\n");
                printf("\nProposta #%d\n", aux->info.numeroSequencial);
                printf("\tNome: %s\n\tIBAN: %s\n\tMontante: %.2f\n\tPrioridade: %s\n",
                       aux->info.nome,
                       aux->info.IBAN,
                       aux->info.montante,
                       aux->info.prioridade);
                printf("Numero de garantias: %d\n", aux->info.garantiaNumero);
                printf("*--------------------------------------*\n");
                system("pause");
                for (int i = 0; i < aux->info.garantiaNumero; i++)
                {
                    printf("\n*------------GARANTIAS----------------*\n");
                    printf("\nGarantia #%i\n", i + 1);
                    printf("\tTipo:%s\n\tDescricao:%s\n\tValor:%.2f€\n",
                           aux->info.garantia[i].tipo,
                           aux->info.garantia[i].descricao,
                           aux->info.garantia[i].valor);
                    printf("*--------------------------------------*\n");
                    system("pause");
                }
                printf("\n*------------ANALISE----------------*\n");
                printf("Analise da proposta #%d\n", aux->info.numeroSequencial);
                printf("\tEstado da proposta: Analisada\n\tSituacao: %s\n\tData: %s\n",
                       aux->analise.situacao,
                       aux->analise.data);
                printf("*--------------------------------------*\n");
                system("pause");
                return;
            }
            else
            {
                printf("Proposta nao encontrada!\n");
                return;
            }
        }
    }
}

void altera_nome(ELEM_CREDITO **iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    int resposta;
    char novo[100];

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Proposta #%d\n", aux->info.numeroSequencial);
            printf("Nome atual: %s\n", aux->info.nome);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);
            if (resposta == 0)
            {
                return;
            }
            if (resposta == 1)
            {
                printf("Insira o novo nome: \n");
                fflush(stdin);
                scanf("%[^\n]", novo);

                strcpy(aux->info.nome, novo);
            }
        }
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

void altera_iban(ELEM_CREDITO **iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    int resposta;
    char novo[50];

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Proposta #%d\n", aux->info.numeroSequencial);
            printf("IBAN atual: %s\n", aux->info.IBAN);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);
            if (resposta == 0)
            {
                return;
            }
            if (resposta == 1)
            {
                printf("Insira o novo IBAN: \n");
                fflush(stdin);
                scanf("%[^\n]", novo);

                strcpy(aux->info.IBAN, novo);
            }
        }
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

void altera_numero_garantias(ELEM_CREDITO **iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    int resposta;
    int novo;

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Proposta #%d\n", aux->info.numeroSequencial);
            printf("Numero de garantias atuais: %d\n", aux->info.garantiaNumero);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);
            if (resposta == 0)
            {
                return;
            }
            if (resposta == 1)
            {
                printf("Insira o novo numero de garantias: \n");
                fflush(stdin);
                scanf("%d", novo);

                aux->info.garantiaNumero = novo;
            }
        }
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

void altera_garantias(ELEM_CREDITO **iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    ELEM_CREDITO *aux2 = NULL;
    int resposta[2];
    int opcao, garantiaOpcao;
    int novo[MAX_GARANTIAS];

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Proposta #%d\n", aux->info.numeroSequencial);
            printf("Numero de garantias atual: %d\n", aux->info.garantiaNumero);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta[0]);
            if (resposta[0] == 0)
            {
                return;
            }
            if (resposta[1] == 1)
            {
                do
                {
                    opcao = menu_altera_garantias();
                    switch (opcao)
                    {
                    case 1:
                        if (aux->info.garantiaNumero < 1)
                        {
                            printf("Esta proposta nao possui garantias!\n");
                            printf("Deseja adicionar?\n**0-NAO**\n**1-SIM**\n");
                            fflush(stdin);
                            scanf("%d", &resposta[1]);
                            if (resposta[1] == 0)
                            {
                                return;
                            }
                        }
                        printf("Tipo de garantia?\n");
                        printf("\n[0] - Imovel");
                        printf("\n[1] - Fiador");
                        printf("\n[2] - Depositos");
                        printf("\n[3] - Produtos");
                        fflush(stdin);
                        scanf("%d", &garantiaOpcao);
                        if (garantiaOpcao == 0)
                        {
                            strcpy(aux->info.garantia[0].tipo, "Imovel");
                        }
                        else if (garantiaOpcao == 1)
                        {
                            strcpy(aux->info.garantia[0].tipo, "Fiador");
                        }
                        else if (garantiaOpcao == 2)
                        {
                            strcpy(aux->info.garantia[0].tipo, "Depositos");
                        }
                        else if (garantiaOpcao == 3)
                        {
                            strcpy(aux->info.garantia[0].tipo, "Produtos");
                        }
                        else if (garantiaOpcao != 0 || garantiaOpcao != 1 || garantiaOpcao != 2 || garantiaOpcao || 3)
                        {
                            printf("OPCAO invalida!\n");
                            exit(0);
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", &(aux->info.garantia[0].descricao));
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[0].valor));
                        break;
                    case 2:
                        if (aux->info.garantiaNumero < 2)
                        {
                            printf("Esta proposta apenas possui 1 garantia!\n");
                            printf("Deseja adicionar?\n**0-NAO**\n**1-SIM**\n");
                            fflush(stdin);
                            scanf("%d", &resposta[1]);
                            if (resposta[1] == 0)
                            {
                                return;
                            }
                        }
                        printf("Tipo de garantia?\n");
                        printf("\n[0] - Imovel");
                        printf("\n[1] - Fiador");
                        printf("\n[2] - Depositos");
                        printf("\n[3] - Produtos");
                        fflush(stdin);
                        scanf("%d", &garantiaOpcao);
                        if (garantiaOpcao == 0)
                        {
                            strcpy(aux->info.garantia[1].tipo, "Imovel");
                        }
                        else if (garantiaOpcao == 1)
                        {
                            strcpy(aux->info.garantia[1].tipo, "Fiador");
                        }
                        else if (garantiaOpcao == 2)
                        {
                            strcpy(aux->info.garantia[1].tipo, "Depositos");
                        }
                        else if (garantiaOpcao == 3)
                        {
                            strcpy(aux->info.garantia[1].tipo, "Produtos");
                        }
                        else if (garantiaOpcao != 0 || garantiaOpcao != 1 || garantiaOpcao != 2 || garantiaOpcao || 3)
                        {
                            printf("OPCAO invalida!\n");
                            exit(0);
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", &(aux->info.garantia[1].descricao));
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[1].valor));
                        break;
                    case 3:
                        if (aux->info.garantiaNumero < 3)
                        {
                            printf("Esta proposta apenas possui 2 garantias!\n");
                            printf("Deseja adicionar?\n**0-NAO**\n**1-SIM**\n");
                            fflush(stdin);
                            scanf("%d", &resposta[1]);
                            if (resposta[1] == 0)
                            {
                                return;
                            }
                        }
                        printf("Tipo de garantia?\n");
                        printf("\n[0] - Imovel");
                        printf("\n[1] - Fiador");
                        printf("\n[2] - Depositos");
                        printf("\n[3] - Produtos");
                        fflush(stdin);
                        scanf("%d", &garantiaOpcao);
                        if (garantiaOpcao == 0)
                        {
                            strcpy(aux->info.garantia[2].tipo, "Imovel");
                        }
                        else if (garantiaOpcao == 1)
                        {
                            strcpy(aux->info.garantia[2].tipo, "Fiador");
                        }
                        else if (garantiaOpcao == 2)
                        {
                            strcpy(aux->info.garantia[2].tipo, "Depositos");
                        }
                        else if (garantiaOpcao == 3)
                        {
                            strcpy(aux->info.garantia[2].tipo, "Produtos");
                        }
                        else if (garantiaOpcao != 0 || garantiaOpcao != 1 || garantiaOpcao != 2 || garantiaOpcao || 3)
                        {
                            printf("OPCAO invalida!\n");
                            exit(0);
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", &(aux->info.garantia[2].descricao));
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[2].valor));
                        break;
                    case 4:
                        if (aux->info.garantiaNumero < 4)
                        {
                            printf("Esta proposta apenas possui 3 garantias!\n");
                            printf("Deseja adicionar?\n**0-NAO**\n**1-SIM**\n");
                            fflush(stdin);
                            scanf("%d", &resposta[1]);
                            if (resposta[1] == 0)
                            {
                                return;
                            }
                        }
                        printf("Tipo de garantia?\n");
                        printf("\n[0] - Imovel");
                        printf("\n[1] - Fiador");
                        printf("\n[2] - Depositos");
                        printf("\n[3] - Produtos");
                        fflush(stdin);
                        scanf("%d", &garantiaOpcao);
                        if (garantiaOpcao == 0)
                        {
                            strcpy(aux->info.garantia[3].tipo, "Imovel");
                        }
                        else if (garantiaOpcao == 1)
                        {
                            strcpy(aux->info.garantia[3].tipo, "Fiador");
                        }
                        else if (garantiaOpcao == 2)
                        {
                            strcpy(aux->info.garantia[3].tipo, "Depositos");
                        }
                        else if (garantiaOpcao == 3)
                        {
                            strcpy(aux->info.garantia[3].tipo, "Produtos");
                        }
                        else if (garantiaOpcao != 0 || garantiaOpcao != 1 || garantiaOpcao != 2 || garantiaOpcao || 3)
                        {
                            printf("OPCAO invalida!\n");
                            exit(0);
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", &(aux->info.garantia[3].descricao));
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[3].valor));
                        break;
                    case 5:
                        if (aux->info.garantiaNumero < 5)
                        {
                            printf("Esta proposta apenas possui 4 garantias!\n");
                            printf("Deseja adicionar?\n**0-NAO**\n**1-SIM**\n");
                            fflush(stdin);
                            scanf("%d", &resposta[1]);
                            if (resposta[1] == 0)
                            {
                                return;
                            }
                        }
                        printf("Tipo de garantia?\n");
                        printf("\n[0] - Imovel");
                        printf("\n[1] - Fiador");
                        printf("\n[2] - Depositos");
                        printf("\n[3] - Produtos");
                        fflush(stdin);
                        scanf("%d", &garantiaOpcao);
                        if (garantiaOpcao == 0)
                        {
                            strcpy(aux->info.garantia[4].tipo, "Imovel");
                        }
                        else if (garantiaOpcao == 1)
                        {
                            strcpy(aux->info.garantia[4].tipo, "Fiador");
                        }
                        else if (garantiaOpcao == 2)
                        {
                            strcpy(aux->info.garantia[4].tipo, "Depositos");
                        }
                        else if (garantiaOpcao == 3)
                        {
                            strcpy(aux->info.garantia[4].tipo, "Produtos");
                        }
                        else if (garantiaOpcao != 0 || garantiaOpcao != 1 || garantiaOpcao != 2 || garantiaOpcao || 3)
                        {
                            printf("OPCAO invalida!\n");
                            exit(0);
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", &(aux->info.garantia[4].descricao));
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[4].valor));
                        break;
                    case 6:
                        for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
                        {
                            for (int i = 0; i < aux->info.garantiaNumero; i++)
                            {
                                printf("\n*------------GARANTIAS----------------*\n");
                                printf("\nGarantia #%i\n", i + 1);
                                printf("\tTipo:%s\n\tDescricao:%s\n\tValor:%.2f€\n",
                                       aux->info.garantia[i].tipo,
                                       aux->info.garantia[i].descricao,
                                       aux->info.garantia[i].valor);
                                printf("*--------------------------------------*\n");
                                system("pause");
                            }
                        }
                        break;
                    default:
                        printf("OPCAO invalida!\n");
                        break;
                    }

                } while (0 < opcao < 7);
            }
        }
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

void altera_montante(ELEM_CREDITO **iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    int resposta;
    float novo;

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Proposta #%d\n", aux->info.numeroSequencial);
            printf("Montante atual: %.2f\n", aux->info.montante);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);
            if (resposta == 0)
            {
                return;
            }
            if (resposta == 1)
            {
                printf("Insira o novo montante: \n");
                fflush(stdin);
                scanf("%f", novo);

                aux->info.montante = novo;
            }
        }
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

void corrigir_erro_analise(ELEM_CREDITO **iniLista, int id)
{
    ELEM_CREDITO *aux = NULL;
    int resposta;
    int novo; //* NEGATIVA OU POSITIVA

    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (id == aux->info.ID)
        {
            printf("Situacao atual: %s\n", aux->analise.situacao);
            printf("Corresponde ao inserido\n**0-NAO**\n**1-SIM**\n");
            fflush(stdin);
            scanf("%d", &resposta);
            if (resposta == 0)
            {
                return;
            }
            if (resposta == 1)
            {
                printf("Insira a nova situacao:\n**0-NEGATIVO**\n**1-POSITIVO**\n");
                fflush(stdin);
                scanf("%s", novo);
                switch (novo)
                {
                case 0:
                    strcpy(aux->analise.situacao, "Negativo");
                    break;
                case 1:
                    strcpy(aux->analise.situacao, "Positivo");
                    break;
                default:
                    printf("OPCAO invalida!\n");
                    break;
                }
            }
        }
        //TODO: FALTA A CENA DA DATA
        else
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}
