from typing import List


class Solution:
    def countElements(self, arr: List[int]) -> int:
        map = {}

        for a in arr:
            if a in map:
                map[a] += 1
            else:
                map[a] = 1

        elem = 0
        for (val, freq) in map.items():
            if (val + 1) in map.keys():
                elem += freq

        return elem