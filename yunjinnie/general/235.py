# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # depth 타고 올라가면서
        # dictionary에 ancestor 값들 저장하다가 최초로 만나는 지점
        
        # or recursive
        
        if not root:
            return 

        if root.val == p.val or root.val == q.val:
            return root

        if root.val > p.val and root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        
        return root ###


# https://walkccc.me/LeetCode/problems/0235/?h=235