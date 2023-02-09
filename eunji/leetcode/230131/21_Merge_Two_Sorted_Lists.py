# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1, list2):
      start = ListNode()
      ans = start  ## [124] [134]
      if (list1 == None) & (list2 == None):
        return None

      while True:
        if (list2 == None):
          ans.val = list1.val
          if list1.next == None:
            return start
          list1 = list1.next
        elif (list1 == None):
          ans.val = list2.val
          if list2.next == None:
            return start
          list2 = list2.next
        elif (list1.val <= list2.val):
          ans.val = list1.val
          list1 = list1.next
        elif (list1.val > list2.val):
          ans.val = list2.val
          list2 = list2.next
        ans.next = ListNode()
        ans = ans.next
