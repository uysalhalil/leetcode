from typing import List
from Node import Node

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        def rec(root: "Node", arr: List[int]) -> None:
            if root is None:
                return
            arr.append(root.val)
            for child in root.children:
                rec(child, arr)

        arr = []
        rec(root, arr)
        return arr
