from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        prefixSum = [0] * (len(nums) + 2)
        for i in range(1, len(nums) + 1):
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1]

        for i in range(1, len(nums) + 1):
            leftside = prefixSum[i - 1]
            rightside = prefixSum[-2] - prefixSum[i]
            if leftside == rightside:
                return i - 1

        return -1