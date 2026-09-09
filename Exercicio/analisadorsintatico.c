#include <stdio.h>
#include <stdlib.h>
#define IDENT 1
#define NUMERO 2
#define MAIS 3
#define MULT 4
#define POTENCIA 5
#define ABRE_PAR 6
#define FECHA_PAR 7
#define FIM 8
#include "analisadorsintatico.h"

int simbolo_lido;

void obtenha_simbolo(){
    char a = getchar();
    while(a == '\n' || a == '\t' || a == ' '){
        a = getchar();
    }

    if(a >= '0' && a <= '9'){
        simbolo_lido = NUMERO;
    }
    else if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
        simbolo_lido = IDENT;
    }
    else if(a == '+'){
        simbolo_lido = MAIS;
    }
    else if(a == '*'){
        char proximo = getchar();
        if(proximo == '*'){
            simbolo_lido = POTENCIA;
        } else {
            ungetc(proximo, stdin);
            simbolo_lido = MULT;
        }
    }
    else if(a == '('){
        simbolo_lido = ABRE_PAR;
    }
    else if(a == ')'){
        simbolo_lido = FECHA_PAR;
    }
    else if(a == '\n' || a == EOF){
        simbolo_lido = FIM;
    }
    else {
        printf("\nCARACTER INVALIDO!");
    }
    printf("\nToken reconhecido: %d\n", simbolo_lido);
}

void analisador_sintatico(){
    printf("\n----INICIO DA ANALISE SINTATICA----");
    obtenha_simbolo();
    EXPR();
    if(simbolo_lido == FIM){
        printf("\nExpressao valida\n");
    } else {
        printf("\nSimbolo inesperado!\n");
        return;
    }
}

void PRIMARIO(){
    printf("\n-PRIMARIO\n");
    if(simbolo_lido == IDENT){
        obtenha_simbolo();
    }
    else if(simbolo_lido == NUMERO){
        obtenha_simbolo();
    }
    else if(simbolo_lido == ABRE_PAR){
        obtenha_simbolo();
        EXPR();
        if(simbolo_lido != FECHA_PAR){
            erro("Falta o ')");
        } else {
            obtenha_simbolo();
        }
    }
    else {
        erro("primario invalido");
    }
}

void FATOR(){
    printf("\n-FATOR\n");
    PRIMARIO();
    if(simbolo_lido == POTENCIA){
        obtenha_simbolo();
        FATOR();
    }
}

void TERMO(){
    printf("\n-TERMO\n");
    FATOR();
    if(simbolo_lido == MULT){
        obtenha_simbolo();
        TERMO();
    }
}

void EXPR(){
    printf("\n-EXPR\n");
    TERMO();
    if(simbolo_lido == MAIS){
        obtenha_simbolo();
        EXPR();
    }
}

void erro(char *mensagem) {
    printf("\nerro sintatico no programa: %s\n", mensagem);
    exit(1); 
}