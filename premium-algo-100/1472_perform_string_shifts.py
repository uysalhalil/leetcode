from typing import List


class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        # compute shift amounts
        shiftAmount = 0
        for sh in shift:
            if sh[0] == 0:
                shiftAmount -= sh[1]
            else:
                shiftAmount += sh[1]

        shiftAmount %= len(s)
        res = ""

        for i in range(len(s)):
            res += s[(i - shiftAmount) % len(s)]

        return res