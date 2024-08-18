from typing import List


class Solution:
    def buildGraph(self, n: int, edges: List[List[int]]) -> None:
        self.graph = dict()
        # set up graph if a node does not have an edge
        for i in range(n):
            self.graph[i] = []

        # set up graph with neighbors
        for edge in edges:
            self.graph[edge[0]].append(edge[1])
            self.graph[edge[1]].append(edge[0])


    def dfsTraverseGraph(self, source: int, destination: int) -> None:
        if source == destination:
            self.reached = True
            return

        if self.reached is True or self.visited[source]:
            return

        self.visited[source] = True
        for neighbor in self.graph[source]:
            self.dfsTraverseGraph(neighbor, destination)


    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        self.reached = False
        self.visited = [False] * n
        self.buildGraph(n, edges)
        self.dfsTraverseGraph(source, destination)
        return self.reached