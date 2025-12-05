#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int tc = 0; tc < T; tc++) {
        int inicio;
        scanf("%d", &inicio);

        int V, A;
        scanf("%d %d", &V, &A);

        int maxV = V > 100 ? V : 100;
        static int adj[100][100];
        
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;

        int u, v;
        int arestasUnicas = 0;
        for (int i = 0; i < A; i++) {
            scanf("%d %d", &u, &v);
            if (u < 0 || v < 0 || u >= V || v >= V) {
                continue;
            }
            
            int a = u < v ? u : v;
            int b = u < v ? v : u;
            if (!adj[a][b]) {
                adj[a][b] = 1;
                adj[b][a] = 1;
                arestasUnicas++;
            }
        }

        int movimentos = 2 * arestasUnicas;
        printf("%d\n", movimentos);
    }

    return 0;
}
