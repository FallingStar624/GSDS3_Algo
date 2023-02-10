# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # p의 ancestor 담아놓기
        p_ancestors = []
        curNode = root
        while curNode.val != p.val:
            p_ancestors.append(curNode.val)
            if curNode.val < p.val:
                curNode = curNode.right
            else:
                curNode = curNode.left
        # p 자기 자신도 넣어줘야
        p_ancestors.append(curNode.val)

        lca = root
        curNode = root
        while curNode.val != q.val:
            if curNode.val in p_ancestors:
                lca = curNode
            if curNode.val < q.val:
                curNode = curNode.right
            else:
                curNode = curNode.left
        # q 자기 자신도 확인해줘야
        if curNode.val in p_ancestors:
            lca = curNode

        return lca
