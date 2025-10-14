//PILHA ENCADEADA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_LENGTH 1001
#define MAX_EXPRESSIONS 10000

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* criar_node(char data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->next = NULL;
    return novo;
}

void push(Node** topo, char data) {
    Node* novo = criar_node(data);
    novo->next = *topo;
    *topo = novo;
}

char pop(Node** topo) {
    if (*topo == NULL) {
        return '\0';
    }
    Node* temp = *topo;
    char data = temp->data;
    *topo = (*topo)->next;
    free(temp);
    return data;
}

int pilha_vazia(Node* topo) {
    return topo == NULL;
}

void liberar_pilha(Node** topo) {
    while (*topo != NULL) {
        Node* temp = *topo;
        *topo = (*topo)->next;
        free(temp);
    }
}

int verificar_parenteses(char *expressao) {
    Node* pilha = NULL;
    int i;
    
    for (i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            push(&pilha, '(');
        } else if (expressao[i] == ')') {
            
            if (pilha_vazia(pilha)) {
                liberar_pilha(&pilha);
                return 0;
            }
           
            pop(&pilha);
        }
    }
    int resultado = pilha_vazia(pilha);
    liberar_pilha(&pilha);
    
    return resultado;
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
