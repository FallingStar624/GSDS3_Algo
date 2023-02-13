
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        return self.__helper(root, p, q)

    def __helper(self, root, p, q):

        if not root:
            return None

        if min(p.val, q.val) <= root.val <= max(p.val, q.val):
            return root
        elif root.val < min(p.val, q.val):
            return self.__helper(root.right, p, q)
        elif root.val > max(p.val, q.val):
            return self.__helper(root.left, p, q) 
