#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef unsigned long long ull;
typedef struct ListNode Node;

Node* reverseOneGroup(Node* head, int k) {
    Node* last = NULL;
    Node* left = head; Node* right = NULL;
    Node* before_right = NULL; Node* after_right = NULL;

    //verify if switching up can happen
    if(k == 1) return NULL;
    for(int i = 0; i < k; i++){
        if(right == NULL) right = left;
        else if(right->next == NULL) return NULL;
        else right = right->next;
    }
    right = NULL;
    for(int i = 0; i < k; i++){
        if(right == NULL) right = left;
        else {
            if (after_right != NULL) right = after_right;
            else right = right->next;
            if (i == k/2)  {
                before_right = right;
                after_right = right->next;
            }else if (i > k/2) {
                after_right = right->next;
                ull xored_link = (ull)right->next ^ (ull)before_right;
                right->next = (Node*)xored_link;
                before_right = right;
            }
        }
    }

    while(k > 0) {
        int tmp = right->val;
        right->val = left->val;
        left->val = tmp;

        if(last == NULL) last = right;
        ull xored_link = (ull)right->next;
        right->next = after_right;
        after_right = right;
        right = (Node*)(xored_link ^ (ull)right->next);
        left = left->next;
        k -= 2;
    }
    return last;
}

Node* reverseKGroup(Node* head, int k){
    Node* first = head;
    while(first != NULL) {
        first = reverseOneGroup(first, k);
        if(first != NULL) first = first->next;
    }
    return head;
}
