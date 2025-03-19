from typing import List


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        i = 0
        j = 0
        nZeros = 0
        maxOnes = 0
        while j < len(nums):
            if nums[j] == 0:
                nZeros += 1
            if nZeros > k:
                while nums[i] == 1:
                    i += 1
                i += 1
                nZeros = k
            maxOnes = max(maxOnes, j - i + 1)
            j += 1

        return maxOnes