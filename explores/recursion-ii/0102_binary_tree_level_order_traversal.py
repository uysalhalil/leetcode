from typing import List, Optional

from TreeNode import TreeNode


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        curr_level = 0

        def solve(node: Optional[TreeNode], curr_level: int) -> None:
            if node is None:
                return
            elif curr_level == len(res):
                res.append([])
                res[-1].append(node.val)
            else:
                res[curr_level].append(node.val)
            
            solve(node.left, curr_level+1)
            solve(node.right, curr_level+1)
        
        solve(root, curr_level)
        return res