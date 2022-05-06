#pragma once
#include"234.h"

void reverseListNode(ListNode** head) {
	ListNode* _next = nullptr;
	ListNode* _current = *head;
	ListNode* _prev = nullptr;

	while (_current!=nullptr)
	{
		_next = _current->next;
		_current->next = _prev;
		_prev = _current;
		_current = _next;
	}
	*head = _prev;
}
bool isPalindrome(ListNode* head) {
	ListNode* slowp;
	ListNode* fastp;
	slowp = head;
	fastp = head;

	while (fastp != nullptr && fastp->next != nullptr)
	{
		slowp = slowp->next;
		fastp = fastp->next->next;
	}
	if (fastp != nullptr) {
		slowp = slowp->next; //middlepoint exclusion
	}
	reverseListNode(&slowp);
	while (slowp != nullptr && head != nullptr)
	{
		if (slowp->val != head->val) return false;
		slowp = slowp->next;
		head = head->next;
	}
	return true;
}
