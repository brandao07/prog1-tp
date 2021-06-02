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

//! DEFINIÇÃO DE CONSTANTES
#define MAX_GARANTIAS 5 // Número máximo de garantias
#define MENU_INICIAL 0
#define MENU_ENTRAR 1
#define MENU_ADMIN 2
#define MENU_ANALISTA 3
#define MENU_ALTERA 4
#define MENU_LISTAR 5

//! ESTRUTURAS
// Estrutra para o utilizador
typedef struct utilizador
{
    int ID;
    char username[20];
    char nome[50];
    char password[20];
    char tipo[20];
    int tipoID; //* 4 - Administrador 5 - Analista
    int rank;   // Número de propostas de crédito analisadas
} UTILIZADOR;

// Estrutura para as prioridades
typedef struct prioridade
{
    char nome[50];
    float montanteInferior, montanteSuperior;
} PRIORIDADE;

// Estrutura para as datas das propostas de crédito
typedef struct data //* DD/MM/AAAA
{
    int dia, mes, ano;
} DATA;

// Estrutura para até 5 garantias
typedef struct garantia
{
    char tipo[20]; // Imóvel Fiador Depósitos Produtos
    char descricao[200];
    float valor;
} GARANTIA;

// Estrutura para a anlise de uma dada proposta
typedef struct analise
{
    char utilizador[20]; // = ao username do utilizador que a analisou
    char situacao[20];   //* NEGATIVA OU POSITIVA
    char justificacao[200];
    DATA data;
} ANALISE;

// Estruturas de uma propostas de crédito
typedef struct credito
{
    int numeroSequencial; // Proposta 1 ... Proposta 2 ...
    int ID;               // Posição na fila
    char nome[100];
    char IBAN[50];
    int garantiaNumero;
    GARANTIA garantia[MAX_GARANTIAS]; // Número máximo de garantias 5
    float montante;                   // Montante pedido
    char prioridade[20];              // Carregada do ficheiro csv
} CREDITO;

// Estrutura da lista dos UTILIZADORES
typedef struct elem_UTILIZADOR
{
    UTILIZADOR info;
    struct elem_UTILIZADOR *anterior; // Aponta para o nó (UTILIZADOR) anterior
    struct elem_UTILIZADOR *seguinte; // Aponta para o nó (UTILIAZDOR) seguinte
} ELEM_UTILIZADOR;

// Estrutura da lista das PRIORIDADES
typedef struct elem_PRIORIDADE
{
    PRIORIDADE info;
    struct elem_PRIORIDADE *anterior; // Aponta para o nó (PRIORIDADE) anterior
    struct elem_PRIORIDADE *seguinte; // Aponta para o nó (PRIORIDADE) seguinte
} ELEM_PRIORIDADE;

// Estrutura da lista dos CRÉDITOS //* Analisadas
typedef struct elem_CREDITO
{
    CREDITO info;
    ANALISE analise;               // informação da análise
    struct elem_CREDITO *anterior; // Aponta para o nó (CREDITO) anterior
    struct elem_CREDITO *seguinte; // Aponta para o nó (CREDITO) seguinte
} ELEM_CREDITO;

// Estrutura para a fila de processamento //* Falta Análise
typedef struct queue_CREDITO
{
    CREDITO info;
    struct elem_CREDITO *seguinte; // Aponta para o nó (CREDITO) seguinte
    struct elem_CREDITO *anterior; // Aponta para o nó (CREDITO) anterior
} QUEUE_CREDITO;

// Estrutura para lista simples de várias filas de processamento (duplamente ligadas)
typedef struct queues
{
    QUEUE_CREDITO *iniLista;
    QUEUE_CREDITO *fimLista;
    PRIORIDADE prioridade;
    struct queues *seguinte; // Aponta para o nó (QUEUE_CREDITO) seguinte
} QUEUES;

//! FUNÇÕES USERS.C

UTILIZADOR criar_utilizador(ELEM_UTILIZADOR *iniLista); //Cria os utilizadores do programa e guarda no ficheiro users.txt

void inserir_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista, UTILIZADOR *info); //Insere os utilizadores na lista

void gravar_utilizador(ELEM_UTILIZADOR *iniLista); //Grava os utilizadores no ficheiro texto users.txt

int verifique_username(ELEM_UTILIZADOR *iniLista, char username[]); //Verifica se o username já existe

int carregar_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista); // Carrega os utilizadores do programa do ficheiro users.txt

UTILIZADOR login_utilizador(ELEM_UTILIZADOR **iniLista); // Verifica se o login foi efetuado com sucesso

int remove_utilizador(ELEM_UTILIZADOR **iniLista, ELEM_UTILIZADOR **fimLista); // Remove um utilizador

//! FUNÇÕES QUEUE.C

void enqueue_credito(QUEUES **queue, CREDITO info); // Insere um elemento no fim da fila

void dequeue_credito(QUEUES **queue, char prioridade[]); // Remove o primeiro elemento da fila

void enqueue_prioridade(QUEUES **queue, PRIORIDADE info); // adiciona header da lista

void gravar_queues(QUEUES *queue); // Gravar no ficheiro queues.dat

void carregar_queues(QUEUES **queue); // carrega o ficheiro queues.dat

void insere_propcredito(ELEM_PRIORIDADE *iniListaP, ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista, QUEUES **queue, ELEM_UTILIZADOR **iniListaU, UTILIZADOR sessao); // Insere no fim na lista de propostas de crédito analisadas

void enqueue_prioridade(QUEUES **queue, PRIORIDADE prioridade); // Adiciona x prioridades origem da lista

//!FUNÇÕES DASHBOARD.C

