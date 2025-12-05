#include <stdio.h>
#include <string.h>

#define LIMITE 10000

int inverter(int numero) {
    int invertido = 0;
    while (numero > 0) {
        invertido = invertido * 10 + (numero % 10);
        numero /= 10;
    }
    return invertido;
}

int bfs(int inicio, int alvo) {
    int visitado[LIMITE + 1];
    int fila[LIMITE * 2];
    int passos[LIMITE + 1];

    memset(visitado, 0, sizeof(visitado));

    int frente = 0, tras = 0;

    fila[tras++] = inicio;
    visitado[inicio] = 1;
    passos[inicio] = 0;

    while (frente < tras) {
        int atual = fila[frente++];
        
        if (atual == alvo)
            return passos[atual];

        int soma = atual + 1;
        if (soma <= LIMITE && !visitado[soma]) {
            visitado[soma] = 1;
            passos[soma] = passos[atual] + 1;
            fila[tras++] = soma;
        }

        int inverso = inverter(atual);
        if (inverso <= LIMITE && !visitado[inverso]) {
            visitado[inverso] = 1;
            passos[inverso] = passos[atual] + 1;
            fila[tras++] = inverso;
        }
    }

    return -1;
}

int main() {
    int testes;
    scanf("%d", &testes);

    while (testes--) {
        int numero_inicial, numero_alvo;
        scanf("%d %d", &numero_inicial, &numero_alvo);

        int resultado = bfs(numero_inicial, numero_alvo);
        printf("%d\n", resultado);
    }

    return 0;
}
