# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        min_v = -1 * (2 << 30)
        max_v = (2 << 30) - 1
        return self.is_valid(root, min_v - 1, max_v + 1)
    
    def is_valid(self, node, min_v, max_v):
        if not node:
            return True

        if node.left:
            left_max_v = min(max_v, node.val)
            if min_v < node.left.val < left_max_v:
                left_val = self.is_valid(node.left, min_v, left_max_v)
            else:
                left_val = False
        else:
            left_val = True

        if node.right:
            right_min_v = max(min_v, node.val)
            if right_min_v < node.right.val < max_v:
                right_val = self.is_valid(node.right, right_min_v, max_v)
            else:
                right_val = False
        else:
            right_val = True

        return left_val and right_val