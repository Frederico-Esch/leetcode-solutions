#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int index_of_one(int base_number, int index_one) {
    int index = 0;
    while (index_one) {
        if (base_number&1) index_one--;
        index++;
        base_number >>= 1;
    }

    return index-1;
}

int count_ones(int number) {
    int count = 0;

    while (number > 0) {
        count += number&1;
        number >>= 1;
    }

    return count;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int n = (int)pow(2, numsSize);
    if (n <= 0) return NULL;

    *returnSize = n;
    *returnColumnSizes = calloc(n, sizeof(int));
    int** result = calloc(n, sizeof(int*));

    for (int i = 0; i < n; i ++) {
        int amount = count_ones(i);
        (*returnColumnSizes)[i] = amount;
        result[i] = calloc(amount, sizeof(int));

        for (int j = 0; j < amount; j++) {
            int index = index_of_one(i, j+1);
            result[i][j] = nums[index];
        }
    }

    return result;
}

int main() {
    int nums[] = { 1, 2, 3 };
    int numsSize = _countof(nums);
    int returnSize;
    int* returnColumnSizes;
    int** result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("{ ");
        for(int j = 0; j < returnColumnSizes[i]; j++ ){
            printf("%d ", result[i][j]);
        }
        puts("} ");
    }
    return 0;
}
