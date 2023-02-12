# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ret = None
        self.dfs(root, min(p.val, q.val), max(p.val, q.val))
        return self.ret

    def dfs(self, node, p, q):
        if not node:
            return
        if self.ret:
            return
        if p <= node.val <= q:
            self.ret = node
            return
        if node.val > q:
            self.dfs(node.left, p, q)
        elif node.val < p:
            self.dfs(node.right, p, q)  