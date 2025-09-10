#include <stdio.h>
#include <stdlib.h>

// Definição de true e false
#define verdadeiro 1
#define falso 0

// Definição de tipos
typedef struct No {
    char caractere;
    struct No *proximo;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

// Protótipos de funções
void inicializarPilha(Pilha *);
void empilhar(Pilha *, char);
char desempilhar(Pilha *);
char topo(Pilha *);
void infixaParaPosfixa(char *);
int prioridade(char, char);

// Função principal
int main() {
    char expressao[400];
    unsigned short numCasos;

    scanf("%hu", &numCasos);

    while (numCasos--) {
        scanf("%s", expressao);
        infixaParaPosfixa(expressao);
    }

    return 0;
}

// Função para converter de notação infixa para posfixa
void infixaParaPosfixa(char *expressao) {
    int i = 0;
    char caractereAtual, topoPilha;
    Pilha pilha;

    inicializarPilha(&pilha);
    empilhar(&pilha, '(');

    do {
        caractereAtual = expressao[i++];
        
        if ((caractereAtual >= 'A' && caractereAtual <= 'Z') || 
            (caractereAtual >= '0' && caractereAtual <= '9') || 
            (caractereAtual >= 'a' && caractereAtual <= 'z')) {
            printf("%c", caractereAtual);
        } else if (caractereAtual == '(') {
            empilhar(&pilha, '(');
        } else if (caractereAtual == ')' || caractereAtual == '\0') {
            do {
                topoPilha = desempilhar(&pilha);
                if (topoPilha != '(')
                    printf("%c", topoPilha);
            } while (topoPilha != '(');
        } else if (caractereAtual == '+' || caractereAtual == '-' || caractereAtual == '*' || 
                   caractereAtual == '^' || caractereAtual == '/') {
            while (verdadeiro) {
                topoPilha = desempilhar(&pilha);
                if (prioridade(caractereAtual, topoPilha)) {
                    empilhar(&pilha, topoPilha);
                    empilhar(&pilha, caractereAtual);
                    break;
                } else {
                    printf("%c", topoPilha);
                }
            }
        }
    } while (caractereAtual != '\0');

    printf("\n");
}

// Função para inicializar a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

// Função para empilhar um caractere
void empilhar(Pilha *pilha, char caractere) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo)
        exit(1);

    novoNo->caractere = caractere;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

// Função para desempilhar um caractere
char desempilhar(Pilha *pilha) {
    if (pilha->topo == NULL)
        return '\0';

    No *temp = pilha->topo;
    char caractere = temp->caractere;
    pilha->topo = temp->proximo;
    free(temp);

    return caractere;
}

// Função para obter o topo da pilha
char topo(Pilha *pilha) {
    if (pilha->topo == NULL)
        return '\0';

    return pilha->topo->caractere;
}

// Função para determinar a prioridade de operadores
int prioridade(char operadorAtual, char topoPilha) {
    int prioridadeAtual, prioridadeTopo;

    if (operadorAtual == '^')
        prioridadeAtual = 3;
    else if (operadorAtual == '*' || operadorAtual == '/')
        prioridadeAtual = 2;
    else if (operadorAtual == '+' || operadorAtual == '-')
        prioridadeAtual = 1;
    else if (operadorAtual == '(')
        prioridadeAtual = 4;

    if (topoPilha == '^')
        prioridadeTopo = 3;
    else if (topoPilha == '*' || topoPilha == '/')
        prioridadeTopo = 2;
    else if (topoPilha == '+' || topoPilha == '-')
        prioridadeTopo = 1;
    else if (topoPilha == '(')
        prioridadeTopo = 0;

    return (prioridadeAtual > prioridadeTopo);
}