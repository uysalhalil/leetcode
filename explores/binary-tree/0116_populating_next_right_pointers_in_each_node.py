from typing import Optional

class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def traverse(self, root: 'Optional[Node]', next: 'Optional[Node]'):
        if root is None or next is None:
            return

        root.next = next

        self.traverse(root.left, root.right)
        self.traverse(next.left, next.right)
        self.traverse(root.right, next.left)


    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root is None:
            return root

        self.traverse(root.left, root.right)
        return root