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
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*--------------------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("MENU LISTAR");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("----------------------------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Listar as propostas de credito por analisar\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Listar as propostas de credito analisadas\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("3");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Listar as propostas de credito por uma prioridade\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("4");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Listar as propostas de credito acima de um determinado montante\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("5");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Listar todas as propostas de credito analisadas por um determinado utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("6");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Listar ranking de analistas\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("7");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Listar utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n8");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar para o menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*--------------------------------------------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int menu_altera_garantias() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("ALTERAR GARANTIAS");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("---------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar #1 garantia\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar #2 garantia\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("3");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar #3 garantia\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("4");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar #4 garantia\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("5");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar #5 garantia\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("6");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Listar garantias\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n7");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar para o menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*-----------------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int menu_altera() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("MENU ALTERA PROPOSTAS CREDITO");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("---------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar o nome\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar IBAN\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("3");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar as garantias\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("4");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar o montante\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("5");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar erro na analise\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n6");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar ao menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*------------------------------------------------------------*\n");
    printf("\nInsira opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int menu_admin() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("MENU ADMIN");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("---------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - CRUD utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - CRUD proposta de credito\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("3");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Relatorio das propostas de credito\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("4");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Menu de listagens\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n5");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar ao menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int menu_analista() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("MENU ANALISTA");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("---------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Analisar proposta de credito\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar para o menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*------------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int CRUD_utilizador() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("CRUD UTILIZADOR");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("---------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Inserir utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Remover utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("3");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Menu alterar utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n4");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar para o menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*----------------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int CRUD_prop_credito() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("CRUD PROPOSTA DE CREDITO");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("---------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Inserir proposta de credito\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Menu alterar proposta de credito\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("3");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Remover proposta de credito\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("4");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Pesquisar proposta de credito\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n5");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar para o menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*-----------------------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int menu_altera_utilizador() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("MENU ALTERA UTILIZADOR");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("-----------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar o nome do utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar o username do utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("3");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar a password do utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("4");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Alterar o tipo do utilizador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n5");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar para o menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*-----------------------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int menu_entrar() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*--------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("LOGIN");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("----------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Administrador\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Analista \n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\n3");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Voltar para o menu anterior\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*-------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

int menu_inicial() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcao;
    printf("\n*------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("MENU INICAL");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("---------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("1");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Entrar\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("2");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Ajuda\n\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("0");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" - Sair do programa\n");
    printf("*--------------------------------------*\n");
    printf("\nInsire opcao: ");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    fflush(stdin);
    scanf("%d", &opcao);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    return opcao;
}

void ajuda() //*
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n*--------------------------------------");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("AJUDA");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("-------------------------------------------------*\n");
    printf("# Caso seja a primeira vez que usa este programa, por favor insira um ficheiro do tipo .csv\n");
    printf("# O programa nao aceita \"Enters\" para mudar de linha.\n");
    printf("# O primeiro administrador sera o primeiro utilizador registado no programa.\n");
    printf("# Quaso se esqueceu da sua palavra-passe ou username, por favor contacte um administrador.\n");
    printf("# Para mais informacao nao hesite em contactar!\n");
    printf("# Em anexo encontra-se um manual de utilizador.\n");
    printf("*------------------------------------------------------------------------------------------------*\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\nCopyright: Andre Brandao e Diogo Campos IPVC - ESTG\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    //system("pause");
    //system("cls");
}