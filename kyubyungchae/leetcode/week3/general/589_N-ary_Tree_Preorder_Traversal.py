from typing import List

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        
        if not root:
            return []
        
        ans = [root.val]
        for ch in root.children:
            ans.extend(self.preorder(ch))

        return ans
        
