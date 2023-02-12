#589. N-ary Tree Preorder Traversal
# Definition for a Node.
# failed,  solution
from typing import List 

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def preorder(self, root: 'Node', ans: list = None) -> List[int]:
        if not root: 
            return ans
        if ans == None:
            ans = []
        ans.append(root.val)
        for child in root.children:
            self.preorder(child, ans)
        return ans