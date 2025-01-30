from typing import List


class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        # I need to figure out the out degrees of the edges
        n = len(edges)
        n_edges = [0 for x in range(n + 1)]
        for edge in edges:
            n_edges[edge[0] - 1] += 1
            n_edges[edge[1] - 1] += 1
            if n_edges[edge[0] - 1] == n:
                return edge[0]
            if n_edges[edge[1] - 1] == n:
                return edge[1]

        return -1