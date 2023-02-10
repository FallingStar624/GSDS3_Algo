from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        visited = []
        if not root:
            return visited

        level_dict = dict()
        curNode = root
        queue = [root]
        level_dict[root] = 0
        while queue:
            curNode = queue.pop(0)
            if curNode.left:
                level_dict[curNode.left] = level_dict[curNode] + 1
                queue.append(curNode.left)
            if curNode.right:
                level_dict[curNode.right] = level_dict[curNode] + 1
                queue.append(curNode.right)

        for level in set(level_dict.values()):
            level_list = []
            for key in level_dict.keys():
                if level_dict[key] == level:
                    level_list.append(key.val)
            visited.append(level_list)
        
        return visited
