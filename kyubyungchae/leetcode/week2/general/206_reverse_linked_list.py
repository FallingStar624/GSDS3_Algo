from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        cur = head
        prev = None
        next = None

        while cur is not None:
            
            next = cur.next
            cur.next = prev
            prev = cur 
            cur = next 
         
        return prev

if __name__ == '__main__':

    sol = Solution()
    list1 = ListNode(val=1)
    list1.next = ListNode(val=2)
    list1.next.next = ListNode(val=4)

    sl = sol.reverseList(list1)
    while sl is not None:
        print(sl.val)
        sl = sl.next