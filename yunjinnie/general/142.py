# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# ???

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        lst = []
        #curr = head

        if head == None or head.next == None:
            return None

        while (head !=None):
            if head not in lst:
                lst.append(head)
            else:
                return head #ListNode(lst.index(head.val))
            head = head.next

        return None

# or Floyd cycle detection
# https://ifuwanna.tistory.com/345
# https://velog.io/@haebin/Leetcode-142.-Linked-List-Cycle-II