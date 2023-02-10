# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.dict = {}
    
    def levelOrderHelp(self, root, level):
        if root == None:
            return None
        
        if level in self.dict:
            self.dict[level].append(root.val)
        else:
            self.dict[level] = [root.val]

        level += 1
        self.levelOrderHelp(root.left, level)
        self.levelOrderHelp(root.right, level)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.levelOrderHelp(root, 0)
        ans = [v for k, v in self.dict.items()]

        return ans

