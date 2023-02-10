from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        ## inorder DFS
        self.visited = []
        self.visit_set = set()
        self.inorderHelp(root)
        if (len(self.visit_set) == len(self.visited)) and (self.visited == sorted(self.visited)):
            return True
        return False

    def inorderHelp(self, curNode):
        if not curNode:
            return
        self.inorderHelp(curNode.left)
        self.visited.append(curNode.val)
        self.visit_set.add(curNode.val)
        self.inorderHelp(curNode.right)
