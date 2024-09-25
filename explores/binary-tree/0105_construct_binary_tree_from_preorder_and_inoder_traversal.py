from typing import List, Optional

from TreeNode import TreeNode


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) <= 0:
            return None

        r = preorder[0]
        rNode = TreeNode(r)

        for i in range(len(inorder)):
            if (inorder[i] == r):
                break

        rNode.left = self.buildTree(preorder[1:i + 1], inorder[:i])
        rNode.right = self.buildTree(preorder[i + 1:], inorder[i + 1:])
        return rNode