from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 and not list2:
            return
        curr = ListNode()
        ans_head = curr
        while list1 and list2:
            if list1.val < list2.val:
                curr.val = list1.val
                list1 = list1.next
            else:
                curr.val = list2.val
                list2 = list2.next
            next_node = ListNode()
            curr.next = next_node
            curr = curr.next
        if list1:
            curr.val = list1.val
            curr.next = list1.next
        else:
            curr.val = list2.val
            curr.next = list2.next
        return ans_head
