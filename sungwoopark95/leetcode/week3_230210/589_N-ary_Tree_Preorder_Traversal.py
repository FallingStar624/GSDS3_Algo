from typing import List

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        self.visited = []
        self.preorderHelp(root)
        return self.visited

    def preorderHelp(self, curNode):
        if curNode is None:
            return
        self.visited.append(curNode.val)
        for child in curNode.children:
            self.preorderHelp(child)
