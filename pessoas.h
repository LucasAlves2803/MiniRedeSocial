#ifndef PESSOAS_H_INCLUDED
#define PESSOAS_H_INCLUDED
#include "global.h"
void principal_amigos(pessoa *);
void principal_garotas(pessoa *);
struct pessoas * insercao_pessoas(struct pessoas *, char *);
struct pessoas * carrega_dados(struct pessoas *, char *);
struct pessoas * exclui (struct pessoas *);
void exibe(struct pessoas *);
void menu3_amigos();
void menu3_garotas();


#endif // PESSOAS_H_INCLUDED
