#ifndef FATOS_H_INCLUDED
#define FATOS_H_INCLUDED
#include "global.h"
struct fatos * carrega_dados2(struct fatos *, char *);
struct fatos * apaga(struct fatos*);
struct Data leit();
void tira_espacos(char *);
void titulo(char *);
int menu4_impressao();
void descricao(char *);
void imprime(char *);
void menu4_grande_dia();
void menu4_melhores_feitos();
void menu4_surpresas();
struct fatos * insercao_fatos(struct fatos*, char *);
void exb(struct fatos *);
void princ_grande_dia(pessoa *);
void princ_melhores_feitos(pessoa *);
void princ_surpresas(pessoa *);

#endif // FATOS_H_INCLUDED
