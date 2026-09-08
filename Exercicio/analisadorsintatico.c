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

int simbolo_lido; 


//Definindo os simbolos/tokens
void obtenha_simbolo(){
    char a = getchar();
    while(a == '\n' || a == '\t'){ //Ignorar os enter e as tabulacoes
        a = getchar();
    }
        if(a >= '0' || a <= 9){
            simbolo_lido = NUMERO;
    }
        if(a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'){
            simbolo_lido = IDENT; 
        }
        else if(a == '+'){
            simbolo_lido = MAIS;
        }
        else if(a == '*'){
            simbolo_lido = MULT;
        }
        else if(a == '('){
            simbolo_lido = ABRE_PAR;
        }
        else if(a == ')'){
            simbolo_lido = FECHA_PAR;
        }
        else if(a == '**'){
            simbolo_lido = POTENCIA;
        }
        else if(a == '\n'){
            simbolo_lido = FIM;
        }
        

    }





//AINDA RPECISA DE CORREÇÕES !!!



void analisador_sintatico(){
    char simbolo_lido = obtenha_simbolo();
    EXP();
    if(simbolo_lido == FIM){
        printf("\nExpressao valida");
    }
    else{
        printf("\nSimbolo inesperado!");
        return;
    }

    return FIM;

}

void PRIMARIO(int simbolo_lido){
    if(simbolo_lido == IDENT){
        obtenha_simbolo();
    }
    else if(simbolo_lido == NUMERO){
        obtenha_simbolo();
    }
    else if(simbolo_lido = '('){
        obtenha_simbolo();
        EXP();
        if(simbolo_lido != ')'){
            printf("\nERRO! FALTA ')'");
            return;
        }
        else{
            obtenha_simbolo();
        }
    }
    else{
        printf("\nERRO: Primario inválido!");
        return;
    }

    return FIM;
}


void FATOR(){
    char simbolo_lido;
    PRIMARIO(simbolo_lido);
    if(simbolo_lido = '**'){
        obtenha_simbolo();
        FATOR();
    }

    return FIM;
}


int main(){
    int simbolo_lido; 






    return 0;
}