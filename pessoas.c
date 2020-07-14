/* Arquivo que conterá as funções que implementarão uma
lista encadeada dentro de outra
*/
#include "global.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pessoas.h"
#include "info.h"
#include "fatos.h"

// primeira funcao será a funcão principal que manipulara a lista interna
//void soletra(char * nome);
void principal_amigos(pessoa * no){
    no->amigos = NULL;
    char nom[25];
    strcpy(nom,no->nome);
    tira_espacos(nom);
    strcat(nom,"a.txt");
   // printf("Nome: %s",nom);
    no->amigos = carrega_dados(no->amigos,nom);
    int op;
    while(op != 3){
        limpa_tela();
        menu3_amigos();
        scanf("%d",&op);
        if ( op == 1)
            no->amigos = insercao_pessoas(no->amigos,nom);
        else if (op == 2){
            limpa_tela();
            printf("Amigos do %s\n", no->nome);
            exibe(no->amigos);
        }
        else if (op == 3)
            no->amigos = exclui(no->amigos);
        else
            puts("Digite somente numeros de 1 ate 3");
    }
}



void principal_garotas(pessoa * no){
    no->garotas = NULL;
    char nom[25];
    strcpy(nom,no->nome);
    tira_espacos(nom);
    strcat(nom,"g.txt");
   // printf("Nome: %s",nom);
    no->garotas = carrega_dados(no->garotas,nom);
    int op;
    while(op != 3){
        limpa_tela();
        menu3_garotas();
        scanf("%d",&op);
        if ( op == 1)
            no->garotas = insercao_pessoas(no->garotas,nom);
        else if (op == 2){
            limpa_tela();
            printf("Garotas do %s\n", no->nome);
            exibe(no->garotas);
        }
        else if (op == 3)
            no->garotas = exclui(no->garotas);
        else
            puts("Digite somente numeros de 1 ate 3");
    }
}

void menu3_amigos(){
    puts("--------  Amigos ---------");
    puts("Para adicionar amigos -> Digite 1");
    puts("Para exibir -> Digite 2");
    puts("Para sair -> Digite 3");
}

void menu3_garotas(){
    puts("--------  Garotas ---------");
    puts("Para adicionar garotas -> Digite 1");
    puts("Para exibir -> Digite 2");
    puts("Para sair -> Digite 3");
}




struct pessoas * insercao_pessoas (struct pessoas * head, char * nomearq){ // a inserção será sempre no inicio
    struct pessoas * no = (struct pessoas *) malloc(sizeof(struct pessoas));
    fflush(stdin);
    nomes_fgets(no->nome);
    FILE * arq = fopen(nomearq,"a");
    if (arq){
        fprintf(arq,"%s",no->nome);
    }
    else{
        puts("Erro, nao foi possivel salvar os dados\n");
    }
    no->prox = head;
    fclose(arq);
    return no;
};


void  exibe (struct pessoas * head){ // exibicao dos amigos ou garotas
    struct pessoas * ite;
    for(ite = head; ite != NULL; ite = ite->prox){
        printf("%s\n",ite->nome);
    }
    puts("Digite enter para continuar");
    fflush(stdin);
    getchar();
}

struct pessoas * exclui (struct pessoas * head){
    struct pessoas * ite;
    while (head != NULL){
        ite = head->prox;
        free(head);
        head = ite;
    }
    return head;
}
/*
void soletra(char * nome){
    int i=0;
    while (nome[i] != '\0'){
        printf("%c\n",nome[i++]);
    }
}
*/
struct pessoas * carrega_dados(struct pessoas * head, char * nomearq){
    FILE * arq = fopen(nomearq,"r");
    if (arq){
        while(!feof(arq)){
            struct pessoas * ite = (struct pessoas *) malloc(sizeof(struct pessoas));
            if (fgets(ite->nome,54,arq)){
           //     soletra(ite->nome);
            // erro na leitura, algum caracter fica sobrando ne leitura
            //printf(" O que esta sendo lido: %s",ite->nome);
                ite->prox = head;
                head = ite;
            }
        }
        fclose(arq);
        return head;
    }
    else
    {
        fclose(arq);
        puts("Erro, o arquivo nao pode ser aberto");
        return NULL;
    }
}
