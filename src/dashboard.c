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

    printf("\n*------------MENU ADMIN---------------*\n");
    printf("1 - Criar utilizador\n");
    printf("2 - ...\n");
    printf("\n3 - Voltar para o menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}

int menu_analista()
{
    int opcao;

    printf("\n*------------MENU ANALISTA---------------*\n");
    printf("1 - ...\n");
    printf("2 - ...\n");
    printf("\n3 - Voltar para o menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}

int menu_entrar()
{
    int opcao;

    printf("\n*------------ENTRAR COMO:---------------*\n");
    printf("1 - Administrador\n");
    printf("2 - Analista \n");
    printf("\n3 - Voltar para o menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}

int menu_inicial()
{
    int opcao;

    printf("\n*------------MENU INICIAL---------------*\n");
    printf("1 - Entrar \n");
    printf("0 - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}