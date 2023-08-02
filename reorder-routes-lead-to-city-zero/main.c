#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int number;
    char* direct;
    char* reverse;
} conn;

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {

    conn* conns = malloc(n*sizeof(conn));
    for (int i = 0; i < n; i++) {
        conns[i].number = i;
        conns[i].direct = malloc(n);
        conns[i].reverse = malloc(n);
        memset(conns[i].direct, 0, n);
        memset(conns[i].reverse, 0, n);
    }


    for (int i = 0; i < n-1; i++) {
        int from = connections[i][0];
        int to = connections[i][1];

        conns[from].direct[to] = 1;
        conns[to].reverse[from] = 1;
    }

    char* visited = malloc(n);
    memset(visited, 0, n);
    visited[0] = 1;
    int* next_direct = malloc(n*sizeof(int));
    int* next_reverse = malloc(n*sizeof(int));

    int nd = -1; // .size() equivalent for the c++ deque
    int nr = -1; // .size() equivalent for the c++ deque


    for (int i = 0; i < n; i++) {
        if (conns[0].direct[i]) {
            next_direct[++nd] = i;
        }
        if (conns[0].reverse[i]) {
            next_reverse[++nr] = i;
        }
    }

    int reorders = 0;
    while (nd > -1 || nr > -1) {
        int cur = 0;
        if (nr > -1) {
            cur = next_reverse[nr--];
            visited[cur] = 1;
            printf("let alone: %d\n", cur);
        }
        else {
            cur = next_direct[nd--];
            if (visited[cur]) continue;
            reorders++;
            visited[cur] = 1;
            printf("reverse: %d\n", cur);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (conns[cur].direct[i]) {
                    next_direct[++nd] = i;
                }
                if (conns[cur].reverse[i]) {
                    next_reverse[++nr] = i;
                }
            }
        }
    }

    return reorders;
};

int main() {

    int n = 5;
    int** conns = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i ++)
        conns[i] = malloc(2*sizeof(int));

    conns[0][0] = 0;
    conns[0][1] = 1;

    conns[1][0] = 1;
    conns[1][1] = 3;

    conns[2][0] = 2;
    conns[2][1] = 3;

    conns[3][0] = 4;
    conns[3][1] = 0;

    conns[4][0] = 4;
    conns[4][1] = 5;

    printf("%d\n", minReorder(6, conns, 0, 0));
}
