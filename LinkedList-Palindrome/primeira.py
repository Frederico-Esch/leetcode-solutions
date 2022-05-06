from re import L


class ListNode:
    def __init__(self,val:int = 0, _next:'ListNode' = None):
        self.val = val
        self.next = _next
    def __repr__(self) -> None:
        cur = self
        value = ""
        while cur != None:
            value += f"{cur.val} "
            cur = cur.next
        return value


#O(n²) -> time ; O(n) -> space
def isPalindromeNaive(head:'ListNode') -> bool:
    size = 0
    pointer = head
    while pointer != None:
        size+= 1
        pointer = pointer.next

    metade = []
    cur = head
    for i in range(size//2):
        metade.insert(0,cur.val)
        cur = cur.next
    if(size%2 != 0): cur = cur.next
    for i in metade:
        if cur.val != i:
            return False
        cur = cur.next
    return True

#O(n) -> time ; O(1) -> space
def isPalindrome(head:'ListNode') -> bool:
    slowP = head
    fastP = head
    while fastP != None and fastP.next != None:
        fastP = fastP.next.next
        slowP = slowP.next

    if fastP != None : slowP = slowP.next

    #inverter head
    prev: 'ListNode' = None
    _next: 'ListNode'

    while slowP != None:
        _next = slowP.next
        slowP.next = prev
        prev = slowP
        slowP = _next
    slowP = prev

    while slowP != None:
        if slowP.val != head.val:
            return False
        slowP = slowP.next
        head = head.next
    return True
