from typing import Optional


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        while curr and curr.next:
            try:
                if curr.visited:
                    return curr
            except AttributeError:
                curr.visited = True
                curr = curr.next
        return None
