/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: dashboard.c
 ** Ficheiro C responsável pelos menus do programa
\********************************************************************************/

//! HEADER
#include "headers.h"

int menu_listar() //*
{
    int opcao;
    printf("\n*--------------------------MENU LISTAR--------------------------------*\n");
    printf("1 - Listar as propostas de credito por analisar\n");
    printf("2 - Listar as propostas de credito analisadas\n");
    printf("3 - Listar as propostas de credito por uma prioridade\n");
    printf("4 - Listar as propostas de credito acima de um determinado montante\n");
    printf("5 - Listar todas as propostas de crédito analisadas por um determinado utilizador\n");
    printf("6 - Listar ranking de analistas\n");
    printf("\n7 - Voltar para o menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*--------------------------------------------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}

int menu_altera_garantias() //*
{
    int opcao;
    printf("\n*------------ALTERAR GARANTIAS---------------*\n");
    printf("1 - Alterar #1 garantia\n");
    printf("2 - Alterar #2 garantia\n");
    printf("3 - Alterar #3 garantia\n");
    printf("4 - Alterar #4 garantia\n");
    printf("5 - Alterar #5 garantia\n");
    printf("6 - Listar garantias\n");
    printf("\n7 - Voltar para o menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*-----------------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}

int menu_altera() //*
{
    int opcao;
    printf("\n*------------MENU ALTERA---------------*\n");
    printf("1 - Alterar o nome\n");
    printf("2 - Alterar IBAN\n");
    printf("3 - Alterar o numero de garantias\n");
    printf("4 - Alterar as garantias\n");
    printf("5 - Alterar o montante\n");
    printf("6 - Alterar erro na analise\n");
    printf("\n7 - Voltar ao menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsira opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}

int menu_admin() //*
{
    int opcao;
    printf("\n*------------MENU ADMIN---------------*\n");
    printf("1 - Criar utilizador\n");
    printf("2 - Remover utilizador\n");
    printf("3 - Inserir proposta de credito\n");
    printf("4 - Alterar proposta de credito\n");
    printf("5 - Apagar proposta de credito\n");
    printf("6 - Pesquisa proposta de credito\n");
    printf("7 - Relatorio das propostas de credito\n");
    printf("8 - Menu de listagens\n");
    printf("\n9 - Voltar ao menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}

int menu_analista() //*
{
    int opcao;
    printf("\n*------------MENU ANALISTA---------------*\n");
    printf("1 - Analisar proposta de credito\n");
    printf("\n2 - Voltar para o menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*------------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}

int menu_entrar() //*
{
    int opcao;
    printf("\n*------------ENTRAR COMO:---------------*\n");
    printf("1 - Administrador\n");
    printf("2 - Analista \n");
    printf("\n3 - Voltar para o menu anterior\n");
    printf("0 - Sair do programa\n");
    printf("*-----------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}

int menu_inicial() //*
{
    int opcao;
    printf("\n*------------MENU INICIAL---------------*\n");
    printf("1 - Entrar \n");
    printf("2 - Ajuda\n");
    printf("\n0 - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    return opcao;
}

void ajuda() //*
{
    printf("\n*--------------------------------------AJUDA-------------------------------------------------*\n");
    printf("# Caso seja a primeira vez que usa este programa, por favor insira um ficheiro do tipo .csv\n");
    printf("# O programa nao aceita \"Enters\" para mudar de linha.\n");
    printf("# O primeiro administrador sera o primeiro utilizador registado no programa.\n");
    printf("# Quaso se esqueceu da sua palavra-passe ou username, por favor contacte um administrador.\n");
    printf("# Para mais informacao nao hesite em contactar!\n");
    printf("# Em anexo encontra-se um manual de utilizador.\n");
    printf("\n*------------------------------------------------------------------------------------------------*\n");
    printf("\nCopyright: Andre Brandao e Diogo Campos IPVC - ESTG\n");
    system("pause");
}