#include "pessoas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"
#include "info.c"




pessoa * reinicia(pessoa * cab){
    FILE * arq = fopen("dados_da_lista.txt","r");
    if (!arq){
        cab = insere_info(cab);
        return NULL;
    }
    else{
            while (!feof(arq) ){
                pessoa * no = (pessoa *) malloc(sizeof(pessoa));
                fgets(no->nome,55,arq);
                fscanf(arq,"%d\n %f\n",&no->idade,&no->dinheiro);
                //printf("%s",no->nome);
                no->prox = cab;
                cab = no;
            }
    }
    fclose(arq);
    return cab;
}
pessoa * pag1(pessoa * phead){ // primeiro menu do programa
    int op =0;
    while (op != 4){
        menu();
        scanf("%d",&op);
        if (op == 1){
            imprime_usuarios(phead);
        }
        else if (op == 2){
            phead = insere_info(phead);
        }
        else if (op == 3){
            usuario(phead);
        }
        else if (op != 4){
            printf("Digite somente os numeros 1,2,3 ou 4\n");
        }
        limpa_tela();
    }
   return phead;
}

pessoa * cria_no(char * nom){
    FILE * arq = fopen("dados_da_lista.txt","a");
    pessoa * no = (pessoa *) malloc(sizeof(pessoa));
    strcpy(no->nome,nom);
    no->idade = idades();
    no->dinheiro = carteira();
    fprintf(arq,"%s",no->nome);
    fprintf(arq,"%d\n",no->idade);
    fprintf(arq,"%.2f\n",no->dinheiro);
    no->prox = NULL;
    fclose(arq);
    return no;
}

pessoa * insere_info(pessoa * phead){
    char nome[15];
    fflush(stdin);
    nomes_fgets(nome);
    while (!cadastro(phead,nome)){
        puts("Nome ja existente");
        puts("Digite novamente");
        nomes_fgets(nome);
        fflush(stdin);
    }
    pessoa * no = cria_no(nome);
    // criar uma função de busca para não ter duas pessoas com o mesmo nome
    no->prox = phead;

    return no;
}

pessoa * user(pessoa * phead, char * nome){
    pessoa * ite;
    for (ite = phead ; ite != NULL; ite = ite->prox){
        if (!strcmp(ite->nome,nome)){
            return ite;
        }
    }
    return NULL;
}





pessoa * apaga_lista(pessoa * phead){
    pessoa * ite =  NULL;
    while (phead != NULL){
        ite = phead->prox;
        phead = NULL;
        free(phead);
        phead = ite;
    }
    return phead;
}


void usuario(pessoa * phead){
    char nome[55];
    fflush(stdin);
    nomes_fgets(nome);
    pessoa * no = user(phead,nome);
    if (no)
        exibicao(no);
    else
        puts("usuario inexistente");
}
