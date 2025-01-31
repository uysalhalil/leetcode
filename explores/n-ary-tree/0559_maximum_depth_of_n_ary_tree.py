from Node import Node


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0

        max_depth = 1
        for child in root.children:
            max_depth = max(max_depth, 1 + self.maxDepth(child))

        return max_depth
