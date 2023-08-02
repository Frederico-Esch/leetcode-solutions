#include <stdlib.h>
#include <stdio.h>

void rotate(int** matrix, int matrixSize, int*matrixColSize){
    int n = matrixSize;
    int temp;

    int x[4]; //aux for rotation
    int y[4]; //aux for rotation
    int v[4]; //aux for rotation

    for (int j = 0; j < n/2; j++) {
        for (int i = j; i < n-j-1; i++) {

            y[0] = j;
            x[0] = i;
            //v[0] = matrix[x[0]][y[0]];
            for (int k = 1; k < 4; k++) {
                y[k] = x[k-1];
                x[k] = n-y[k-1]-1;
                //v[k] = matrix[x[k]][y[k]];
            }

            //y[1] = x[0];
            //x[1] = n-y[0]-1;

            //y[2] = x[1];
            //x[2] = n-y[1]-1;

            //y[3] = x[2];
            //x[3] = n-y[2]-1;

            //v[0] = matrix[x[0]][y[0]];
            //v[1] = matrix[x[1]][y[1]];
            //v[2] = matrix[x[2]][y[2]];
            //v[3] = matrix[x[3]][y[3]];

            for (int k = 0; k < 4; k++) {
                //matrix[x[k]][y[k]] = v[(k+1)%4];
            }

            printf("%d %d -> %d %d\n%d %d -> %d %d\n%d %d -> %d %d\n%d %d -> %d %d\n",
                x[0], y[0], x[1], y[1],
                x[1], y[1], x[2], y[2],
                x[2], y[2], x[3], y[3],
                x[3], y[3], x[0], y[0]
            );
            puts("\n");
        }
    }

}

int main() {
    rotate(NULL, 3, NULL);
    return 0;
}
