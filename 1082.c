#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 26

int main() {
    int totalCasos;
    if (scanf("%d", &totalCasos) != 1) return 0;

    for (int caso = 1; caso <= totalCasos; caso++) {

        int qtdVertices, qtdArestas;
        scanf("%d %d", &qtdVertices, &qtdArestas);

        bool adj[MAX_VERTICES][MAX_VERTICES];
        bool visitado[MAX_VERTICES];

        for (int i = 0; i < MAX_VERTICES; i++) {
            visitado[i] = false;
            for (int j = 0; j < MAX_VERTICES; j++)
                adj[i][j] = false;
        }

        for (int i = 0; i < qtdArestas; i++) {
            char uChar, vChar;
            scanf(" %c %c", &uChar, &vChar);

            int u = uChar - 'a';
            int v = vChar - 'a';

            if (u >= 0 && u < qtdVertices && v >= 0 && v < qtdVertices) {
                adj[u][v] = adj[v][u] = true;
            }
        }

        int qtdComponentes = 0;
        char componentes[MAX_VERTICES][MAX_VERTICES + 1];
        int tamComponente[MAX_VERTICES];

        for (int i = 0; i < qtdVertices; i++) {
            if (!visitado[i]) {
                
                int pilha[MAX_VERTICES];
                int topo = 0;

                pilha[topo++] = i;
                visitado[i] = true;

                bool pertence[MAX_VERTICES];
                for (int k = 0; k < qtdVertices; k++)
                    pertence[k] = false;

                while (topo > 0) {
                    int atual = pilha[--topo];
                    pertence[atual] = true;

                    for (int viz = 0; viz < qtdVertices; viz++) {
                        if (adj[atual][viz] && !visitado[viz]) {
                            visitado[viz] = true;
                            pilha[topo++] = viz;
                        }
                    }
                }

                int idx = 0;
                for (int v = 0; v < qtdVertices; v++) {
                    if (pertence[v]) {
                        componentes[qtdComponentes][idx++] = (char)('a' + v);
                    }
                }
                componentes[qtdComponentes][idx] = '\0';
                tamComponente[qtdComponentes] = idx;

                qtdComponentes++;
            }
        }

        // saída
        printf("Case #%d:\n", caso);

        for (int c = 0; c < qtdComponentes; c++) {
            for (int k = 0; k < tamComponente[c]; k++) {
                printf("%c,", componentes[c][k]);
            }
            printf("\n");
        }
        printf("%d connected components\n", qtdComponentes);

        printf("\n");
    }

    return 0;
}
