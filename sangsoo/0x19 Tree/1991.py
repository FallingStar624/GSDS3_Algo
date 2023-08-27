class Tree:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

    @staticmethod
    def preorder(node):
        if node is None:
            return
        print(node.data, end='')
        Tree.preorder(node.left)
        Tree.preorder(node.right)

    @staticmethod
    def inorder(node):
        if node is None:
            return
        Tree.inorder(node.left)
        print(node.data, end='')
        Tree.inorder(node.right)

    @staticmethod
    def postorder(node):
        if node is None:
            return
        Tree.postorder(node.left)
        Tree.postorder(node.right)
        print(node.data, end='')

n = int(input())
tree = [Tree(chr(i + ord('A'))) for i in range(n)]
for _ in range(n):
    data, left, right = input().strip().split()
    node = tree[ord(data) - ord('A')]
    if left != '.':
        node.left = tree[ord(left) - ord('A')]
    if right != '.':
        node.right = tree[ord(right) - ord('A')]

root = tree[0]
Tree.preorder(root)
print()
Tree.inorder(root)
print()
Tree.postorder(root)
