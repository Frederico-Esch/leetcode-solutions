#include<bits/stdc++.h>
typedef std::string string;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next=nullptr):val(val), next(next){
    }
    ListNode(std::vector<int> vals) {
        val = vals[0];
        auto end = this;
        for(int i = 1; i < vals.size(); i++){
            end->next = new ListNode{vals[i], nullptr};
            end = end->next;
        }
    }

    void print() {
        auto end = this;
        while(end != nullptr){
            std::cout << end->val << " ";
            end = end->next;
        }
        std::cout << std::endl;
    }
};


class Solution {
public:
    static ListNode* mergeKLists(std::vector<ListNode*>&lists ){
        if(lists.size() == 0) return nullptr;
        while(lists.size() > 1){
            for(int i = 0, j = 1; j < lists.size(); i+=2, j+=2){
                auto left = lists[i];
                auto right = lists[j];
                auto merge = mergeLists(left, right);
                lists[i/2] = merge;
            }
            if(lists.size()%2 == 1){
                lists[std::ceil(lists.size()/2)] = lists[lists.size()-1];
            }
            lists.erase(lists.end()-std::floor(lists.size()/2), lists.end());
        }
        return lists[0];
    }

    static ListNode* mergeLists(ListNode* list1, ListNode* list2){
        ListNode* result = nullptr;
        ListNode* end = nullptr;

        while(list1 != nullptr && list2 != nullptr){
            ListNode* val;
            if (list1->val < list2->val){
                val = list1;
                list1 = list1->next;
                val->next = nullptr;
            }else{
                val = list2;
                list2 = list2->next;
                val->next = nullptr;
            }

            if(result == nullptr){
                result = val;
                end = result;
            }else{
                end->next = val;
                end = end->next;
            }
        }
        while(list1 != nullptr){
            ListNode* val = list1;
            list1 = list1->next;
            val->next = nullptr;
            if(result == nullptr){
                result = val;
                end = result;
            }else{
                end->next = val;
                end = end->next;
            }
        }
        while(list2 != nullptr){
            ListNode* val = list2;
            list2 = list2->next;
            val->next = nullptr;
            if(result == nullptr){
                result = val;
                end = result;
            }else{
                end->next = val;
                end = end->next;
            }
        }
        return result;
    }
};

auto main() -> int {
    //[[-9,-7,-7]
    //[-6,-4,-1,1]
    //{-6,-5,-2,0,0,1,2}
    //{ -9,-8,-6,-5,-4,1,2,4 }
    //[-10]
    //{ -5,2,3 }
    std::vector<ListNode*> lists = {
        new ListNode({-9,-7,-7}),
        new ListNode({-6,-4,-1,1}),
        new ListNode({-6,-5,-2,0,0,1,2}),
        new ListNode({ -9,-8,-6,-5,-4,1,2,4 }),
        new ListNode(-10),
        new ListNode({ -5,2,3 }),
    };
    auto sol = Solution::mergeKLists(lists);
    sol->print();
    return 0;
}

















