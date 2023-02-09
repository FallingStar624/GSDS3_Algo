from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pointer = head
        length = 0

        while pointer:
            length += 1
            pointer = pointer.next

        stop = (length//2)
        i = 0
        while i < stop:
            head = head.next
            i += 1

        return head
