from typing import Optional

from ListNode import ListNode


class Solution:
    def rec(self, prev: Optional[ListNode], curr: Optional[ListNode]) -> Optional[ListNode]:
        if curr is None:
            return prev

        next = curr.next
        curr.next = prev
        prev = curr
        return self.rec(curr, next)

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.rec(None, head)
