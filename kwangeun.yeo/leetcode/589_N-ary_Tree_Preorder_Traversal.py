"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        self.out = []
        self.dfs(root)
        return self.out
    
    def dfs(self, node):
        if not node:
            return
        self.out.append(node.val)
        for child in node.children:
            self.dfs(child)