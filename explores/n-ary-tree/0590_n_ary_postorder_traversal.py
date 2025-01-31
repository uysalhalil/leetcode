from typing import List

from Node import Node


class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        def rec(root: "Node", arr: List[int]) -> None:
            if root is None:
                return

            for child in root.children:
                rec(child, arr)

            arr.append(root.val)

        arr = []
        rec(root, arr)
        return arr