#include <stdio.h>
#include <string.h>

#define MAX_EXPR_LENGTH 1001
#define MAX_EXPRESSIONS 10000

int verificar_parenteses(char *expressao) {
    int pilha[MAX_EXPR_LENGTH];
    int topo = -1;
    int i;
    
    for (i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            pilha[++topo] = '(';
        } else if (expressao[i] == ')') {
            if (topo == -1) {
                return 0;
            }
            topo--;
        }
    }
    
    return (topo == -1);
}

int main() {
    char expressao[MAX_EXPR_LENGTH];
    char resultados[MAX_EXPRESSIONS][20];
    int count = 0;
    
    while (fgets(expressao, MAX_EXPR_LENGTH, stdin) != NULL) {
        int len = strlen(expressao);
        if (len > 0 && expressao[len - 1] == '\n') {
            expressao[len - 1] = '\0';
        }
        
        if (verificar_parenteses(expressao)) {
            strcpy(resultados[count], "correct");
        } else {
            strcpy(resultados[count], "incorrect");
        }
        count++;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%s\n", resultados[i]);
    }
    
    return 0;
}