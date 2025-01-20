from typing import List
from UnionFind import UnionFind


class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        uf = UnionFind(n)
        for edge in edges:
            uf.union(edge[0], edge[1])

        return uf.connected(source, destination)
