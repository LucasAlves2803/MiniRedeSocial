#ifndef OBJETIVOS_H_INCLUDED
#define OBJETIVOS_H_INCLUDED
#include "global.h"
void principal_objetivos(pessoa *);
struct objetivos * insercao_obj(struct objetivos * , char *);
struct objetivos * carrega_dados_obj(struct objetivos * , char *);
struct objetivos * deleta_lista(struct objetivos *);
void exibe_objetivos(struct objetivos *);
void titulo_obj(char *);
void menu_objetivos();
struct Data leit_obj();
struct Data calculo_dias(int);
struct Data data_atual_obj();
struct Data prazo_obj();
void verifica_objetivo(struct objetivos *, char * nome, pessoa *);
void fracassos(char *);
void sucessos(char *);

#endif // OBJETIVOS_H_INCLUDED
