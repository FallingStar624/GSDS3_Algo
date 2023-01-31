# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1
        
        n1 = list1
        n2 = list2
        if n1.val < n2.val:
            head = ListNode(val=n1.val, next=None)
            n1 = n1.next
        else:
            head = ListNode(val=n2.val, next=None)
            n2 = n2.next
        n = head
        while n1 or n2:
            if not n1 or (n2 and n2.val < n1.val):
                n.next = n2
                n2 = n2.next
                n = n.next
            else:
                n.next = n1
                n1 = n1.next
                n = n.next
        return head