#include <iostream>
#include <vector>
#define ull unsigned long long

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    template<class... Args>
    ListNode(int x, Args... values) : val(x) {
        this->next = new ListNode(values...);
    }
};

bool isItNull(ListNode* right) {
    return right->next == nullptr;
}

ListNode* reverseOneGroup(ListNode* head, int k) {
    ListNode* last = nullptr;
    ListNode* left = head;
    ListNode* before_right = nullptr;
    ListNode* after_right = nullptr;
    ListNode* right = nullptr;

    //verify if the switching up can happen
    for (int i = 0; i < k; i++) {
        if (right == nullptr) right = left;
        else if (right->next == nullptr) return nullptr;
        else right = right->next;
        std::cout << right->next << std::endl;
    }
    right = nullptr;

    for (int i = 0; i < k; i ++) {
        if (right == nullptr) right = left;
        else {
            if (after_right != nullptr) right = after_right;
            else right = right->next;
            if (i == k/2) {
                before_right = right;
                after_right = right->next;
            }
            else if (i > (k/2)) {
                auto right_next = (ull)right->next;
                after_right = right->next;
                auto xored_link = right_next ^ (ull)before_right;
                right->next = (ListNode*)xored_link;
                before_right = right;
            }
        }
    }


    while (k > 0) {
        std::cout << "Got here" << std::endl;
        int temp = right->val;
        right->val = left->val;
        left->val = temp;

        if (last == nullptr) last = right;
        auto xored_link = (ull)right->next;
        right->next = after_right;
        after_right = right;
        right = (ListNode*)(xored_link ^ (ull)right->next);
        left = left->next;
        k-=2;
    }

    return last;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    auto first = head;
    while (first != nullptr) {
        first = reverseOneGroup(first, k);
        if(first != nullptr) first = first->next;
    }
    return head;
}

int main() {
    auto head = new ListNode(1,2,3,4,5,6,7,8,9);
    int k = 5;

    auto first = reverseKGroup(head, k);
    while (first != nullptr) {
        std::cout << first->val << " ";
        first = first->next;
    }
    std::cout << std::endl;
    return 0;
}
