from typing import List
from UnionFind import UnionFind


class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:

        logs.sort(key=lambda x: x[0])
        uf = UnionFind(n)
        for log in logs:
            uf.union(log[1], log[2])
            if uf.provinces == 1:
                return log[0]

        return -1