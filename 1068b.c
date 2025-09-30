#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_LENGTH 1001
#define MAX_EXPRESSIONS 10000

// Estrutura do nó da pilha
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* criar_node(char data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->next = NULL;
    return novo;
}

// Função para empilhar (push)
void push(Node** topo, char data) {
    Node* novo = criar_node(data);
    novo->next = *topo;
    *topo = novo;
}

// Função para desempilhar (pop)
char pop(Node** topo) {
    if (*topo == NULL) {
        return '\0'; // Pilha vazia
    }
    Node* temp = *topo;
    char data = temp->data;
    *topo = (*topo)->next;
    free(temp);
    return data;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(Node* topo) {
    return topo == NULL;
}

// Função para liberar a pilha
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
            // Empilha o parênteses aberto
            push(&pilha, '(');
        } else if (expressao[i] == ')') {
            // Se encontrar um fecha parênteses e a pilha estiver vazia, está incorreto
            if (pilha_vazia(pilha)) {
                liberar_pilha(&pilha);
                return 0; // incorrect
            }
            // Desempilha o parênteses aberto correspondente
            pop(&pilha);
        }
    }
    
    // Verifica se a pilha está vazia no final
    int resultado = pilha_vazia(pilha);
    
    // Libera a memória da pilha
    liberar_pilha(&pilha);
    
    return resultado;
}

int main() {
    char expressao[MAX_EXPR_LENGTH];
    char resultados[MAX_EXPRESSIONS][20];
    int count = 0;
    
    // Ler todas as expressões até EOF
    while (fgets(expressao, MAX_EXPR_LENGTH, stdin) != NULL) {
        // Remover o '\n' do final se existir
        int len = strlen(expressao);
        if (len > 0 && expressao[len - 1] == '\n') {
            expressao[len - 1] = '\0';
        }
        
        // Verificar se a expressão está correta
        if (verificar_parenteses(expressao)) {
            strcpy(resultados[count], "correct");
        } else {
            strcpy(resultados[count], "incorrect");
        }
        count++;
    }
    
    // Imprimir todos os resultados
    for (int i = 0; i < count; i++) {
        printf("%s\n", resultados[i]);
    }
    
    return 0;
}