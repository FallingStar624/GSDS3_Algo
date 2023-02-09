# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
      nodes = set()
      start = head
      count = 0
      while start != None:
        nodes.add(start)
        count += 1
        if (len(nodes) != count):
            return start
        start = start.next
      return None

      ## Wrong
      # nodes = {}
      # start = head
      # while start != None:
      #   if (start.val in nodes.keys()):
      #     if (nodes[start.val] == start):
      #       return start
      #   nodes[start.val] = start
      #   start = start.next
      # return None