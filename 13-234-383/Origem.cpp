#include"13.h"
#include"234.h"
#include"383.h"
#include<cstdio>
#define TESTE 3
int main() {
#if TESTE == 1
	printf("%d\n", romanToInt("III"));
	printf("%d\n", romanToInt("LVIII"));
	printf("%d\n", romanToInt("MCMXCVIII"));
#elif  TESTE == 2
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
	printf("%d\n", isPalindrome(head));
#elif TESTE == 3
	printf("%d\n", canConstruct("a", "b"));
	printf("%d\n", canConstruct("aa", "ab"));
	printf("%d\n", canConstruct("aa", "aab"));
#endif
	return 0;
}