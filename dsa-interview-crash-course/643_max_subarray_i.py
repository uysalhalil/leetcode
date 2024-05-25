from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        subSum = 0
        for i in range(k):
            subSum += nums[i]
        
        maxAvg = subSum / k
        for i in range(k, len(nums)):
            subSum -= nums[i-k]
            subSum += nums[i]
            maxAvg = max(maxAvg, subSum/k)
        
        return maxAvg