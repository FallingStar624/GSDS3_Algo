

class Solution:
    def __init__(self):
        self.ans = True

    def sub_tree(self, node):
        left = node.left
        right = node.right
        min_val = node.val
        max_val = node.val
        while left:
            min_val = left.val
            left = left.left
        while right:
            max_val = right.val
            right = right.right
        return min_val, max_val

    def valid_check(self, node):
        if node.left:
            _, left_max = self.sub_tree(node.left)
            if left_max >= node.val:
                self.ans = False
                return
            self.valid_check(node.left)
        if node.right:
            right_min, _ = self.sub_tree(node.right)
            if right_min <= node.val:
                self.ans = False
                return
            self.valid_check(node.right)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.valid_check(root)
        return self.ans

