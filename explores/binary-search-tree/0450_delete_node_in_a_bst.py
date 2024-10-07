from typing import Optional

from TreeNode import TreeNode


class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return root

        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            else:
                curr = root.right
                while curr.left is not None:
                    curr = curr.left
                curr.val, root.val = root.val, curr.val
                root.right = self.deleteNode(root.right, key)

        return root
