# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root:
            return []

        lst = []
        #for i, p in enumerate(root):
            # idx = 0
            # while p!=Null:
            #     dic[idx]=p
            # idx += 1   

        def dfs(root):
            lst.append(root.val)
            for i in root.children:
                dfs(i)

        dfs(root)

        return lst