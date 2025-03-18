from collections import defaultdict
from typing import List


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nOp = 0
        freqMap = defaultdict(int)
        for n in nums:
            freqMap[n] += 1

        for key in freqMap.keys():
            target = k - key
            if target == key:
                while freqMap[key] > 1:
                    freqMap[key] -= 2
                    nOp += 1
            elif target in freqMap:
                while freqMap[key] and freqMap[target] > 0:
                    freqMap[key] -= 1
                    freqMap[target] -= 1
                    nOp += 1

        return nOp