from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def checkSum(self, root: Optional[TreeNode], targetSum: int, currentSum: int) -> bool:
        if root is None:
            return False

        if (root.left is None and root.right is None):
            return currentSum + root.val == targetSum
        

            
        return self.checkSum(root.left, targetSum, currentSum + root.val) or \
            self.checkSum(root.right, targetSum, currentSum + root.val)


    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        
        return self.checkSum(root, targetSum, 0)