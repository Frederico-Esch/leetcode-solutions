#include <iostream>
#include <math.h>
#include <stdio.h>
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() {
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
    ListNode(int val, ListNode* next) {
        this->next = next;
        this->val = val;
    }
};

void printListNode(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << "\n";
}

// Naive
ListNode* middleNodeNaive(ListNode* head) {
    ListNode* pointer = head;
    int size = 0;
    while (pointer != nullptr && pointer->next != nullptr) {
        pointer = pointer->next;
        size++;
    }
    pointer = head;
    for (int i = 0; i < ceil((double)size / 2); i++)
        pointer = pointer->next;

    return pointer;
}

// Optimal
ListNode* middleNode(ListNode* head) {
    ListNode* slowPointer = head;
    ListNode* fastPointer = head;
    while(fastPointer != nullptr && fastPointer->next != nullptr){
        fastPointer = fastPointer->next->next;
        slowPointer = slowPointer->next;
    }
    return slowPointer;
}

int main() {
    printListNode(middleNode(
        new ListNode(1, new ListNode(2, new ListNode(3)))));

    return 0;
}
