#include<stdio.h>
#include<stdlib.h>

int removeElement(int* nums, int numSize, int val){
    int count = numSize;
    for(int i = 0, pos = 0; pos < numSize; i++, pos++){
        while(nums[pos] == val && pos < numSize){
            pos++;
            count--;
        }
        if(pos >= numSize) break;
        nums[i] = nums[pos];
    }
    return count;
}

int main(){
    int valores[] = {0,1,2,2,3,0,4,2};
    int k = removeElement(valores, 8, 2);
    for(int i = 0; i < k; i++) printf("%d, ", valores[i]);
    printf("\n");
    return 0;
}
