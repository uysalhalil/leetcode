from typing import Optional

from ListNode import ListNode

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (head is None or head.next is None):
            return head

        nextNode = head.next
        head.next = nextNode.next
        nextNode.next = head
        head = nextNode

        head.next.next = self.swapPairs(head.next.next)
        return head