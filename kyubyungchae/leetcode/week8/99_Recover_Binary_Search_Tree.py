from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """  
        curr, prev, a, b = root, None, None, None        
        while curr:
            if not curr.left:   
				# find the node that is violating the ordering 
                if prev and curr.val < prev.val:
                    if not a: # find the first node to swap
                        a = prev
                    b = curr                   
                prev = curr
                curr = curr.right  
            else:
                temp = curr.left
                while temp.right and temp.right is not curr:
                    temp = temp.right

                if temp.right is curr:
                    temp.right = None
                    if prev and curr.val < prev.val:
                        if not a:
                            a = prev
                        b = curr
                    prev = curr
                    curr = curr.right
                else:
                    temp.right = curr
                    curr = curr.left
        
        a.val, b.val = b.val, a.val



    def __findMin(self, curNode) -> Optional[TreeNode]:
        if not curNode.left:
            return curNode
        else:
            return self.__findMin(curNode.left)

    
    def __findMax(self, curNode):
        if not curNode.right:
            return curNode
        else:
            return self.__findMax(curNode.right)

    def levelOrder(self, root):

        if not root:
            return
        
        q = []
        q.append(root)
        while q:
            size = len(q)
            curList = []

            while size > 0:
                curNode = q.pop(0)
                curList.append(curNode.val)
                size -= 1

                if curNode.left is not None:
                    q.append(curNode.left)
                if curNode.right is not None:
                    q.append(curNode.right)
            
            print(curList)

if __name__ == '__main__':

    sol = Solution()

    # root = TreeNode(val=1)
    # root.left = TreeNode(val=3)
    # root.left.right = TreeNode(val=2)

    root = TreeNode(val=3)
    root.left = TreeNode(val=1)
    root.right = TreeNode(val=4)
    root.right.left = TreeNode(val=2)


    sol.recoverTree(root)
    
    sol.levelOrder(root)
