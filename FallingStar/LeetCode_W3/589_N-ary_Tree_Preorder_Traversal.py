from typing import List


class Solution:
    def __init__(self):
        self.ans = []

    def __preorderHelp(self, curr):
        if not curr:
            return
        self.ans.append(curr.val)
        for child in curr.children:
            self.__preorderHelp(child)

    def preorder(self, root: 'Node') -> List[int]:
        self.__preorderHelp(root)
        return self.ans
