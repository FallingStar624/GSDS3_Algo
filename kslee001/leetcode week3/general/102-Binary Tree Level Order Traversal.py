from typing import Optilnal, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        if root is None:
            return None
        
        L = [ ]
        
        level_idx = 0
        queue = []
        queue.append( [root, level_idx] ) # node, level_idx
        while(queue):
            # cur
            cur, level_idx = queue.pop(0) # node, level_idx

            # generate list of list
            if len(L)-1 < level_idx:
                L.append([])
            
            # append values in level_idx-th list of list
            L[level_idx].append(cur.val)
            
            if cur.left is not None:
                queue.append( [cur.left, level_idx+1] )
            if cur.right is not None:
                queue.append( [cur.right, level_idx+1] )
        
        return L
