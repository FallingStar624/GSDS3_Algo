#235. Lowest Common Ancestor of a Binary Search Tree
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
# failed, solution
'''
[Algorithm]
(문제요구사항) 가장 아래 레벨의 공통의 부모노드를 찾아라
1. BST는 가운데기준으로 크고 작고가 결정되니까.
   p_val, q_val, parent_val를 비교하면 될것이다.
2. p_val, q_val이 둘다 parent_val보다 크면 오른쪽에 둘다 작으면 왼쪽에 있을 것이고, 
3. 만약 둘이 찢어진다면 그 parent_val이 우리가 찾는 부모노드이다. 
'''

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Value of current node or parent node
        parent_val = root.val
        # Value of p
        p_val = p.val
        # Vaule of q
        q_val = q.val

        # If both p and q are greater than parent
        if p_val > parent_val and q_val > parent_val:
            return self.lowestCommonAncestor(root.right, p, q)
        # If both p and q are lesser than parent
        elif p_val < parent_val and q_val < parent_val:
            return self.lowestCommonAncestor(root.left, p, q)
        # We have found the split poinit, i.e., the LCA node.
        else:
            return root