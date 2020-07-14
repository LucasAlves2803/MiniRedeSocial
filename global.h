#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
struct pessoas{
    char nome[55];
    struct pessoas * prox;
};

struct Data{
    int dia,mes,ano;
};

struct objetivos{
    char titulo[60];
    int bol;
    struct Data day;
    struct objetivos * prox;
};

struct fatos{
    char titulo[55];
    struct Data day;
    struct fatos * prox;
};
typedef struct pessoal{
    char nome[55];
    int idade,sucessos,fracassos;
    char senha[15];
    float dinheiro;
    struct objetivos * meus_objetivos;
    struct pessoas * amigos, * garotas;
    struct fatos * grande_dia, * melhores_feitos, * surpresas;
    struct pessoal * prox;
}pessoa;


#endif // GLOBAL_H_INCLUDED
