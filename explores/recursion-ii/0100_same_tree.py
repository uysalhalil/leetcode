from typing import Optional

from TreeNode import TreeNode

# Recursive
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False

        return p.val == q.val and self.isSameTree(p.left, q.left) and \
            self.isSameTree(p.right, q.right)


# Iterative
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        p_list = []
        q_list = []

        p_list.append(p)
        q_list.append(q)

        while len(p_list) > 0:
            if len(p_list) != len(q_list):
                return False

            if p_list[-1] is None and q_list[-1] is None:
                # pop the stack
                p_list.pop()
                q_list.pop()
                # process current node
                if len(p_list) == 0:
                    return True

                if p_list[-1].val != q_list[-1].val:
                    return False

                p_node = p_list.pop()
                q_node = q_list.pop()
                # push right node
                p_list.append(p_node.right)
                q_list.append(q_node.right)
            elif p_list[-1] is None or q_list[-1] is None:
                return False

            if p_list[-1] is not None:
                p_list.append(p_list[-1].left)

            if q_list[-1] is not None:
                q_list.append(q_list[-1].left)