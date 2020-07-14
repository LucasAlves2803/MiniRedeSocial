#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "objetivos.h"
#include "fatos.h"
#include "info.h"


void principal_objetivos(pessoa * no){
    no->meus_objetivos = NULL;
    char nom[50];
    strcpy(nom,no->nome);
    tira_espacos(nom);
    strcat(nom,"obj.txt");
    no->meus_objetivos = carrega_dados_obj(no->meus_objetivos,nom);
    verifica_objetivo(no->meus_objetivos, nom, no);
    int op;
    do {
    limpa_tela();
    menu_objetivos();
    fflush(stdin);
    scanf("%d",&op);
        if (op == 1){
            no->meus_objetivos = insercao_obj(no->meus_objetivos,nom);
        }
        else if (op == 2){
            exibe_objetivos(no->meus_objetivos);
        }
        else if (op == 3){
            limpa_tela();
           sucessos(no->nome);
        }
        else if (op == 4){
           limpa_tela();
           fracassos(no->nome);
        }
        else if (op != 5){
            puts("Digite somente numeros de 1 ate 5");
            Sleep(1300);
        }
        else
            no->meus_objetivos = deleta_lista(no->meus_objetivos);
    }while (op != 5);
}



struct objetivos * insercao_obj(struct objetivos * head, char * nome){
        FILE * arq = fopen(nome,"a");
        if (arq){
            struct objetivos * novo = (struct objetivos *) malloc(sizeof(struct objetivos));
            fflush(stdin);
            titulo_obj(novo->titulo);
            novo->day = prazo_obj();
            fprintf(arq,"%s",novo->titulo);
            fprintf(arq,"%d %d %d\n", novo->day.dia, novo->day.mes, novo->day.ano);
            novo->prox = head; // quando o objetivo ainda não tiver terminado o prazo coloco a informação com dado 3
            head = novo;  // se já
            fclose(arq);
        }
        else{
            puts("Erro na gravacao dos dados");
        }
    return head;
}

struct objetivos * carrega_dados_obj(struct objetivos * head, char * nome){
        FILE * arq = fopen(nome,"r");
        if (arq){
            while(!feof(arq)){
                struct objetivos * no = (struct objetivos *) malloc(sizeof(struct objetivos));
                if (fgets(no->titulo,60,arq)){
                    fflush(stdin);
                    fscanf(arq,"%d %d %d\n", &no->day.dia, &no->day.mes, &no->day.ano);
                    no->prox = head;
                    head = no;
                }
            }
            fclose(arq);
        }
        else{
            puts("Erro na leitura dos dados");
        }
        return head;
}

struct objetivos * deleta_lista( struct objetivos * head){
    struct objetivos * temp;
    while(head){
        temp = head->prox;
        free(head);
        head = temp;
    }
    return head;
}

void exibe_objetivos(struct objetivos * head){
    struct objetivos * ite;
    limpa_tela();
    puts("Seus objetios atuais");
    for (ite = head; ite != NULL; ite = ite->prox){
        printf("%s", ite->titulo);
    }
    puts("Digite enter para voltar ao menu Objetivos");
    fflush(stdin);
    getchar();
}

void titulo_obj (char * nome){
    printf("De um titulo para o objetivo:\n");
    fgets(nome,55,stdin);
}

struct Data data_atual_obj(){
    struct Data da;
    SYSTEMTIME st;
    GetSystemTime(&st);
    da.ano = st.wYear;
    da.mes = st.wMonth;
    da.dia = st.wDay;
    return da;
}

struct Data prazo_obj(){
   struct Data dia;
   int prazo=0;
   printf("De um prazo, em dias, para cumprir o objetivo:");
   scanf("%d",&prazo);
   dia = calculo_dias(prazo);
   return dia;
}

void fracassos(char * nome){
    char nome_temp[35];
    strcpy(nome_temp,nome);
    tira_espacos(nome_temp);
    strcat(nome_temp,"_obj_f.txt");
    FILE * arq = fopen(nome_temp,"r");
    puts("======= Fracassos ========");
    puts("Infelizmente voce nao cumpriu esses objetivos");
    if (arq){
        while(!feof(arq)){
            char obj[60];
            if (fgets(obj,60,arq)){
                printf("%s",obj);
                if(menu4_impressao())
                    imprime(obj);
              fflush(stdin);
              puts("Digite enter para continuar");
              getchar();
              limpa_tela();
            }
        }
    }
    else{
        puts("Erro");
    }
}

