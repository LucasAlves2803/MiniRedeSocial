#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listapessoa.h"


int main()
{
    setlocale(LC_ALL,"Portuguese");
    pessoa * phead = NULL;
    phead = reinicia(phead); // insere no início
    phead = pag1(phead);
    phead = apaga_lista(phead);
    return 0;
}


/*
void imprime(pessoa master){
    printf("Bem-vindo, %s suas informacoes estao seguras aqui\n", master.nome);
    puts("Esse aplicativo eh uma forma concreta de avaliar as mudancas na sua vida\n");
    printf("Nome: %s\n", master.nome);
    printf("Idade: %d\n", master.idade);
    printf("Seu dinheiro atual: %f\n", master.dinheiro);

}
*/
