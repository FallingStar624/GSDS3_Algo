from collections import deque
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        lst = [[]]
        if not root:
            return []
        # queue
        # q = deque().append(root)
        # while q:
        #### bfs -> depth
        def bfs(root, depth):
            if not root: 
                return 
            #for i in root:
            if len(lst)>depth: # ｎｏｔ ｆｉｒｓｔ ｅｌｅｍｅｎｔ
                lst[depth].append(root.val)
            # if root.left==None or root.right==None:
            #     continue
            else: # first
                lst.append([root.val])
            bfs(root.left, depth+1)
            bfs(root.right, depth+1)
            
        bfs(root, 0)

        return lst