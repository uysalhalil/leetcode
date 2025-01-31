from typing import List
from Node import Node


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        def rec(root: 'Node', arr: List[List[int]], level: int) -> None:
            if root is None:
                return

            if level >= len(arr):
                arr.append([])
            arr[level].append(root.val)

            for child in root.children:
                rec(child, arr, level + 1)

        arr = []
        rec(root, arr, 0)

        return arr
