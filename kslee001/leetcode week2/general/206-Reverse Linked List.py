from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        L = ListNode
        cur = head

        if cur is None:
            return L('')
        # init
        res = L(cur.val)
        cur = cur.next
        
        while cur is not None:
            dummy = L(cur.val)
            dummy.next = res
            res = dummy
            cur = cur.next
        
        if cur is not None:
            dummy = L(cur.val)
            dummy.next = res
            res = dummy
        
        return res