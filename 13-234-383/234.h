#include<cstdio>
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr){}
	ListNode(int val) : val(val), next(nullptr){}
	ListNode(int val, ListNode* next) : val(val), next(next){}
	void print() {
		ListNode* _current = this;
		while (_current != nullptr) {
			printf("%d ", _current->val);
			if (_current->next != nullptr) printf("-> ");
			_current = _current->next;
		}
		printf("\n");
	}
};

void reverseListNode(ListNode** head);

bool isPalindrome(ListNode* head);
