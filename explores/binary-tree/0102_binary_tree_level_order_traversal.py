from typing import List, Optional

from TreeNode import TreeNode


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if (root is None):
            return res

        level = []
        level.append(root)

        while len(level) > 0:
            nextLevel = []
            levelVals = []
            for node in level:
                levelVals.append(node.val)
                if (node.left is not None):
                    nextLevel.append(node.left)
                if (node.right is not None):
                    nextLevel.append(node.right)
            level = nextLevel
            res.append(levelVals)

        return res