#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = calloc(2, sizeof(int));
    result[0] = -1; result[1] = -1;

    if (numsSize == 0) return result;
    if (numsSize == 1) {
        if (nums[0] == target) {
            result[0] = 0;
            result[1] = 0;
        }
        return result;
    }
    if (numsSize == 2) {
        if (nums[0] == target) result[0] = 0;
        if (nums[1] == target) result[1] = 1;

        if (result[0] == -1) result[0] = result[1];
        if (result[1] == -1) result[1] = result[0];
        return result;
    }

    int begin = 0;
    int end = numsSize;
    int middle = (end - begin)/2 + begin;

    puts("FIND END");
    //find the end
    while (1) {
        if (middle == numsSize-1) { if(nums[middle] == target) result[1] = numsSize-1; break; }
        if (nums[middle] == target && nums[middle+1] != target) { result[1] = middle; break; }
        if (nums[middle] < target && nums[middle+1] > target) break;

        if (nums[middle] <= target)
        {
            begin = middle;
        }
        else
        {
            end = middle;
        }
        int temp_middle = (end-begin)/2 + begin;
        if (middle == temp_middle) break;
        middle = temp_middle;
    }

    begin = 0;
    end = numsSize;
    middle = (end-begin)/2 + begin;

    puts("FIND BEGIN");
    //find the beginning
    while (1)
    {
        if (middle == 0) { if(nums[middle] == target) result[0] = 0; break; }
        if (nums[middle] == target && nums[middle-1] != target) { result[0] = middle; break; }
        if (nums[middle-1] < target && nums[middle] > target) break;

        if (nums[middle] >= target)
        {
            end = middle;
        }
        else
        {
            begin = middle;
        }
        int temp_middle = (end-begin)/2 + begin;
        if (middle == temp_middle) break;
        middle = temp_middle;
    }

    if ((result[0] == -1 && result[1] != -1) || (result[0] != -1 && result[1] == -1))
    {
        puts("ERRO, ENCONTROU APENAS UM LADO");
        return result;
    }

    return result;
}

int main()
{
    int lista[] = {1,2,3};
    int search = 4;
    int resultSize = 0;
    int* result = searchRange(lista, _countof(lista), search, &resultSize);
    printf("(%d, %d)", result[0], result[1]);

    return 0;
}
