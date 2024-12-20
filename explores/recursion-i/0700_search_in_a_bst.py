from typing import Optional

from TreeNode import TreeNode


class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None or root.val == val:
            return root

        if root.val > val:
            return self.searchBST(root.left, val)
        else:
            return self.searchBST(root.right, val)