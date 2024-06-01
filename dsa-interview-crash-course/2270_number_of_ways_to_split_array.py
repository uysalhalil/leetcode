from typing import List


class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        prev = 0
        prefix = []
        for i in range(len(nums)):
            prefix.append(prev + nums[i])
            prev = prefix[i]
        
        num_ways = 0
        for i in range(len(nums)-1):
            if (prefix[i] >= (prefix[-1] - prefix[i])):
                num_ways += 1
        
        return num_ways