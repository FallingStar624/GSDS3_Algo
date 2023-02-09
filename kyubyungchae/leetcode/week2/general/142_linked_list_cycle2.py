from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        visited = {}
        cur = head
        idx = 0
        while cur is not None:
            
            if cur in visited.keys():
                return cur
            else:
                visited[cur] = idx
            cur = cur.next
            idx += 1

        return None



if __name__ == '__main__':
    sol = Solution()
    list1 = ListNode(1)
    list1.next = ListNode(2)
    list1.next.next = ListNode(3)
    list1.next.next.next = ListNode(4)
    list1.next.next.next.next = list1
    sl = sol.detectCycle(list1)
    print(sl)