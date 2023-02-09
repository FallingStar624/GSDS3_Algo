from typing import Optional


class Solution:
    def __init__(self):
        self.ans = []

    def levelOrderHelp(self, node: Optional[TreeNode], level: int) -> None:
        if node == None:
            return
        if len(self.ans) >= level:
            self.ans[level-1].append(node.val)
            if node.left:
                self.levelOrderHelp(node.left, level+1)
            if node.right:
                self.levelOrderHelp(node.right, level+1)
        else:
            self.ans.append([])
            self.ans[level-1].append(node.val)
            if node.left:
                self.levelOrderHelp(node.left, level + 1)
            if node.right:
                self.levelOrderHelp(node.right, level + 1)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.levelOrderHelp(root, 1)
        return self.ans

