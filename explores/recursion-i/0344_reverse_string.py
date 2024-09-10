from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        left = 0
        right = len(s) - 1


        def rec(s: List[str], left: int, right: int) -> None:
            if (left >= right):
                return

            [s[left], s[right]] = [s[right], s[left]]
            left += 1
            right -= 1
            rec(s, left, right)

        rec(s, left, right)
        return