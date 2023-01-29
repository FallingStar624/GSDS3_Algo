# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # or 2 pointer
        curr = head
        length = 0
        while head!=None:
            length+=1
            head = head.next

        # print(length)
        for i in range(length//2):
            curr = curr.next
        return curr

# https://medium.com/@hylei_73413/middle-of-linked-list-8fb3931c6106