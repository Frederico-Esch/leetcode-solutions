from math import ceil

from sympy import im

class ListNode:
    val:int
    next_:'ListNode'
    def __repr__(self) -> str:
        cur = self
        result = ""
        while cur != None:
            result += f"{cur.val} "
            cur = cur.next_
        return result

    def __init__(self, val:int = 0, next: 'ListNode' = None) -> None:
        self.val = val
        self.next_ = next

def middleLinkedListNaive(head:'ListNode') -> 'ListNode':
    size = 0
    pointer = head
    while pointer != None:
        pointer = pointer.next_
        size+= 1
    middle = head
    for i in range(ceil(size//2)):
        middle = middle.next_
    return middle

def middleLinkedListFast(head:'ListNode') -> 'ListNode':
    slowPointer = head
    fastPointer = head
    while fastPointer != None and fastPointer.next_ != None:
        slowPointer = slowPointer.next_
        fastPointer = fastPointer.next_.next_
    return slowPointer

impar = ListNode(1, ListNode(2, ListNode(3)))
par   = ListNode(1, ListNode(2, ListNode(3, ListNode())))
print(middleLinkedListFast(impar))
print(middleLinkedListFast(par))