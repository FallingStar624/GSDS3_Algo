from typing import List, Optional

# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        head = ListNode(-1)
        cur = head

        while list1 != None and list2 != None:

            if list1.val <= list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next

            cur = cur.next
        
        if list1 != None:
            cur.next = list1
        else:
            cur.next = list2

        return head.next                    


if __name__ == '__main__':

    sol = Solution()
    list1 = ListNode(val=1)
    list1.next = ListNode(val=2)
    list1.next.next = ListNode(val=4)

    list2 = ListNode(val=1)
    list2.next = ListNode(val=3)
    list2.next.next = ListNode(val=4)

    sl = sol.mergeTwoLists(list1, list2)
    # sl = list1
    while sl is not None:
        print(sl.val)
        sl = sl.next