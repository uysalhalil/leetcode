from typing import List


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        inc, dec = False, False

        for i in range(1,len(nums)):
            if (nums[i] > nums[i-1]):
                inc = True
            
            if (nums[i] < nums[i-1]):
                dec = True
        
        return not(inc and dec)