#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED
#include "global.h"
void imprime_lista(pessoa *);
void nomes(char *);
void nomes_fgets(char *);
void limpa_tela(void);
float carteira();
int idades();
void menu();
void menu2();
int cadastro(pessoa *, char *);
void exibicao(pessoa *);
void imprime_usuarios(pessoa *);
void escolha(int, pessoa *);

#endif // INFO_H_INCLUDED
