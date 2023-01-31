from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        length = 0
        cur = head
        while cur is not None:
            length += 1
            cur = cur.next
        
        cur = head
        counter = 0
        while counter < length // 2:
            counter += 1
            cur = cur.next

        return cur



if __name__ == '__main__':
    sol = Solution()
    list1 = ListNode(val=1)
    list1.next = ListNode(val=2)
    list1.next.next = ListNode(val=3)
    list1.next.next.next = ListNode(val=4)
    sl = sol.middleNode(list1)
    while sl is not None:
        print(sl.val)
        sl = sl.next