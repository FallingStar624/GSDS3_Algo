# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
      length = 0 
      start = head
      while (start != None):
        length += 1
        start = start.next
      middle = length // 2 

      ans = head
      while (middle != 0):
        middle -= 1
        ans = ans.next

      return ans

