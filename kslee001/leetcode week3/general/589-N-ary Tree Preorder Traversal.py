from typing import List
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        L = []
        stack = []
        stack.append(root)
        while(stack):
            cur = stack.pop() # 1
            if cur is not None:
                L.append(cur.val) # preorder
                for c in reversed(cur.children): # 4 - 2 - 3 
                    stack.append(c)               # last :  3

        return L