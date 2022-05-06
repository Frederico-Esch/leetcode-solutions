#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next; 
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* back  = head;
    if(back == NULL) return back;
    struct ListNode* ahead = head->next;
    int temp;
    while(ahead != NULL){
        temp = back->val;
        back->val = ahead->val;
        ahead->val = temp;

        back = back->next->next;
        ahead = ahead->next;
        if(ahead != NULL) ahead = ahead->next;
    }
    return head;
}

int main(){
    struct ListNode* head = malloc(sizeof(struct ListNode*)); head->val = 1;
    head->next = malloc(sizeof(struct ListNode*)); head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode*)); head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(struct ListNode*)); head->next->next->next->val = 4;
    swapPairs(head);
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
