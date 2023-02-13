# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.min = 10**4
        self.finish = False

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        curr = root
        if curr == None:
            return True
        while True:
            if curr.left != None and curr.left.val < curr.val:
                self.min = curr.left.val
                self.isValidBST(curr.left)
            elif curr.left != None and (curr.left.val >= curr.val or curr.left.val >= self.min):
                return False
            if  curr.right != None and curr.right.val > curr.val:
                self.isValidBST(curr.right)
            elif  curr.right != None and curr.right.val <= curr.val:
                return False
            return