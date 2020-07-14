#include <stdio.h>
#include <string.h>
#include "global.h"
#include "info.h"
#include "fatos.h"
#include "objetivos.h"


int cadastro(pessoa * phead, char * nome){
    pessoa * ite;
    for (ite = phead ; ite != NULL; ite = ite->prox){
        if (!strcmp(ite->nome,nome)){
            return 0;
        }
    }
    return 1;
}

void limpa_tela(){
    system("cls");
}


void exibicao(pessoa * no){ // segundo do programa
    limpa_tela();
    printf("Ola,%s\n",no->nome);
    int op;
    while (op != 7){
        menu2();
        scanf("%d", &op);
        escolha(op,no);
        limpa_tela();
    }
}

void escolha(int op, pessoa * no){
    switch (op){
        case 1:
            principal_objetivos(no);
            break;
        case 2:
            principal_amigos(no);
            break;
        case 3:
            principal_garotas(no);
            break;
        case 4:
            princ_grande_dia(no);
            break;
        case 5:
            princ_surpresas(no);
            break;
        case 6:
            princ_melhores_feitos(no);
            break;
        case 7:
            puts("Voltando ao menu principal...");
            break;
        default:
            puts("Escolha um numero de 1 ate 7");
            break;
    }
}




void imprime_lista(pessoa * cab){
    pessoa * ite;
    for (ite = cab; ite != NULL; ite = ite->prox){;
    printf("Nome: %s\n", ite->nome);
    printf("Idade: %d\n", ite->idade);
    printf("Seu dinheiro atual: %.2f\n", ite->dinheiro);
    }
}

void imprime_usuarios(pessoa * cab){
    pessoa * ite;
    for (ite = cab; ite != NULL; ite = ite->prox){
    printf("Nome: %s\n", ite->nome);
    }
}




/*                  Ordem de Leitura
                1 - Nome
                2 - Idade
                3 - Dinheiro
                4 - Sem_besteira
*/

float carteira(){
    float din;
    printf("Digite quando dinheiro tem:\n");
    scanf("%f",&din);
    return din;
}

int idades(){
    int id;
    printf("Digite sua idade:\n");
    scanf("%d",&id);
    return id;
}

void nomes (char * nome){
    printf("Insira o nome:\n");
    scanf("%s",nome);
}

void nomes_fgets(char * nome){
    printf("Insira o nome:\n");
    fgets(nome,55,stdin);
}

void menu(){
    puts("Bem-vindo");
    puts("Mini-Rede Social");
    puts("Digite 1 -> Para ver os usuários cadastrados");
    puts("Digite 2 -> Para fazer um cadastro");
    puts("Digite 3 -> Para acessar sua conta");
    puts("Digite 4 -> Para fechar o programa");
}

void menu2(){
    puts("Deseja ver alguma informacao?");
    puts("Para criar ou ver seus objetivos - Digite 1");
    puts("Para ver os seus amigos - Digite 2");
    puts("Para ver as garotas que voce conhece - Digite 3");
    puts("Para ver os seus grandes dias - Digite 4");
    puts("Para ver as surpresas - Digite 5");
    puts("Para ver os melhores feitos - Digite 6");
    puts("Para voltar ao menu principal - Digite 7");
}
