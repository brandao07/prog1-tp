/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: dashboard.c
 ** Ficheiro C responsável pelos menus do programa
\********************************************************************************/

//! HEADER
#include "headers.h"

int menu_admin()
{
    int opcao;
    UTILIZADOR info;

    printf("\n*------------MENU ADMIN---------------*\n");
    printf("1 - Criar utilizador\n");
    printf("2 - ...\n");
    printf("\n3 - Voltar para o menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int menu_analista()
{
    int opcao;
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
        scanf("%d", &opcao);

        if (0 >= opcao <= 3)
        {
            return opcao;
        }
        printf("OPCAO INVALIDA!\n");
    } while (opcao != 3);
}

int menu_entrar()
{
    int opcao;
    do
    {
        printf("\n*------------ENTRAR COMO:---------------*\n");
        printf("1 - Administrador\n");
        printf("2 - Analista \n");
        printf("\n3 - Voltar para o menu anterior\n");
        printf("0 - Sair do programa\n");
        printf("*--------------------------------------*\n");
        printf("\nInsire opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        if (0 >= opcao <= 3)
        {
            return opcao;
        }
        printf("OPCAO INVALIDA!\n");
    } while (opcao != 3);
}

int menu_inicial(char ficheiroCSV[])
{
    int opcao;
    do
    {
        printf("\n*------------MENU INICIAL---------------*\n");
        printf("1 - Entrar \n");
        printf("0 - Sair do programa\n");
        printf("*--------------------------------------*\n");
        printf("\nInsire opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        // opcao >=0 && opcao <=1
        if (0 >= opcao <= 1)
        {
            return opcao;
        }
        printf("OPCAO INVALIDA!\n");

    } while (opcao != 0);
}