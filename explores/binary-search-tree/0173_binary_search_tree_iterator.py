from typing import Optional

from TreeNode import TreeNode


class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.dfs_stack = []
        temp = root
        while temp is not None:
            self.dfs_stack.append(temp)
            temp = temp.left

    def next(self) -> int:
        temp = self.dfs_stack[-1]
        val = temp.val
        self.dfs_stack.pop(-1)
        temp = temp.right
        while temp is not None:
            self.dfs_stack.append(temp)
            temp = temp.left

        return val


    def hasNext(self) -> bool:
        return len(self.dfs_stack) > 0