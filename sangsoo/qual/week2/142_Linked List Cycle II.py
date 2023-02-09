#142
# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        val_list = []
        while head and head.next:
            if head not in val_list:    
                val_list.append(head)
                head = head.next
            else: # head in val_list
                return head
            