from itertools import accumulate
from typing import List


class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        cum_sum = list(accumulate(nums))
        min_val = min(cum_sum)
        return 1 if min_val > 0 else (abs(min_val) + 1) 