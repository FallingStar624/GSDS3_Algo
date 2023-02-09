from typing import Optional

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        
        while cur and cur.next:
            if cur.val < -10**5:
                return cur # 반복
            else:
                cur.val -= 10**6
                cur = cur.next

        return None