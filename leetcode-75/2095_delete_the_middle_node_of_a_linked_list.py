from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dmyHead = ListNode(0, head)
        prev = dmyHead
        midNode = head
        fast = head

        while (fast and fast.next):
            prev = midNode
            midNode = midNode.next
            fast = fast.next.next

        prev.next = midNode.next
        midNode.next = None

        return dmyHead.next