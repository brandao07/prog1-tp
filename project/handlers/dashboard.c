/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: dashboard.c
 ** Ficheiro C responsável pelos menus do programa
 *! MENU_INICIAL = 0 MENU_ADMIN = 1 MENU_ANALISTA = 2;
\********************************************************************************/

void menuAdmin(int opcao[])
{
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
            //criarUtilizador();
            printf("Utilizador criado com sucesso!\n");
            system("cls");
            break;
        case 2:
            system("cls");
        case 3: // Volta para o menu anterior
            return;
        default:
            printf("OPCAO INVALIDA!\n");
            system("cls");
            break;
        }

    } while (opcao[MENU_ADMIN] != 0);
}

void menuAnalista(int opcao[])
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
            system("cls");
            break;
        case 2:
            system("cls");
        case 3: // Volta para o menu anterior
            return;
        default:
            printf("OPCAO INVALIDA!\n");
            system("cls");
            break;
        }

    } while (opcao[MENU_ANALISTA] != 0);
}

void menuEntrar(int opcao[])
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
            menuAdmin(opcao);
            system("cls");
            break;
        case 2:
            menuAnalista(opcao); // Entra no menu Analista
            system("cls");
        case 3: // Volta para o menu anterior
            return;
        default:
            printf("OPCAO INVALIDA!\n");
            system("cls");
            break;
        }
    } while (opcao[MENU_ENTRAR] != 3);
}

void menuInicial(char ficheiroCSV[])
{
    ELEM_UTILIZADOR *iniListaUTILIZADOR = NULL, *fimListaUTILIZADOR = NULL;
    ELEM_CREDITO *iniListaCREDITO = NULL, *fimListaCREDITO = NULL;
    ELEM_PRIORIDADE *iniListaPRIORIDADE = NULL, *fimListaPRIORIDADE = NULL;

    recebeCSV(&iniListaPRIORIDADE, &fimListaPRIORIDADE, ficheiroCSV); // Carrega para o programa toda a informação do ficheiro csv
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
            menuEntrar(opcao); // Entra com uma conta do tipo administrador ou analista
            system("cls");
            break;
        default:
            printf("OPCAO INVALIDA!\n");
            system("cls");
        }

    } while (opcao[MENU_INICIAL] != 0);
}