# Definition for singly-linked list.
# 21_Merge Two sorted list
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        i, j, k, list3_len = 0, 0, 0, 0
        list3_len = len(list1)+len(list2)
        list3 = [0] * list3_len
        while i < len(list1) and j < len(list2):
            if list1[i] < list2[j]:
                list3[k] = list1[i]
                i += 1
            else:
                list3[k] = list2[j]
                j += 1
            k += 1
        if i < len(list1):
            list3[k:] = list1[i:]
        if j < len(list2):
            list3[k:] = list2[j:]
        return list3
                    
            