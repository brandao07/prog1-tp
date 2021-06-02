/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: credito.c
 ** Ficheiro C responsável por todas as operações relacionadas com as propostas de crédito
\***********************************************************************************************/

//! HEADER
#include "headers.h"

//TODO

CREDITO criar_credito(ELEM_PRIORIDADE *iniLista) //*
{
    CREDITO info;
    int garantiaOpcao;
    int ctrl = 0;
    // Input dos dados da proposta de crédito
    printf("Introduza identificador:\n");
    fflush(stdin);
    scanf("%d", &info.ID);
    printf("Introduza nome:\n");
    fflush(stdin);
    scanf("%[^\n]", info.nome);
    printf("Introduza IBAN:\n");
    fflush(stdin);
    scanf("%s", info.IBAN);

    while (ctrl != 1)
    {
        printf("Quantas garantias?\n");
        fflush(stdin);
        scanf("%d", &info.garantiaNumero); // maximo 5

        if (info.garantiaNumero > MAX_GARANTIAS)
        {
            printf("Numero maximo de garantias excedido!\n");
            ctrl = 0;
        }
        else
        {
            ctrl = 1;
        }
    }

    for (int i = 0; i < info.garantiaNumero; i++)
    {
        printf("Tipo de garantia?\n");
        printf("\n[0] - Imovel");
        printf("\n[1] - Fiador");
        printf("\n[2] - Depositos");
        printf("\n[3] - Produtos\n");
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
        }

        printf("Descricao sobre a proposta:\n");
        fflush(stdin);
        scanf("%[^\n]", info.garantia[i].descricao);
        printf("Valor:\n");
        fflush(stdin);
        scanf("%f", &info.garantia[i].valor);
    }

    printf("Montante:\n");
    scanf("%f", &info.montante);
    strcpy(info.prioridade, carrega_prioridade(iniLista, info.montante)); // a carrega_prioridade retorna a prioridade entre os montantes x e y

    return info;
}

void altera_nome(ELEM_CREDITO **iniLista, int id) //*
{
    int ctrl = 0;
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
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

void altera_iban(ELEM_CREDITO **iniLista, int id) //*
{
    int ctrl = 0;
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
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

void altera_numero_garantias(ELEM_CREDITO **iniLista, int id) //*
{
    int ctrl = 0;
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
                scanf("%d", &novo);
                aux->info.garantiaNumero = novo;
            }
            ctrl = 1;
        }
        if (ctrl == 0)
        {
            printf("Utilizador nao encontrado!\n");
        }
    }
}

