#876_failed
# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        lst = []
        ln = 0
        while head:
            lst.append(head.val)
            head = head.next
        ln = len(lst)
        return lst[ln//2]