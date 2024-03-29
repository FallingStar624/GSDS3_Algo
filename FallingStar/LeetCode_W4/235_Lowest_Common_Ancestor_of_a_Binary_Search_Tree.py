class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        low = min(p.val, q.val)
        high = max(p.val, q.val)
        while True:
            if root.val < low:
                root = root.right
            elif root.val > high:
                root = root.left
            else:
                return root
