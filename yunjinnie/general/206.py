# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head) -> ListNode:
        curr = head
        prev = None
        # 1 -> 2 -> 3 -> 4 -> 5
        # 5 <- 4 <- 3 <- 2 <- 1

        while(curr):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
            #prev = head.val

        return prev


# https://hezma.tistory.com/96
# https://airsbigdata.tistory.com/96