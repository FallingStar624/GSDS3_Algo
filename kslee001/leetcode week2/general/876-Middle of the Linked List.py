from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        L = ListNode
        length = 0

        cur = head
        candidates = [head]
        
        while cur.next is not None:
            cur = cur.next
            length +=1
            candidates.append(cur)
        length +=1 # [cur.next] is None, but [cur] is not None now.
        candidates.append(cur)
        mid = length//2
        return candidates[mid]
        