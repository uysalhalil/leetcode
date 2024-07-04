from typing import List


class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        map = {}
        for num in nums:
            if num in map:
                map[num] += 1
            else:
                map[num] = 1

        mx = -1
        for (key, val) in map.items():
            if (val == 1):
                mx = max(mx, key)
        
        return mx