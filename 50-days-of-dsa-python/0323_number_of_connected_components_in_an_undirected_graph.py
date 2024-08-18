from typing import List


class Solution:
    def buildUndirectedGraph(self, n: int, edges: List[List[int]]) -> None:
        self.graph = {x: [] for x in range(n)}
        for edge in edges:
            self.graph[edge[0]].append(edge[1])
            self.graph[edge[1]].append(edge[0])

    def dfsTraverseGraph(self, source: int) -> None:
        if self.visited[source]:
            return

        self.visited[source] = True

        for neighbor in self.graph[source]:
            self.dfsTraverseGraph(neighbor)


    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        self.buildUndirectedGraph(n, edges)
        self.visited = [False] * n

        nComponents = 0
        for i in range(n):
            if not self.visited[i]:
                nComponents += 1
                self.dfsTraverseGraph(i)

        return nComponents