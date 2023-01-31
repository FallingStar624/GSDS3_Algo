#876_failed
# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        middle_number, num, tmpnode = 0, 0, head
        while head:
            num += 1
            head = head.next
        middle_number = num//2
        tmp = 0
        while tmp != middle_number:
            tmp += 1
            tmpnode = tmpnode.next
        return tmpnode