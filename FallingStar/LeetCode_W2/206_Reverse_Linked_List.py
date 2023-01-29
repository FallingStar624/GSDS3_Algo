class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return
        curr = head
        org_prev = None
        flag = True
        while True:
            if not curr.next:
                flag = False
            org_next = curr.next  # 원래 next node를 저장
            curr.next = org_prev  # 원래 node의 next에 실제 prev node 할당 (swap ptr)
            org_prev = curr  # org_prev 현재 node로 업데이트
            if not flag: break
            curr = org_next  # 다음 node로 변경
        return curr
