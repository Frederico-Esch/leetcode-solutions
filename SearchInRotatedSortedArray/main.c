#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* nums, int target, int begin, int end) {
    int middle = (end-begin)/2 + begin;

    if (begin == end) return nums[begin] == target ? begin : -1;

    while ( begin < end-1 && nums[middle] != target) {
        printf("begin %d, end %d\n", begin, end);
        if (nums[middle] < target) {
            begin = middle;
        }
        else {
            end = middle;
        }
        middle = (end-begin)/2 + begin;
    }

    return nums[middle] == target ? middle : -1;
}

int search(int* nums, int numsSize, int target) {
    if(numsSize == 0) return -1;
    if(numsSize == 1) return (nums[0] == target) -1;

    int begin = 0;
    int middle = numsSize/2;
    int end = numsSize;

    if (nums[0] < nums[numsSize-1]) {
        if ( target < nums[0] || target > nums[numsSize-1]) return -1;

        int index = binarySearch(nums, target, begin, end);
        return index;
    }

    while (nums[middle] < nums[middle+1]) {
        if (nums[middle] > nums[0]) {
            begin = middle;
        }
        else {
            end = middle;
        }
        middle = (end-begin)/2 + begin;
    }

    int big_index = middle;
    int small_index = middle+1;

    if ( nums[big_index] < target || nums[small_index] > target) {
        puts("SKIPED");
        return -1;
    }

    int index =
        (nums[0] > target)
        ? binarySearch( nums, target, small_index, numsSize)
        : binarySearch( nums, target, 0, small_index);

    return index;
}

int main() {
    int nums[] = { 3, 1 };
    printf("%d\n", search(nums, _countof(nums), 0));
    printf("%d\n", search(nums, _countof(nums), 3));
}
