class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        walk, jump = head, head
        while jump and jump.next:
            walk = walk.next
            jump = jump.next.next
        return walk
