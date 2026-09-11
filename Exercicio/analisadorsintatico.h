#define IDENT 1
#define NUMERO 2
#define MAIS 3
#define MULT 4
#define POTENCIA 5
#define ABRE_PAR 6
#define FECHA_PAR 7
#define FIM 8

void analisador_sintatico();
void obtenha_simbolo();
void EXPR();
void TERMO();
void FATOR();
void PRIMARIO();
void erro(char *mensagem);