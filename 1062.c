#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char resultados[10000][5];
    int idx = 0;

    while (scanf("%d", &N) && N != 0) {
        while (1) {
            int a[1000];
            scanf("%d", &a[0]);
            if (a[0] == 0) {
                strcpy(resultados[idx++], "");
                break;
            }

            for (int i = 1; i < N; i++)
                scanf("%d", &a[i]);

            int stack[1000];
            int top = -1;
            int next = 1;
            int possible = 1;

            for (int i = 0; i < N; i++) {
                int desired = a[i];

                while (next <= N && (top == -1 || stack[top] != desired)) {
                    stack[++top] = next++;
                }

                if (stack[top] == desired) {
                    top--;
                } else {
                    possible = 0;
                    break;
                }
            }

            if (possible)
                strcpy(resultados[idx++], "Yes");
            else
                strcpy(resultados[idx++], "No");
        }
    }

    for (int i = 0; i < idx; i++) {
        if (strlen(resultados[i]) == 0)
            printf("\n");
        else
            printf("%s\n", resultados[i]);
    }

    return 0;
}
