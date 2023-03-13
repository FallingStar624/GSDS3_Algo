# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # rbt
        #print(root.right)
        #print(root)

        # min max range << or pow

        def dfs(root, min_, max_):
            # print(min_)
            # print(max_)
            # print("---")
            if not root: # 끝까지 감
                return True
            
            if (min_ and root.val <= min_.val) or (max_ and root.val >= max_.val):
                return False
            #if root.left.val <root.val and root.right.val >root.val:
                
            return dfs(root.right, root, max_) and dfs(root.left, min_, root)
            # 213 n n - 3 213 n - n 3 n (True)- n 213 3 (True) -
            # 1 n 213 - n 1 213 (True) - n n 1 (True)
        return dfs(root, None, None)
        
        
    # or stack - in order : ascending sort

# https://walkccc.me/LeetCode/problems/0098/
# ???