# 98. Validate Binary Search Tree
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
'''
[Algorithm]
(문제요구사항) BST가 맞냐 틀리냐
1. 좌우측을 보면서 가운데 값과 비교하여 작은지 큰지를 확인한다.
2. BSTHelp함수를 만들 때, 한 번에 크고 작음을 비교하기 위해서 parameter를 low, high 둘다 추가한다. 
  - (한번은 왼쪽이 가운데보다 작은지, 오른쪽이 가운데 보다 큰지를 두번에 고려하지 않고 한번에 하기 위해..)
  - (비교할때 low, high 대신 node.left.val 또는 node.right.val을 쓰게되면
    node.left, node.right가 없으면 error가 나서 한번더 if문을 써줘야하는 번거러움이 있다. 
    그래서 low, high로 써줘야 코드가 간결해진다.)
3. BSTHelp함수의 return을 왼쪽노드 and 오른쪽노드 로 한다. (그래야 한번에 비교 가능)
4. node가 없으면 그냥 return 한다. (자녀노드가 없을 경우, basecase)
'''
import math
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def isValidBSTHelp(node, low = -math.inf, high = math.inf): # or low = -2**31, high = 2**31
            # Empty trees are valid BSTs.
            if not node:
                return True          
            # The current node's value must be between left and right
            if node.val <= low or node.val >= high:
                return False
            # The left and rifhgt subtree must also be valid.
            return isValidBSTHelp(node.left, low, node.val) and isValidBSTHelp(node.right, node.val, high)
        
        return isValidBSTHelp(root)

