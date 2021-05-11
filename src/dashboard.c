/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: dashboard.c
 ** Ficheiro C responsável pelos menus do programa
 *! MENU_INICIAL = 0 MENU_ADMIN = 1 MENU_ANALISTA = 2 MENU_ENTRAR = 3
\********************************************************************************/

//! HEADER
#include "headers.h"

void menu_admin(int opcao[])
{
    UTILIZADOR info;
    do
    {
        printf("\n*------------MENU ADMIN---------------*\n");
        printf("1 - Criar utilizador\n");
        printf("2 - ...\n");
        printf("\n3 - Voltar para o menu anterior\n");
        printf("0 - Sair do programa\n");
        printf("*--------------------------------------*\n");
        printf("\nInsire opcao: ");
        scanf("%d", &opcao[MENU_ADMIN]);

        switch (opcao[MENU_ADMIN])
        {
        case 0: // Sai do programa
            exit(0);

        case 1: // Criar utilizador
            //info = criar_utilizador();
            //inserir_utilizador(&iniLista,&fimLista,info);
            //gravar_utilizador(iniLista);

            printf("Utilizador criado com sucesso!\n");
            break;
        case 2:
            break;
        case 3: // Volta para o menu anterior
            return;
        default:
            printf("OPCAO INVALIDA!\n");
            break;
        }

    } while (opcao[MENU_ADMIN] != 0);
}

void menu_analista(int opcao[])
{
    do
    {
        printf("\n*------------MENU ANALISTA---------------*\n");
        printf("1 - ...\n");
        printf("2 - ...\n");
        printf("\n3 - Voltar para o menu anterior\n");
        printf("0 - Sair do programa\n");
        printf("*--------------------------------------*\n");
        printf("\nInsire opcao: ");
        fflush(stdin);
        scanf("%d", &opcao[MENU_ANALISTA]);

        switch (opcao[MENU_ANALISTA])
        {
        case 0: // Sai do programa
            exit(0);

        case 1:
            break;
        case 2:
            break;
        case 3: // Volta para o menu anterior
            return;
        default:
            printf("OPCAO INVALIDA!\n");
            break;
        }

    } while (opcao[MENU_ANALISTA] != 0);
}

void menu_entrar(int opcao[])
{
    do
    {
        printf("\n*------------ENTRAR COMO:---------------*\n");
        printf("1 - Administrador\n");
        printf("2 - Analista \n");
        printf("\n3 - Voltar para o menu anterior\n");
        printf("0 - Sair do programa\n");
        printf("*--------------------------------------*\n");
        printf("\nInsire opcao: ");
        scanf("%d", &opcao[MENU_ENTRAR]);

        switch (opcao[MENU_ENTRAR])
        {
        case 0: // Sai do programa
            exit(0);

        case 1: // Entra no menu Admin
            menu_admin(opcao);
            break;
        case 2:
            menu_analista(opcao); // Entra no menu Analista
        case 3: // Volta para o menu anterior
            return;
        default:
            printf("OPCAO INVALIDA!\n");
            system("cls");
            break;
        }
    } while (opcao[MENU_ENTRAR] != 3);
}

void menu_inicial(char ficheiroCSV[])
{
    ELEM_UTILIZADOR *iniListaUTILIZADOR = NULL, *fimListaUTILIZADOR = NULL;
    ELEM_CREDITO *iniListaCREDITO = NULL, *fimListaCREDITO = NULL;
    ELEM_PRIORIDADE *iniListaPRIORIDADE = NULL, *fimListaPRIORIDADE = NULL;

    recebe_csv(&iniListaPRIORIDADE, &fimListaPRIORIDADE, ficheiroCSV); // Carrega para o programa toda a informação do ficheiro csv
    int opcao[4];
    do
    {
        printf("\n*------------MENU INICIAL---------------*\n");
        printf("1 - Entrar \n");
        printf("0 - Sair do programa\n");
        printf("*--------------------------------------*\n");
        printf("\nInsire opcao: ");
        scanf("%d", &opcao[MENU_INICIAL]);

        switch (opcao[MENU_INICIAL])
        {
        case 0: // Sai do programa
            exit(0);
        case 1:
            menu_entrar(opcao); // Entra com uma conta do tipo administrador ou analista
            break;
        default:
            printf("OPCAO INVALIDA!\n");
        }

    } while (opcao[MENU_INICIAL] != 0);
}