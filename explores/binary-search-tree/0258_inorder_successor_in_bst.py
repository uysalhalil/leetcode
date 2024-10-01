from typing import Optional
from TreeNode import TreeNode


class Solution:
    def __init__(self):
        self.isFound = False
        self.successor = None

    def traverse(self, root: TreeNode, p: TreeNode) -> None:
        if root is None:
            return

        self.traverse(root.left, p)

        if self.isFound is True and self.successor is None:
            self.successor = root

        if root == p:
            self.isFound = True

        self.traverse(root.right, p)

    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        self.traverse(root, p)
        return self.successor