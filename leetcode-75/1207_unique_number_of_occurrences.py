from collections import defaultdict
from typing import List


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freqMap = defaultdict(int)
        for n in arr:
            freqMap[n] += 1
        freqSet = set()
        for freq in freqMap.values():
            if freq in freqSet:
                return False
            freqSet.add(freq)
        return True