void altera_garantias(ELEM_CREDITO **iniLista, int id) //*
{
    ELEM_CREDITO *aux = NULL;
    int ctrl = 0;
    int resposta[2];
    int opcao, garantiaOpcao;

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
                                break;
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
                            return;
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", aux->info.garantia[0].descricao);
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[0].valor));
                        aux->info.garantiaNumero++;
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
                                break;
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
                            break;
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", aux->info.garantia[1].descricao);
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[1].valor));
                        aux->info.garantiaNumero++;
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
                                break;
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
                            break;
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", aux->info.garantia[2].descricao);
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[2].valor));
                        aux->info.garantiaNumero++;
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
                                break;
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
                            break;
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", aux->info.garantia[3].descricao);
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[3].valor));
                        aux->info.garantiaNumero++;
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
                                break;
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
                            break;
                        }
                        printf("Descricao sobre a proposta:\n");
                        fflush(stdin);
                        scanf("%[^\n]", aux->info.garantia[4].descricao);
                        printf("Valor:\n");
                        fflush(stdin);
                        scanf("%f", &(aux->info.garantia[4].valor));
                        aux->info.garantiaNumero++;
                        break;
                    case 6:
                        for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
                        {
                            for (int i = 0; i < aux->info.garantiaNumero; i++)
                            {
                                printf("\n*------------GARANTIAS----------------*\n");
                                printf("\nGarantia #%i\n", i + 1);
                                printf("\tTipo:%s\n\tDescricao:%s\n\tValor:%.2f\n",
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
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

void altera_montante(ELEM_CREDITO **iniLista, int id) //*
{
    int ctrl = 0;
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
                scanf("%f", &novo);

                aux->info.montante = novo;
            }
        }
        ctrl = 1;
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

void corrigir_erro_analise(ELEM_CREDITO **iniLista, int id) //*
{
    int ctrl = 0;
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
                scanf("%d", &novo);
                switch (novo)
                {
                case 0:
                    strcpy(aux->analise.situacao, "Negativa");
                    break;
                case 1:
                    strcpy(aux->analise.situacao, "Positiva");
                    break;
                default:
                    printf("OPCAO invalida!\n");
                    break;
                }
                printf("Insira uma nova justificacao:\n");
                fflush(stdin);
                scanf("%[^\n]", aux->analise.justificacao);
                printf("Insira um dia: \n");
                fflush(stdin);
                scanf("%d", &aux->analise.data.dia);
                printf("Insira um mes: \n");
                fflush(stdin);
                scanf("%d", &aux->analise.data.mes);
                printf("Insira um ano: \n");
                fflush(stdin);
                scanf("%d", &aux->analise.data.ano);
            }
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

int apagar_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista) //*
{
    int id;
    ELEM_CREDITO *aux = *iniLista;
    printf("Insira o ID da proposta de credito a ser removida: ");
    fflush(stdin);
    scanf("%d", &id);
    while (aux != NULL && aux->info.ID != id)
    {
        aux = aux->seguinte;
    }
    if (aux == NULL) // não existe elemento ou a lista é vazia
    {
        printf("Lista de propostas de credito vazia!\n");
        return -1;
    }
    if (aux->anterior == NULL) // vai remover o 1º elemento
    {
        *iniLista = aux->seguinte;
        if (*iniLista != NULL)
        {
            (*iniLista)->anterior = NULL;
        }
    }
    else
    {
        aux->anterior->seguinte = aux->seguinte;
    }

    if (aux->seguinte == NULL) // vai remover o ultimo elemento
    {
        *fimLista = aux->anterior;
        if (*fimLista != NULL)
        {
            (*fimLista)->seguinte = NULL;
        }
    }
    else
    {
        aux->seguinte->anterior = aux->anterior;
    }
    free(aux);
    return 0;
}

ANALISE analisar_credito(ELEM_UTILIZADOR **iniLista, UTILIZADOR sessao) //*
{
    int ctrl = 1;
    int situacao;
    ANALISE info;
    ELEM_UTILIZADOR *aux = NULL;
    strcpy(info.utilizador, sessao.username);
    while (ctrl == 1)
    {
        printf("Situacao da analise\n [0] - Negativa\n [1] - Positiva\n");
        fflush(stdin);
        scanf("%d", &situacao);
        if (situacao == 0)
        {
            strcpy(info.situacao, "Negativa");
            ctrl = 0;
        }
        else if (situacao == 1)
        {
            strcpy(info.situacao, "Positiva");
            ctrl = 0;
        }
        else
        {
            printf("OPCAO invalida!\n");
            ctrl = 1;
        }
    }
    printf("Introduza uma justificacao:\n");
    fflush(stdin);
    scanf("%[^\n]", info.justificacao);
    printf("Insira um dia: \n");
    fflush(stdin);
    scanf("%d", &info.data.dia);
    printf("Insira um mes: \n");
    fflush(stdin);
    scanf("%d", &info.data.mes);
    printf("Insira um ano: \n");
    fflush(stdin);
    scanf("%d", &info.data.ano);
    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (sessao.ID == aux->info.ID)
        {
            aux->info.rank++; // adicionar pontos após ter analisado uma proposta
        }
    }
    return info;
}

void gravar_credito(ELEM_CREDITO *iniLista) //*
{
    ELEM_CREDITO *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("files\\propostas.dat", "w+b");

    if (fp == NULL) // Teste para ver se houve problema ao criar o ficheiro
    {
        printf("ERRO ao criar o ficheiro propostas.dat!\n");
        return;
    }
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        fwrite(&(aux->info), sizeof(CREDITO), 1, fp);
        fwrite(&(aux->analise), sizeof(ANALISE), 1, fp);
    }
    fclose(fp);
}

