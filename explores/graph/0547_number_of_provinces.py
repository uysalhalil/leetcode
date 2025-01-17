from typing import List

from UnionFind import UnionFind


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        uf = UnionFind(n)

        for i in range(n):
            for j in range(n):
                if isConnected[i][j]:
                    uf.union(i, j)

        return uf.provinces