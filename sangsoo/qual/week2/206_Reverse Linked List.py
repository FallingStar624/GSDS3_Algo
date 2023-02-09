#206. Reverse Linked List
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        next = ListNode()
        while head:
            #go forward
            next = head.next
            #change direction
            head.next = prev
            #go forward
            prev = head
            # go forward
            head = next

        return prev