int menu_inicial(); // Menu incial do programa

int menu_entrar(); // Menu secundário do programa

int menu_analista(); // Menu do analista

int menu_admin(); // Menu do administrador

int menu_altera_garantias(); // Menu para alterar as garantias

int menu_altera(); // Menu das alteracoes das propostas de credito

int menu_listar(); // Menu para listar

void ajuda(); // Apoio ao utilizador

//!FUNÇÕES DO CSV.C

void recebe_csv(QUEUES **queue, ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, char ficheiroCSV[]); // Separa as strings recebidas do ficheiro CSV em três variáveis linha a linha

PRIORIDADE criar_prioridade(QUEUES **queue, char prioridade[], int montanteInferior, int montanteSuperior); // Cria uma prioridade (uma prioridade corresponde a 1 linha do ficheiro CSV)

void inserir_prioridade(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista, PRIORIDADE *info); // Insere prioridade criada na lista PRIORIDADE

void imprime_prioridades(ELEM_PRIORIDADE *iniLista); // Imprime para o ecrã todas as prioridades carregadas pelo programa

const char *carrega_prioridade(ELEM_PRIORIDADE *iniLista, float montante); // Insere prioridade em uma proposta de crédito

int conta_prioridade(ELEM_PRIORIDADE *iniLista); // Conta o número de prioridades

void gravar_prioridade(ELEM_PRIORIDADE *iniLista); // Grava num ficheiro temporario as 

int carrega_priridades(ELEM_PRIORIDADE **iniLista, ELEM_PRIORIDADE **fimLista); // Carrega do ficheiro prioridades.dat

//!FUNÇÕES DO CREDITO.C

CREDITO criar_credito(ELEM_PRIORIDADE *iniLista); // Cria uma nova proposta de crédito

void imprime_credito(ELEM_CREDITO *iniLista, int id); // Imprime para o ecrã uma Proposta de crédito juntamente com as suas garantias e análise

void altera_nome(ELEM_CREDITO **iniLista, int id); // Altera o nome

void altera_iban(ELEM_CREDITO **iniLista, int id); // Altera o IBAN

void altera_numero_garantias(ELEM_CREDITO **iniLista, int id); // Altera o numero de garantias

void altera_garantias(ELEM_CREDITO **iniLista, int id); // Altera as garantias

void altera_montante(ELEM_CREDITO **iniLista, int id); // Altera o montante

void altera_garantias(ELEM_CREDITO **iniLista, int id); // Altera as garantias

int apagar_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista); // Apagar proposta de credito

void pesquisar_credito(ELEM_CREDITO *iniLista); // Pesquisar proposta de credito pelo nome

ANALISE analisar_credito(ELEM_UTILIZADOR **iniLista, UTILIZADOR sessao); // Insere análise na proposta de crédito

void gravar_credito(ELEM_CREDITO *iniLista); // grava no ficheiro propostas.dat

int carregar_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista); // carrega o ficheiro propostas.dat

void inserir_credito(ELEM_CREDITO **iniLista, ELEM_CREDITO **fimLista, CREDITO *info, ANALISE *analise); // insere na lista ELEM_CREDITO as propostas de crédito recebidas do ficheiro propostas.dat

//! FUNÇÕES DO SORT.C

void troca_situacao(ELEM_CREDITO *a, ELEM_CREDITO *b); // função auxiliar do bubbleSort_situacao

void bubbleSort_situacao(ELEM_CREDITO *iniLista); // ordena propostas de crédito por situação

void troca_montante(ELEM_CREDITO *a, ELEM_CREDITO *b); // função auxiliar do bubbleSort_montante

void bubbleSort_montante(ELEM_CREDITO *iniLista); // ordena propostas de crédito por montante

void troca_data_ano(ELEM_CREDITO *a, ELEM_CREDITO *b); // função auxiliar do bubbleSort_data_ano

void bubbleSort_data_ano(ELEM_CREDITO *iniLista); // ordena propostas de crédito por ano

void troca_data_mes(ELEM_CREDITO *a, ELEM_CREDITO *b); // função auxiliar do bubbleSort_data_mes

void bubbleSort_data_mes(ELEM_CREDITO *iniLista); // ordena propostas de crédito por mes

void troca_data_dia(ELEM_CREDITO *a, ELEM_CREDITO *b); // função auxiliar do bubbleSort_data_dia

void bubbleSort_data_dia(ELEM_CREDITO *iniLista); // ordena propostas de crédito por dia

void troca_rank(ELEM_UTILIZADOR *a, ELEM_UTILIZADOR *b); //função auxiliar do bubbleSort_rank

void bubbleSort_rank(ELEM_UTILIZADOR *iniLista); //ordena por ordem decrescente o rank dos analistas

//! FUNÇÕES LISTAGENS.C

void listar_analisadas(ELEM_CREDITO *iniLista); // Listar as propostas de credito analisadas

void listar_prioridade(ELEM_CREDITO *iniLista); // Listar propostas de credito por prioridade

void listar_acima_montante(ELEM_CREDITO *iniLista); // Listar proposta de credito acima de um determinado montante

void listar_credito(ELEM_CREDITO *aux); // Lista credito

void listar_por_analisar(QUEUES *queue); // Listar propostas por analisar

void bubbleSort_listas_credito(ELEM_CREDITO *iniLista); // Listar todas as propostas por um determinado utilizador ordenadas por data de análise e depois por situação positiva/negativa

void listar_por_analisar_aux(QUEUE_CREDITO *aux); // Listar propostas ainda nao analisadas

void listar_ranking(ELEM_UTILIZADOR *iniLista); // Listar por ordem decrescente o ranking dos analistas