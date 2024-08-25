from typing import Optional
from ListNode import ListNode


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(-1000, head)
        prev = dummyHead
        curr = head
        while curr is not None and curr.next is not None:
            if curr.val == curr.next.val:
                valToCompare = curr.val
                while curr is not None and curr.val == valToCompare:
                    prev.next = curr.next
                    curr.next = None
                    curr = prev.next
            else:
                prev = curr
                curr = curr.next

        return dummyHead.next