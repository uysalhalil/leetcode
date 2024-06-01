from typing import List


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l = 0
        max_width = 0
        for i in range(len(nums)):
            if (nums[i] == 0):
                k -= 1
            
            if k < 0:
                if (nums[l] == 0):
                    k += 1
                l += 1
            
            max_width = max(max_width, i - l + 1)
            
        return max_width