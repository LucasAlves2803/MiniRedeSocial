#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "info.h"
//#include "info.c"
#include "fatos.h"


void princ_melhores_feitos(pessoa * no){
    char nome[25];
    no->melhores_feitos = NULL;
    strcpy(nome,no->nome);
    tira_espacos(nome);
    strcat(nome,"g_mf.txt");
    no->melhores_feitos = carrega_dados2(no->melhores_feitos,nome);
    int op;
    while(op != 3){
        limpa_tela();
        menu4_melhores_feitos();
        scanf("%d",&op);
        if ( op == 1){
            no->melhores_feitos = insercao_fatos(no->melhores_feitos,nome);
            descricao(no->melhores_feitos->titulo);
        }
        else if (op == 2){
            printf("Os Melhores feitos do ano do %s\n", no->nome);
            exb(no->melhores_feitos);
        }
        else if (op == 3)
            no->melhores_feitos = apaga(no->melhores_feitos);
        else
            puts("Digite somente numeros de 1 ate 3");
    }

}

void princ_grande_dia(pessoa * no){
    char nome[25];
    no->grande_dia = NULL;
    strcpy(nome,no->nome);
    tira_espacos(nome);
    strcat(nome,"g_d.txt");
    no->grande_dia = carrega_dados2(no->grande_dia,nome);
    int op;
    while(op != 3){
        limpa_tela();
        menu4_grande_dia();
        scanf("%d",&op);
        if ( op == 1){
            no->grande_dia = insercao_fatos(no->grande_dia,nome);
            descricao(no->grande_dia->titulo);
        }
        else if (op == 2){
            printf("Os grandes dia do ano do %s\n", no->nome);
            exb(no->grande_dia);
        }
        else if (op == 3)
            no->grande_dia = apaga(no->grande_dia);
        else
            puts("Digite somente numeros de 1 ate 3");
    }

}

void princ_surpresas(pessoa * no){
    char nome[25];
    no->surpresas = NULL;
    strcpy(nome,no->nome);
    tira_espacos(nome);
    strcat(nome,"g_s.txt");
    printf("Nome: %s\n",nome);
    no->surpresas = carrega_dados2(no->surpresas,nome);
    int op;
    while(op != 3){
        limpa_tela();
        menu4_surpresas();
        scanf("%d",&op);
        if ( op == 1){
            no->surpresas = insercao_fatos(no->surpresas,nome);
            descricao(no->surpresas->titulo);
        }
        else if (op == 2){
            printf("As surpresas do ano do %s\n", no->nome);
            exb(no->surpresas);
        }
        else if (op == 3)
            no->surpresas = apaga(no->surpresas);
        else
            puts("Digite somente numeros de 1 ate 3");
    }

}

void menu4_grande_dia(){
    puts("----------- Grande Dia -----------");
    puts("Para adicionar um grande dia -> Digite 1");
    puts("Para exibir -> Digite 2");
    puts("Para sair -> Digite 3");
}

void menu4_melhores_feitos(){
    puts("--------  Melhores Feitos ---------");
    puts("Para adicionar um feito -> Digite 1");
    puts("Para exibir -> Digite 2");
    puts("Para sair -> Digite 3");
}

void menu4_surpresas(){
    puts("--------  Surpresas ---------");
    puts("Para adicionar uma surpresa -> Digite 1");
    puts("Para exibir -> Digite 2");
    puts("Para sair -> Digite 3");
}



struct fatos * insercao_fatos(struct fatos * head, char * nome){
    struct fatos * no = (struct fatos *) malloc (sizeof(struct fatos ));
    FILE * arq = fopen(nome,"a");
    fflush(stdin);
    titulo(no->titulo);
    no->day = leit();
    if (arq){
        fprintf(arq,"%s",no->titulo);
        fprintf(arq,"%d %d %d\n", no->day.dia, no->day.mes, no->day.ano);
        printf("Dados Salvos\n");
    }
    else{
        puts("Erro na abertura do arquivo");
    }
    no->prox = head;
    return no;
};

void descricao(char * titulo){
    limpa_tela();
    printf("De uma breve descrição sobre: %s",titulo);
    char nome_temp[55];
    strcpy(nome_temp,titulo);
    tira_espacos(nome_temp);
    strcat(nome_temp,".txt");
    //printf("%s",titulo);
    FILE * arq = fopen(nome_temp,"w");
    char c;
    if (arq){
        puts("Para finalizar o texto pressione crtl + F ao mesmo tempo e depois enter");
        c = getchar();
        while (c != 6){
            putc(c,arq);
            c = getchar();
        }
    }
        else{
        puts("Erro na abertura do arquivo");
    }
    fclose(arq);
    limpa_tela();
}


void tira_espacos(char * nome){
    int i=0;
    for (;nome[i] != '\n';i++){
        if (nome[i] == 32){
            nome[i] = 45;
        }
    }
    nome[i] = '\0';
}

void imprime(char * titulo){
    char nome_temp[55];
    strcpy(nome_temp,titulo);
    tira_espacos(nome_temp);
    strcat(nome_temp,".txt");
    FILE * arq = fopen(nome_temp,"r");
    char c;
    if (arq){
        while (!feof(arq)){
            c = fgetc(arq);
            printf("%c",c);
        }
        puts("");
    }else
    puts("Nao ha descricao");
    fclose(arq);
}



void exb(struct fatos * head){
    struct fatos * ite;
    for (ite = head; ite != NULL; ite = ite->prox){
        printf("Titulo:%s",ite->titulo);
        if (menu4_impressao())
            imprime(ite->titulo);
        printf("Data: %d/%d/%d\n",ite->day.dia, ite->day.mes, ite->day.ano);
        puts("");
    }
    puts("Digite enter para continuar");
    fflush(stdin);
    getchar();
}

int menu4_impressao(){
    int op;
    do {
    puts("Deseja ver a descricao desse acontecimento");
    puts("Se sim - Digite 1");
    puts("Se nao - Digite 0");
    fflush(stdin);
    scanf("%d",&op);
    if (op != 1 && op != 0){
        puts("Digite somente 1 ou 0");
    }
    }while (op != 1 && op != 0);
    return op;
}


struct Data leit(){
    struct Data da;
    printf("Data do acontecimento:\n");
    printf("Digite o dia:");
    scanf("%d",&da.dia);
    printf("Digite o mes:");
    scanf("%d",&da.mes);
    printf("Digite o ano:");
    scanf("%d",&da.ano);
    fflush(stdin);
    return da;
}

struct fatos * apaga(struct fatos * head){
 struct fatos * ite;
 while (head != NULL){
    ite = head->prox;
    free(head);
    head = ite;
 }
 return head;
}

void titulo (char * nome){
    printf("De um titulo para esse acontecimento:\n");
    fgets(nome,55,stdin);
}

struct fatos * carrega_dados2(struct fatos * head, char * nome){
    FILE * arq = fopen(nome,"r");
    if (arq){
        while(!feof(arq)){
            struct fatos * no = (struct fatos * ) malloc(sizeof(struct fatos));
            fgets(no->titulo,55,arq);
            fflush(stdin);
            fscanf(arq,"%d %d %d\n", &no->day.dia,&no->day.mes,&no->day.ano);
            //printf("%s %d %d %d\n", no->titulo, no->day.dia,no->day.mes,no->day.ano);
            no->prox = head;
            head = no;
        }
        fclose(arq);
        return head;
    }
    else{
        fclose(arq);
        return NULL;
    }
}