int carregar_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista) //*
{
    CREDITO info;
    ANALISE analise;
    int res = 0;
    FILE *fp = NULL;

    fp = fopen("files/propostas.dat", "r+b");
    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar propostas.dat!\n");
        return -1;
    }

    while (fread(&info, sizeof(CREDITO), 1, fp) && fread(&analise, sizeof(ANALISE), 1, fp) == 1)
    {
        inserir_credito(iniLista, fimLista, &info, &analise);
        res++;
    }

    if (iniLista == NULL)
    {
        return -1;
    }
    if (res > 0)
    {
        printf("Foram lidos %d propostas de credito com sucesso!\n", res);
    }
    else
    {
        printf("Nao foram lidas propostas de credito!\n");
    }
    fclose(fp);

    return 0;
}

void inserir_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista, CREDITO *info, ANALISE *analise) //*
{
    ELEM_CREDITO *novo = NULL;
    novo = (ELEM_CREDITO *)calloc(1, sizeof(ELEM_CREDITO));

    //Teste para saber se o programa foi capaz de alocar memória para um nó da lista (CREDITO)
    if (novo == NULL)
    {
        printf("FALTA de memoria!\n");
        return;
    }

    novo->info = *info;
    novo->analise = *analise;
    novo->anterior = NULL;
    novo->seguinte = NULL;

    if (*iniLista == NULL) // Caso a lista esteja vazia atribui o primeiro elemento da lista ao elemento criado
    {
        *iniLista = novo;
        *fimLista = novo;
    }
    else
    {
        novo->anterior = *fimLista;
        (*fimLista)->seguinte = novo;
        *fimLista = novo;
    }
}

void relatorio_proposta(ELEM_CREDITO *iniLista) //*
{
    ELEM_CREDITO *aux = NULL;

    FILE *fp = NULL;
    fp = fopen("files/relatorio.txt", "w+");

    if (fp == NULL) // Teste para ver se houve problema ao criar o ficheiro
    {
        printf("ERRO ao criar o ficheiro relatorio.txt!\n");
        return;
    }

    bubbleSort_montante(iniLista);

    while (aux != NULL)
    {
        fprintf(fp, "\n*------------PROPOSTA----------------*\n");
        fprintf(fp, "\nProposta #%d\n", aux->info.numeroSequencial);
        fprintf(fp, "\tID: %d\n\tNome: %s\n\tIBAN: %s\n\tMontante: %.2f\n\tPrioridade: %s\n",
                aux->info.ID,
                aux->info.nome,
                aux->info.IBAN,
                aux->info.montante,
                aux->info.prioridade);
        fprintf(fp, "Numero de garantias: %d\n", aux->info.garantiaNumero);
        fprintf(fp, "*--------------------------------------*\n");
        for (int i = 0; i < aux->info.garantiaNumero; i++)
        {
            fprintf(fp, "\n*----fp,--------GARANTIAS----------------*\n");
            fprintf(fp, "\nGarantia #%i\n", i + 1);
            fprintf(fp, "\tTipo:%s\n\tDescricao:%s\n\tValor:%.2f\n",
                    aux->info.garantia[i].tipo,
                    aux->info.garantia[i].descricao,
                    aux->info.garantia[i].valor);
            fprintf(fp, "*--------------------------------------*\n");
        }
        fprintf(fp, "\n*------------ANALISE----------------*\n");
        fprintf(fp, "Analise da proposta #%d\n", aux->info.numeroSequencial);
        fprintf(fp, "\n\tAnalisada por: %s\n\tSituacao: %s\n\tJustificacao: %s\n\tData: %d/%d/%d\n",
                aux->analise.utilizador,
                aux->analise.situacao,
                aux->analise.justificacao,
                aux->analise.data.dia,
                aux->analise.data.mes,
                aux->analise.data.ano);
        fprintf(fp, "*--------------------------------------*\n");

        aux = aux->seguinte;
    }
    fclose(fp);
}