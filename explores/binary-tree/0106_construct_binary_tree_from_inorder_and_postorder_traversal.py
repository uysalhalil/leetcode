from typing import List, Optional

from TreeNode import TreeNode


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(postorder) <= 0:
            return None

        r = postorder[-1]
        rNode = TreeNode(r)

        for i in range(len(inorder)):
            if (inorder[i] == r):
                break

        rNode.left = self.buildTree(inorder[:i], postorder[:i])
        rNode.right = self.buildTree(inorder[i + 1:], postorder[i:-1])
        return rNode