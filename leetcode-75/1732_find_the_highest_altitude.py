from typing import List


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        maxHeight = 0
        currentHeight = 0
        for g in gain:
            currentHeight += g
            maxHeight = max(maxHeight, currentHeight)
        return maxHeight
