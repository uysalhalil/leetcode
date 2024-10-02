from typing import Optional

from TreeNode import TreeNode


class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        newNode = TreeNode(val)
        if root is None:
            return newNode

        prevNode = None
        currNode = root
        while currNode is not None:
            prevNode = currNode
            if currNode.val > val:
                currNode = currNode.left
            else:
                currNode = currNode.right

        if prevNode.val > val:
            prevNode.left = newNode
        else:
            prevNode.right = newNode

        return root