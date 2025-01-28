from typing import List

import UnionFind


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def cost_to_connect(x: List[int], y: List[int]) -> int:
            return abs(x[0] - y[0]) + abs(x[1] - y[1])

        edges = []
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                edges.append([i, j, cost_to_connect(points[i], points[j])])

        total_cost = 0
        n_edges = 0
        uf = UnionFind(len(points))
        edges.sort(key=lambda x: x[-1], reverse=True)
        while n_edges < len(points) - 1:
            t = edges.pop()
            if not uf.connected(t[0], t[1]):
                uf.union(t[0], t[1])
                n_edges += 1
                total_cost += t[2]

        return total_cost
