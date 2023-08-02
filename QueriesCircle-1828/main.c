#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){

    *returnSize = queriesSize;
    int* result = malloc(queriesSize*sizeof(int));
    memset(result, 0, queriesSize*sizeof(int));

    int x, y, cx, cy, r;
    for ( int q = 0; q < queriesSize; q++) {

        for (int p = 0; p < pointsSize; p++) {
            //point "p" for query "q"

            x = points[p][0];
            y = points[p][1];
            cx = queries[q][0];
            cy = queries[q][1];
            r = queries[q][2];

            if (((x - cx)*(x - cx) + (y - cy)*(y - cy)) <= r*r){
                result[q] += 1;
            }

        }

    }

    return result;
}

int main() {
    return 0;
}
