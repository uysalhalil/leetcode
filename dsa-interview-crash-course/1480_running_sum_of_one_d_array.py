from itertools import accumulate
from typing import List


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        return list(accumulate(nums))
