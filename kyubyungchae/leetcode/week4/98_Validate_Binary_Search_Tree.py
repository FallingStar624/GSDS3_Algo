from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        return self.__helper(root, pow(-2, 31) - 1, pow(2, 31))

    def __helper(self, root, left, right):

        if not root:
            return True

        if left >= root.val or right <= root.val:
            return False
        
        return self.__helper(root.left, left, root.val) and \
            self.__helper(root.right, root.val, right)

if __name__ == '__main__':

    sol = Solution()
    
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(6)
    root.right.left = TreeNode(3)
    root.right.right = TreeNode(7)

    print(sol.isValidBST(root))
