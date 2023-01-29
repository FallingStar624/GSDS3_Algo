# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        # compare list 1's leftmost & list 2's leftmost
        # or recursion
        # new = []
        if not list1:
            return list2
        if not list2:
            return list1
        if (not list1) and (not list2):
            return None

        root = curr = ListNode() # 0

        while (list1 and list2):
            # if (list1 and list2):
            if list1.val < list2.val:
                # new.append(list1.val)
                # list1.pop(0)
                new = list1.val
                # curr.next = list1
                list1 = list1.next
                curr.next = ListNode(new)
            else:
                # new.append(list2.val)
                #list2.pop(0)
                new = list2.val
                list2 = list2.next
                curr.next = ListNode(new)
            curr = curr.next
        curr.next = list1 or list2

        return root.next

# https://palashsharma891.medium.com/21-merge-two-sorted-lists-leetcode-python-b7bb16df45f6