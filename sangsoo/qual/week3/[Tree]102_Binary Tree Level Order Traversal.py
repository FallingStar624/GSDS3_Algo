#102. Binary Tree Level Order Traversal
# solution (Recursion)
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional, List
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = []
        if not root:
            return levels

        def helper(node, level):
            # start the current level:
            if len(levels) == level:
                levels.append([])
            
            # append the current node value
            levels[level].append(node.val)

            # process child nodes for the next level
            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)
        helper(root, 0)
        return levels

