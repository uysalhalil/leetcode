import sys
from typing import Optional

from TreeNode import TreeNode


class Solution:
    def validate(self, root: Optional[TreeNode], minVal: int, maxVal: int) -> bool:
        if root is None:
            return True

        if minVal >= root.val or maxVal <= root.val:
            return False

        return self.validate(root.left, minVal, root.val) and \
            self.validate(root.right, root.val, maxVal)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.validate(root, -sys.maxsize - 1, sys.maxsize)
