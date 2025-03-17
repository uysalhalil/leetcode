from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        result = [False] * len(candies)
        maxValue = max(candies)
        for i in range(len(candies)):
            if candies[i] + extraCandies >= maxValue:
                result[i] = True

        return result