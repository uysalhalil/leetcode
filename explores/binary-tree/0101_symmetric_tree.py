from typing import Optional

from TreeNode import TreeNode


class Solution:
    def subTreeTraversal(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        if (left is None and right is None):
            return True
        if (left is None or right is None):
            return False

        if (left.val != right.val):
            return False

        return self.subTreeTraversal(left.left, right.right) and self.subTreeTraversal(left.right, right.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if (root is None):
            return True
        return self.subTreeTraversal(root.left, root.right)