/*********************************************************************************************\ 
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: credito.c
 ** Ficheiro C responsável por todas as operações relacionadas com as propostas de crédito
\***********************************************************************************************/

//! HEADER
#include "headers.h"

CREDITO criar_credito(ELEM_PRIORIDADE *iniLista)
{
    CREDITO info;
    int garantiaOpcao;

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
    printf("Quantas garantias?\n");
    fflush(stdin);
    scanf("%d", &info.garantiaNumero); // maximo 5
    if (info.garantiaNumero > MAX_GARANTIAS)
    {
        printf("Numero maximo de garantias excedido!\n");
        return;
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
                return;
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
        strcpy(info.prioridade, carrega_prioridade(iniLista, info.montante)); // a carrega_prioridade retorna a prioridade entre os montantes x e y

        return info;
    }
}

void altera_nome(ELEM_CREDITO **iniLista, int id)
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

void altera_iban(ELEM_CREDITO **iniLista, int id)
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

void altera_numero_garantias(ELEM_CREDITO **iniLista, int id)
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

void altera_garantias(ELEM_CREDITO **iniLista, int id)
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
                            return;
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
                            return;
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
                            return;
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
                            return;
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
                            return;
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
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

void altera_montante(ELEM_CREDITO **iniLista, int id)
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

void corrigir_erro_analise(ELEM_CREDITO **iniLista, int id)
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
                printf("Insira uma nova data (DD-MM-YYYY): \n");
                fflush(stdin);
                scanf("%[^\n]", aux->analise.data);
            }
            ctrl = 1;
        }
    }
    if (ctrl == 0)
    {
        printf("Utilizador nao encontrado!\n");
    }
}

int apagar_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista)
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
        printf("Lista vazia !!\n");
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

ANALISE analisar_credito(ELEM_UTILIZADOR **iniLista, UTILIZADOR sessao)
{
    int situacao;
    ANALISE info;
    ELEM_UTILIZADOR *aux = NULL;
    strcpy(info.utilizador, sessao.username);
    printf("Situacao da analise\n [0] - Negativa\n [1] - Positiva\n");
    fflush(stdin);
    scanf("%d", &situacao);
    if (situacao == 0)
    {
        strcpy(info.situacao, "Negativa");
    }
    else if (situacao == 1)
    {
        strcpy(info.situacao, "Positiva");
    }
    else
    {
        printf("OPCAO invalida!\n");
        return;
    }
    printf("Introduza uma justificacao:\n");
    fflush(stdin);
    scanf("%[^\n]", info.justificacao);
    printf("Introduza uma data (DD-MM-YYYY):\n");
    fflush(stdin);
    scanf("%[^\n]", info.data);
    //(*fimLista)->analise = info;
    for (aux = (*iniLista); aux != NULL; aux = aux->seguinte)
    {
        if (sessao.ID == aux->info.ID)
        {
            aux->info.rank++; // adicionar pontos após ter analisado uma proposta
        }
    }
    return info;
}

void gravar_credito(ELEM_CREDITO *iniLista)
{
    ELEM_CREDITO *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("files\\propostas.dat", "w+b");

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        fwrite(&(aux->info), sizeof(CREDITO), 1, fp);
        fwrite(&(aux->analise), sizeof(ANALISE), 1, fp);
    }
    fclose(fp);
}

int carregar_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista)
{
    CREDITO info;
    ANALISE analise;
    int res = 0;
    FILE *fp = NULL;

    fp = fopen("files/propostas.dat", "r+b");
    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("Ficheiro inexistente.\n");
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

    printf("Foram lidos %d propostas de credito com sucesso!\n", res);
    fclose(fp);

    return 0;
}

void inserir_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista, CREDITO *info, ANALISE *analise)
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

void troca_montante(ELEM_CREDITO *a, ELEM_CREDITO *b)
{
    float temp = a->info.montante;
    a->info.montante = b->info.montante;
    b->info.montante = temp;
}

void bubbleSort_montante(ELEM_CREDITO *iniLista)
{
    int trocada, i;
    ELEM_CREDITO *x = NULL;
    ELEM_CREDITO *y = NULL;

    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (x->info.montante > x->seguinte->info.montante)
                {
                    troca_montante(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void troca_situacao(ELEM_CREDITO *a, ELEM_CREDITO *b)
{
    char temp[20];

    strcpy(temp, a->analise.situacao);
    strcpy(a->analise.situacao, b->analise.situacao);
    strcpy(b->analise.situacao, temp);
}

void bubbleSort_situacao(ELEM_CREDITO *iniLista)
{
    int trocada, i;
    ELEM_CREDITO *x = NULL;
    ELEM_CREDITO *y = NULL;

    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (strcmp(x->analise.situacao, x->seguinte->analise.situacao) > 0)
                {
                    troca_situacao(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void troca_data(ELEM_CREDITO *a, ELEM_CREDITO *b)
{
    char temp[20];

    strcpy(temp, a->analise.data);
    strcpy(a->analise.data, b->analise.data);
    strcpy(b->analise.data, temp);
}

void bubbleSort_data(ELEM_CREDITO *iniLista)
{
    int trocada, i;
    ELEM_CREDITO *x = NULL;
    ELEM_CREDITO *y = NULL;

    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (strcmp(x->analise.data, x->seguinte->analise.data) > 0)
                {
                    troca_data(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void troca_rank(ELEM_UTILIZADOR *a, ELEM_UTILIZADOR *b)
{
    float temp = a->info.rank;
    a->info.rank = b->info.rank;
    b->info.rank = temp;
}

void bubbleSort_rank(ELEM_UTILIZADOR *iniLista)
{
    int trocada, i;
    ELEM_UTILIZADOR *x = NULL;
    ELEM_UTILIZADOR *y = NULL;

    if (iniLista == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        do
        {
            trocada = 0;
            x = iniLista;
            while (x->seguinte != y)
            {
                if (x->info.rank < x->seguinte->info.rank)
                {
                    troca_rank(x, x->seguinte);
                    trocada = 1;
                }
                x = x->seguinte;
            }
            y = x;

        } while (trocada);
    }
}

void gravar_prioridade(ELEM_PRIORIDADE *iniLista)
{
    ELEM_PRIORIDADE *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("files/prioridade.dat", "w+b");

    if (fp == NULL) // Teste para ver se houve problema ao carregar o ficheiro
    {
        printf("ERRO ao carregar o ficheiro.\n");
        return;
    }
    aux = iniLista;
    while (aux != NULL)
    {
        fwrite(&(aux->info), sizeof(PRIORIDADE), 1, fp);
        aux = aux->seguinte;
    }
    fclose(fp);
} 