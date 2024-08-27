from typing import Optional


class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        nodeMap = {}

        dmyHead = Node(-1)
        prev = dmyHead
        curr = head
        while curr is not None:
            curr2 = Node(curr.val)
            prev.next = curr2
            nodeMap[curr] = curr2
            curr = curr.next
            prev = curr2

        curr = head
        curr2 = dmyHead.next
        while curr is not None:
            if curr.random is not None:
                curr2.random = nodeMap[curr.random]
            curr = curr.next
            curr2 = curr2.next

        return dmyHead.next
