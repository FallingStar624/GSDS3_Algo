# failed, I checked solution 
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ret_list = []
        if not root:
            return ret_list # for an output
        stack = [[root]] # for checking
        while stack:
            nodes = stack.pop(0) # first item in stack pops
            if nodes:
                ret_list.append([]) # make an empty list
                stack.append([]) # make an empty list
                for node in nodes:
                    ret_list[-1].append(node.val)
                    if node.left:
                        stack[-1].append(node.left)
                    if node.right:
                        stack[-1].append(node.right)
        return ret_list