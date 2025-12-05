#include <stdio.h>

#define MAX 1024

char img[MAX][MAX];
int visitado[MAX][MAX];
int filaX[MAX * MAX];
int filaY[MAX * MAX];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", img[i]);
    }

    int cliques = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (img[i][j] == '.' && !visitado[i][j]) {
                cliques++;

                int ini = 0, fim = 0;
                filaX[fim] = i;
                filaY[fim] = j;
                visitado[i][j] = 1;
                fim++;

                while (ini < fim) {
                    int x = filaX[ini];
                    int y = filaY[ini];
                    ini++;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (img[nx][ny] == '.' && !visitado[nx][ny]) {
                                visitado[nx][ny] = 1;
                                filaX[fim] = nx;
                                filaY[fim] = ny;
                                fim++;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", cliques);
    return 0;
}
