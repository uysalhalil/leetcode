from typing import List


class Solution:
    def buildGraph(self, n: int, edges: List[List[int]]) -> None:
        self.graph = {x: [] for x in range(n)}
        for edge in edges:
            if (edge[0] not in self.restricted) and (edge[1] not in self.restricted):
                self.graph[edge[0]].append(edge[1])
                self.graph[edge[1]].append(edge[0])


    def dfsGraphTraversal(self, source: int) -> None:
        if self.visited[source]:
            return

        self.visited[source] = True

        self.nNodes += 1
        for neighbor in self.graph[source]:
            self.dfsGraphTraversal(neighbor)

    def bfsGraphTraversal(self, source: int) -> int:
        nNodes = 1
        next_nodes = self.graph[source]
        self.visited[source] = True

        i = 0
        while i < len(next_nodes):
            if not self.visited[next_nodes[i]]:
                nNodes += 1
                self.visited[next_nodes[i]] = True
                for neighbor in self.graph[next_nodes[i]]:
                    if not self.visited[neighbor]:
                        next_nodes.append(neighbor)
            i += 1

        return nNodes


    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        self.restricted = set(restricted)
        self.buildGraph(n, edges)
        self.visited = [False for _ in range(n)]
        # self.nNodes = 0
        # self.dfsGraphTraversal(0)
        return self.bfsGraphTraversal(0)
        # return self.nNodes