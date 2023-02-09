# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        n = head
        r = ListNode(val=n.val, next=None)
        while n.next:
            n = n.next
            tmp = ListNode(val=n.val, next=r)
            r = tmp
        return r