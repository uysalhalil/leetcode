
from typing import Optional
from ListNode import ListNode


class Solution:
    def __init__(self):
        self.listLength = 0

    def makeCircular(self, head: Optional[ListNode]) -> None:
        curr = head
        for _ in range(self.listLength - 1):
            curr = curr.next

        curr.next = head

    def makeUncircular(self, head: Optional[ListNode]) -> None:
        curr = head
        for _ in range(self.listLength - 1):
            curr = curr.next

        curr.next = None

    def length(self, head: Optional[ListNode]) -> None:
        curr = head
        self.listLength = 0
        while curr is not None:
            self.listLength += 1
            curr = curr.next

    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return head

        self.length(head)
        k %= self.listLength
        self.makeCircular(head)
        move = self.listLength - k
        curr = head
        for _ in range(move):
            curr = curr.next

        head = curr
        self.makeUncircular(head)
        return head