# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head):
        visited = dict()
        while head:
            if head not in visited:
                visited[head] = 1
            else:
                visited[head] += 1
            if visited[head] > 1:
                return head
            head = head.next
        return None
