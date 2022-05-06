#include<iostream>
#include<list>
#include<algorithm>

class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode():val(0),next(nullptr){}
        ListNode(int val):val(val), next(nullptr){}
        ListNode(int val, ListNode* next):val(val), next(next){}
};

void printList(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}

void printList(std::list<int> valores){
    for(int var : valores){
        std::cout << var << " ";
    }
    std::cout << "\n";
}

bool isPalindromeNaive(ListNode* head){
    ListNode* pointer = head;
    int size = 0;
    std::list<int> metade;
    while(pointer != nullptr){
        pointer= pointer->next;
        size++;
    }
    pointer = head;
    for(int i = 0; i < size/2; i++){
        metade.insert(metade.begin(), pointer->val);
        pointer = pointer->next;
    }
    if(size%2 != 0) pointer = pointer->next;
    for(int valor : metade){
        if(valor != pointer->val) return false;
        pointer = pointer->next;
    }
    return true;
}

bool isPalindrome(ListNode* head){
    ListNode* slowP = head;
    ListNode* fastP = head;
    while(fastP != nullptr && fastP->next != nullptr){
        slowP = slowP->next;
        fastP = fastP->next->next;
    }

    if(fastP!=nullptr) slowP = slowP->next;

    ListNode* prev = nullptr;
    ListNode* next;
    while(slowP != nullptr){
        next = slowP->next;
        slowP->next = prev;
        prev = slowP;
        slowP = next;
    }
    slowP = prev;
    while(slowP != nullptr){
        if(slowP->val != head->val) return false;
        slowP = slowP->next;
        head = head->next;
    }

    return true;
}

int main(){
    std::cout << isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))))) << "\n";
    std::cout << isPalindrome(new ListNode(1, new ListNode(3, new ListNode(2, new ListNode(1))))) << "\n";
    std::cout << isPalindrome(new ListNode(1, new ListNode(2, new ListNode(1)))) << "\n";
    return 0;
}