void sucessos(char * nome){
    char nome_temp[35];
    strcpy(nome_temp,nome);
    tira_espacos(nome_temp);
    strcat(nome_temp,"_obj_s.txt");
    FILE * arq = fopen(nome_temp,"r");
    puts("======= Sucessos ========");
    puts("Parabens! voce cumpriu esses objetivos: ");
    if (arq){
        while(!feof(arq)){
            char obj[60];
            if (fgets(obj,60,arq)){
                printf("%s",obj);
                if(menu4_impressao())
                    imprime(obj);
                fflush(stdin);
                puts("Digite enter para continuar");
                getchar();
                limpa_tela();
            }
        }
    }
    else{
        puts("Erro");
    }
    fflush(stdin);
}

struct Data calculo_dias(int prazo){
    struct Data da = data_atual_obj();
    while (prazo){
        int intervalo;
        switch (da.mes){
            case 1:
                if (da.dia + prazo >= 31){
                    intervalo = 31 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 2:
                if (da.dia + prazo >= 29){
                    intervalo = 29 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 3:
                if (da.dia + prazo >= 31){
                    intervalo = 31 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 4:
                if (da.dia + prazo >= 30){
                    intervalo = 30 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 5:
                if (da.dia + prazo >= 31){
                    intervalo = 31 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 6:
                if (da.dia + prazo >= 30){
                    intervalo = 30 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 7:
                if (da.dia + prazo >= 31){
                    intervalo = 31 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 8:
                if (da.dia + prazo >= 31){
                    intervalo = 31 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 9:
                if (da.dia + prazo >= 30){
                    intervalo = 30 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 10:
                if (da.dia + prazo >= 31){
                    intervalo = 31 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 11:
                if (da.dia + prazo >= 30){
                    intervalo = 30 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.dia =0;
                }
               else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
            case 12:
                if (da.dia + prazo >= 31){
                    intervalo = 31 - da.dia;
                    prazo -= intervalo;
                    da.mes++;
                    da.ano++;
                    da.dia =0;
                }
                else{
                    da.dia += prazo;
                    prazo =0;
                }
                break;
        }
    }
    return da;
}
void menu_objetivos(){
    puts("------ Objetivos ------");
    puts("Para criar um objetivo - Digite 1");
    puts("Para ver seus objetivos - Digite 2");
    puts("Para ver os objetivos cumpridos - Digite 3");
    puts("Para ver os objetivos fracassados - Digite 4");
    puts("Para sair - Digite 5");
}

void verifica_objetivo(struct objetivos * head, char * nome,pessoa * no){
    struct objetivos * ite;
    ite = head;
    struct Data dia;
    int bol=1;
    dia = data_atual_obj();
    FILE *  arq = fopen(nome,"w");
    if (arq){
        for (; ite != NULL; ite = ite->prox){
            if (dia.ano >= ite->day.ano){
                    if (dia.mes >= ite->day.mes){
                            if (dia.dia >= ite->day.dia){
                                bol = 0;
                                printf("Fim do prazo para cumprir o objetivo: %s ",ite->titulo);
                                puts("Voce cumpriu?");
                                puts("Se sim - Digite 1");
                                puts("Se nao - Digite 0");
                                do{
                                    fflush(stdin);
                                    scanf("%d", &ite->bol);
                                    if (ite->bol != 0 && ite->bol != 1)
                                        puts("Digite somente 1 ou 0");
                                } while(ite->bol != 0 && ite->bol != 1);
                                char nome_temp[25];
                                if (ite->bol){
                                  strcpy(nome_temp, no->nome);
                                  tira_espacos(nome_temp);
                                  strcat(nome_temp,"_obj_s.txt");
                                  FILE * arq3 = fopen(nome_temp,"a");
                                  if (arq3){
                                    fprintf(arq3,"%s",ite->titulo);
                                    descricao(ite->titulo);// função que pede uma descrição do que aconteceu
                                  }
                                  fclose(arq3);
                                }
                                else{
                                    strcpy(nome_temp, no->nome);
                                    tira_espacos(nome_temp);
                                    strcat(nome_temp,"_obj_f.txt"); // stquivo com objetivos fracassados
                                    FILE * arq2 = fopen(nome_temp,"a");
                                    if (arq2){
                                    fprintf(arq2,"%s",ite->titulo);
                                    descricao(ite->titulo);
                                    }
                                    fclose(arq2);
                                }
                                }
                                if (ite->bol){
                                    (no->sucessos)++;
                                }
                                else
                                    (no->fracassos)++;
                            }
                if (bol){
                        fprintf(arq,"%s",ite->titulo);
                        fprintf(arq,"%d %d %d\n", ite->day.dia, ite->day.mes, ite->day.ano);
                }
            }
         bol=1;
         }
      }
    fclose(arq);
}
