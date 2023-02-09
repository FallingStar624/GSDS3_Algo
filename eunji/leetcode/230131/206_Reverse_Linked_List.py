# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
      # ans = ListNode()
      if head == None:
        return None
      
      prev = None
      current = head
      while (current != None):
        temp = current.next
        current.next = prev
        prev = current
        current = temp
      return prev