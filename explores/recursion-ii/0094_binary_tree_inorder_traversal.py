from typing import List, Optional
from TreeNode import TreeNode


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        st = []
        if root is not None:
            st.append(root)
        while len(st) > 0:
            while (st[-1].left is not None):
                st.append(st[-1].left)

            res.append(st[-1].val)
            node = st.pop()
            while len(st) > 0 and node.right is None:
                res.append(st[-1].val)
                node = st.pop()

            if node.right is not None:
                st.append(node.right)

        return res