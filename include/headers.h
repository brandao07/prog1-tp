/********************************************************************************\
 ** EI - Programação 1
 ** PL1 - Gestão Propostas de Crédito
 ** Realizado por: André Brandão (26244) e Diogo Campos (24888)
 ** Nome do ficheiro: headers.h
 ** Ficheiro H responsável por todas as declarações feitas antes da função main
\********************************************************************************/

//! BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//! ATRIBUIÇÃO DE VALORES
#define MAX_GARANTIAS 5 // Número máximo de garantias
#define MAX_GARANTIAS_TIPO 4 // Imóvel Fiador Depósitos Produtos

//! ESTRUTURAS
// Estrutra para o utilizador
typedef struct utilizador
{
    int ID;
    char username[20];
    char nome[100];
    char password[20];
    char tipo[20]; 
    int tipoID; //* 4 - Administrador 5 - Analista
    int rank; // Número de propostas de crédito analisadas
} UTILIZADOR;

// Estrutura para as prioridades
typedef struct prioridade
{
    char nome[50];
    float montanteInferior, montanteSuperior;
} PRIORIDADE;

// Estrutura para até 5 garantias
typedef struct garantia
{
    char tipo[20]; // Imóvel Fiador Depósitos Produtos
    char descricao[200];
    float valor;

} GARANTIA;

// Estruturas de uma propostas de crédito
typedef struct credito
{
    int numeroSequencial; // Proposta 1 ... Proposta 2 ...
    int ID;               // Posição na fila
    char nome[100];
    char IBAN[50];
    int garantiaNumero;
    GARANTIA garantia[MAX_GARANTIAS]; // Número máximo de garantias
    float montante; // Montante pedido
    char prioridade[20];              // Carregada do ficheiro csv
    int analise;                      //* 0 - NÃO ANALISADA 1 - ANALISADA

} CREDITO;

// Estrutura da lista dos UTILIZADORES
typedef struct elem_UTILIZADOR
{
    UTILIZADOR info;
    struct elem_UTILIZADOR *anterior; // Aponta para o nó (UTILIZADOR) anterior
    struct elem_UTILIZADOR *seguinte; // Aponta para o nó (UTILIAZDOR) seguinte
} ELEM_UTILIZADOR;

// Estrutura da lista dos CRÉDITOS
typedef struct elem_CREDITO
{
    CREDITO info;
    struct elem_CREDITO *anterior; // Aponta para o nó (CREDITO) anterior
    struct elem_CREDITO *seguinte; // Aponta para o nó (CREDITO) seguinte
} ELEM_CREDITO;

// Estrutura da lista das PRIORIDADES
typedef struct elem_PRIORIDADE
{
    PRIORIDADE info;
    struct elem_PRIORIDADE *anterior; // Aponta para o nó (PRIORIDADE) anterior
    struct elem_PRIORIDADE *seguinte; // Aponta para o nó (PRIORIDADE) seguinte
} ELEM_PRIORIDADE;

//! FUNÇÕES

void recebe_csv(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, char ficheiroCSV[]); // Função que recebe o ficheiro csv introduzido pelo utilizador

PRIORIDADE criar_prioridade(char prioridade[], int montanteInferior, int montanteSuperior); // Função para criar as várias prioridades recebidas do ficheiro csv

void inserir_prioridade(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, PRIORIDADE info); // Insere no fim a prioridade recebida

void imprime_prioridades(ELEM_PRIORIDADE *iniLista); // Imprime para o ecrã todas as prioridades existentes

int menu_inicial(); // Menu incial do programa

int menu_entrar();

int menu_analista();

int menu_admin();

UTILIZADOR criar_utilizador(ELEM_UTILIZADOR *iniLista); //Cria os utilizadores do programa e guarda no ficheiro users.txt

void inserir_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista, UTILIZADOR info); //Insere os utilizadores na lista

void gravar_utilizador(ELEM_UTILIZADOR *iniLista); //Grava os utilizadores no ficheiro texto users.txt

int verifique_username(ELEM_UTILIZADOR *iniLista, char username[]); //Verifica se o username já existe

int carregar_utilizador(ELEM_UTILIZADOR *iniLista); // Carrega os utilizadores do programa do ficheiro users.txt

void verifica_primeiro(ELEM_UTILIZADOR *iniListaUTILIZADOR, ELEM_UTILIZADOR *fimListaUTILIZADOR, UTILIZADOR info);

CREDITO criar_credito(ELEM_PRIORIDADE *iniLista);

char carrega_prioridade(ELEM_PRIORIDADE *iniLista,float montante);