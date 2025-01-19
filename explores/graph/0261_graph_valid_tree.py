from collections import deque
from copy import copy
from typing import List

from UnionFind import UnionFind


class Solution:
    def buildTree(self, n, edges) -> None:
        self.graph = {}
        # undirected graph building
        for i in range(n):
            self.graph[i] = set()

        if len(edges) > 0:
            for edge in edges:
                self.graph[edge[0]].add(edge[1])
                self.graph[edge[1]].add(edge[0])

    def hasCycle(self) -> bool:
        g = copy.deepcopy(self.graph) # deep copy
        visited = set()
        keys = list(g.keys())
        nodes_queue = deque()
        nodes_queue.append(keys[0])
        while len(nodes_queue) > 0:
            source = nodes_queue.popleft()
            if source in visited:
                return True

            visited.add(source)
            neighbors = g[source]
            for i in neighbors:
                if i != source:
                    nodes_queue.append(i)
                    g[i].remove(source)

        return False

    def canVisit(self) -> bool:
        g = copy.deepcopy(self.graph)
        visited = set()
        keys = list(g.keys())
        nodes_queue = deque()
        nodes_queue.append(keys[0])
        while len(nodes_queue) > 0:
            source = nodes_queue.popleft()
            visited.add(source)
            neighbors = g[source]
            for i in neighbors:
                if i != source:
                    nodes_queue.append(i)
                    g[i].remove(source)

        for k in list(self.graph.keys()):
            if k not in visited:
                return False

        return True


    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # Solution 1 - sort of brute force
        # self.buildTree(n, edges)
        # return (not self.hasCycle()) and self.canVisit()
        
        uf = UnionFind(n)
        for edge in edges:
            uf.union(edge[0], edge[1])

        return (not uf.hasCycle) and (uf.numRoots == 1)
        