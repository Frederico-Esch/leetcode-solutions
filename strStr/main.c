#include<stdio.h>
int strStr(char * haystack, char * needle){
    char * pointer = needle;
    int pos = 0, pos_start = 0;
    while(*haystack != 0){
        pos++;
        if(*pointer == *haystack){
            pointer++;
            if(*pointer == 0) break;
        }else{
            if(pointer != needle){
                haystack -= (pos - pos_start);
                pos = pos_start + 1;
                haystack++;
            }
            pointer = needle;
            pos_start = pos;
        }
        haystack++; 
    }
    if (*pointer == 0) return pos_start;
    return -1;
}

int main(){
    printf("%d\n", strStr("mississippi", "issip"));
    return 0;
}
