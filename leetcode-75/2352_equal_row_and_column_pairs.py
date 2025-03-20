from collections import defaultdict
from typing import List


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        rowMap = defaultdict(int)
        for i in range(len(grid)):
            row = ",".join([str(x) for x in grid[i]])
            rowMap[row] += 1

        nMatches = 0
        for j in range(len(grid)):
            col = ",".join([str(x[j]) for x in grid])
            if col in rowMap:
                nMatches += rowMap[col]

        return nMatches