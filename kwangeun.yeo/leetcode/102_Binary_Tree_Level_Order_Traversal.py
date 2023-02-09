# bfs인데 level 단위로 싹 다 queue에 넣고 빼고
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        ret = []
        q = [root]
        while q:
            level = [n.val for n in q]
            ret.append(level)
            next_q = []
            for n in q:
                if n.left:
                    next_q.append(n.left)
                if n.right:
                    next_q.append(n.right)
            q = next_q
        
        return ret
