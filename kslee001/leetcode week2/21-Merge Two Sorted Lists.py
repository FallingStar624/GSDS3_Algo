from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # init
        if (list1 is None) and (list2 is None):
            return ListNode('')
        elif list1 is None:
            head = ListNode(list2.val)
            list2 = list2.next
        elif list2 is None:
            head = ListNode(list1.val)
            list1 = list1.next
        elif list1.val < list2.val:
            head = ListNode(list1.val)
            list1 = list1.next
        else:
            head = ListNode(list2.val)
            list2 = list2.next
        cur = head

        # insert
        while (list1 is not None) & (list2 is not None):
            if list1.val < list2.val:
                cur.next = ListNode(list1.val)
                cur = cur.next
                if list1.next is not None :
                    list1 = list1.next
                else:
                    list1 = None
                    break
            else:
                cur.next = ListNode(list2.val)
                cur = cur.next
                if list2.next is not None :
                    list2 = list2.next
                else:
                    list2 = None
                    break

        while (list1 is not None):
            cur.next = ListNode(list1.val)
            cur = cur.next
            if list1.next:
                list1 = list1.next
            else:
                break

        while (list2 is not None):
            cur.next = ListNode(list2.val)
            cur = cur.next
            if list2.next:
                list2 = list2.next
            else:
                break

        return head