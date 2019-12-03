
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

//// Declaracao dos simbolos e tabelas ***********************************////////////////////

typedef struct simbolo
{
    char lexema[100];
    char Token[100];
    char categoria[100];
    char typeData[100];
    char value[100];
    int line; //server para amarzenar a linha onde se encontra a o simbolo
    struct simbolo *next;
} Simbolo;

typedef struct erro
{
    int line;
    char description[1000];
    struct erro *next;
} Erro;

typedef struct estrutura
{
    char nome[100];
    struct variavel *variaveis;
} Estrutura;

typedef struct variavel
{

    char estado[100];
    char name[100];
    char scope[100];
    char type[100];
    int line;
    struct variavel *next;
    /* data */
} Variavel;

typedef struct funcao
{
    char estado[100];
    char parametros[100];
    char tipo[100];
    char nome[100]

    /* data */
} Funcao;

//////////Fim da declaracao de simbolo e tabelas**************************

Simbolo *inserirSimbolo(Simbolo *simbolo, char *lexema, char *Token, char *categoria, char *tipoDados, char *valor, int linha)
{
    Simbolo *novo = (Simbolo *)malloc(sizeof(Simbolo));

    strcpy(novo->lexema, lexema);
    strcpy(novo->Token, Token);
    strcpy(novo->categoria, categoria);
    strcpy(novo->typeData, tipoDados);
    strcpy(novo->value, valor);

    if (simbolo == NULL)
    {
        return novo;
    }
    else
    {
        simbolo->next = novo;
        return simbolo;
    }
}

Estrutura *criarEstrutura(char *nome)
{
    Estrutura *nova = (Estrutura *)malloc(sizeof(Estrutura));
    strcpy(nova->nome, nome);
    nova->variaveis = NULL;
    return nova;
}

Variavel *criarVariavel(Variavel variavel)
{

    Variavel *novo = (Variavel *)malloc(sizeof(Variavel));
    strcpy(novo->name, variavel.name);
    strcpy(novo->type, variavel.type);
    strcpy(novo->scope, variavel.scope);
    strcpy(novo->estado, variavel.estado);
    novo->line = variavel.line;
    return novo;
}

/*Variavel *criarVariavel(char *name, char *scope, char *type, int line, char *estado)
{

    Variavel *novo = (Variavel *)malloc(sizeof(Variavel));
    strcpy(novo->name, name);
    strcpy(novo->type, type);
    strcpy(novo->scope, scope);
    strcpy(novo->estado, estado);
    novo->line = line;
    return novo;
}*/

void addVariavel(Estrutura *estrutura, Variavel *variavel)
{

    Variavel *novo = (Variavel *)malloc(sizeof(Variavel));
    strcpy(novo->name, variavel->name);
    strcpy(novo->type, variavel->type);
    strcpy(novo->scope, variavel->scope);
    strcpy(novo->estado, variavel->estado);
    novo->line = variavel->line;
    if (/* condition */)
    {
        /* code */
    }

    return novo;

    /*  if (estrutura->variaveis == NULL)
        estrutura->variaveis = variavel;
    else
    {

        variavel->next = estrutura->variaveis;
        estrutura->variaveis = variavel;
    }*/
}

void addVariavel(Variavel *variaveis, Variavel *variavel)
{
    if (estrutura->variaveis == NULL)
        estrutura->variaveis = variavel;
    else
    {

        variavel->next = estrutura->variaveis;
        estrutura->variaveis = variavel;
    }
}

void procurar(Estrutura *estrutura, char *nome, Erro *erro)
{

    Estrutura *aux = estrutura;

    while (aux == NULL)
    {
        if (strcpy(aux->nome, nome))
        {
        }
    }
}

Erro *inserirErro(Erro *erro, int line, char *descricao)
{
    Erro *novo = (Erro *)malloc(sizeof(Erro));
    novo->line = line;
    strcpy(novo->description, descricao);
    if (erro = NULL)
        return novo;
    else
    {
        novo->next = erro;
        return novo;
    }
}

int variavelDeclarado(Variavel *todas, Variavel *variavel)
{

    Variavel *aux = todas;
    while (aux != NULL)
    {
        if (strcmp(aux->name, variavel->name) == 0 && strcmp(aux->scope, variavel->scope) == 0 && strcmp(aux->estado, "Delcarado"))
            return 1;
    }
    return 0;
}

int funcaoDeclarado(Funcao *funcoes, Funcao *funcao)
{

    Funcao *aux = funcoes;
    while (aux != NULL)
    {
        if (strcmp(aux->nome, funcao->nome) == 0 && strcmp(aux->tipo, funcao->tipo) == 0 && strcmp(aux->estado, "Declarado"))
            return 1;
    }
    return 0;
}
