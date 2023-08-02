#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int h = matrixSize, w = matrixColSize[0];
    int n = w*h;
    *returnSize = n;
    int* result = malloc(sizeof(int) * n);

    int x = 0, y = 0;
    int idx;
    int dc[] = { 0, 1, 0, -1 };
    int dr[] = { 1, 0, -1, 0 };
 
    int di = 0;
    bool* seen = malloc(w*h*sizeof(bool));
    memset(seen, false, w*h*sizeof(bool));
 
    for (idx = 0; idx < w * h; idx++) {
        result[idx] = matrix[y][x];

        seen[y*w + x] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];
 
        if (0 <= newX && newX < w && 0 <= newY && newY < h) {
            if (!seen[newY*w + newX]){
                x = newX;
                y = newY;
            }
            else {
                di = (di + 1) % 4;
                x += dr[di];
                y += dc[di];
            }
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }

    return result;}

int main() {
    int** matrix = malloc(3*sizeof(int*));
    matrix[0] = malloc(4*sizeof(int));
    matrix[1] = malloc(4*sizeof(int));
    matrix[2] = malloc(4*sizeof(int));

    matrix[0][0] = 1;matrix[0][1] = 2;matrix[0][2] = 3;matrix[0][3] = 4;
    matrix[1][0] = 5;matrix[1][1] = 6;matrix[1][2] = 7;matrix[1][3] = 8;
    matrix[2][0] = 9;matrix[2][1] = 10;matrix[2][2] = 11;matrix[2][3] = 12;

    int matrixSize = 3;
    int matrixColSize[] = { 4, 4, 4 };
    int returnSize;
    printf("Hello World\n");
    int* result = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);
    printf("%d\n", returnSize);
    for (int i = 0 ; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    puts(" ");
    return 0;
}
