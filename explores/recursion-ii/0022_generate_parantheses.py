from typing import List


class Solution:

    def solve(self, left: int, right: int, curr: str, res: List) -> None:
        if (left == 0 and right == 0):
            res.append(curr)
            return

        if (left == right):
            curr += "("
            self.solve(left - 1, right, curr, res)
        elif (left == 0):
            curr += ")"
            self.solve(left, right - 1, curr, res)
        else:
            curr += "("
            self.solve(left - 1, right, curr, res)
            curr = curr[:-1]
            curr += ")"
            self.solve(left, right - 1, curr, res)

    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        self.solve(n, n, "", res)
        return res
