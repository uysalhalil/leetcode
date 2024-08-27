# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummyHead = ListNode(0, head)
        p1 = dummyHead
        while n > 0:
            p1 = p1.next
            n -= 1

        p2 = dummyHead
        while p1.next is not None:
            p1 = p1.next
            p2 = p2.next

        nodeToDelete = p2.next
        p2.next = nodeToDelete.next if nodeToDelete is not None else None

        return dummyHead.next