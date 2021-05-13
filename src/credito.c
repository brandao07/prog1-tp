#include "headers.h"

CREDITO criar_credito(ELEM_PRIORIDADE *iniLista)
{
    CREDITO info;
    int garantiaOpcao[MAX_GARANTIAS_TIPO];
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
            scanf("%d", &garantiaOpcao[i]);
            if (garantiaOpcao[i] == 0)
            {
                strcpy(info.garantia[i].tipo, "Imovel");
            }
            else if (garantiaOpcao[i] == 1)
            {
                strcpy(info.garantia[i].tipo, "Fiador");
            }
            else if (garantiaOpcao[i] == 2)
            {
                strcpy(info.garantia[i].tipo, "Depositos");
            }
            else if (garantiaOpcao[i] == 3)
            {
                strcpy(info.garantia[i].tipo, "Produtos");
            }
            else if (garantiaOpcao[i] != 0 || garantiaOpcao[i] != 1 || garantiaOpcao[i] != 2 || garantiaOpcao[i] || 3)
            {
                printf("OPCAO invalida!\n");
                exit(0);
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
        strcpy(info.prioridade, carrega_prioridade(iniLista, info.montante));
        info.analise = 0;

        return info;
    }
}