# Definition for a Node.
from typing import List, Optional


class Node:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

class Solution:
    def toArray(self, root: 'Optional[Node]') -> List[int]:
        n = 0
        curr_node = root
        while curr_node is not None:
            n += 1
            prev_node = curr_node
            curr_node = curr_node.next

        res = [0] * n
        while n > 0:
            res[n - 1] = prev_node.val
            prev_node = prev_node.prev
            n -= 1

        return res