from typing import List


class Solution:
    def dfsWithBacktracking(self, graph: List[List[int]], currentPath: List[int], source: int, destination: int) -> None:
        if source == destination:
            currentPath.append(source)
            self.allPaths.append(list(currentPath))
            currentPath.pop()
            return

        if source in self.visited:
            return

        currentPath.append(source)
        self.visited.add(source)
        for neighbor in graph[source]:
            if neighbor not in self.visited:
                self.dfsWithBacktracking(graph, currentPath, neighbor, destination)

        currentPath.pop()
        self.visited.remove(source)


    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.visited = set()
        self.allPaths = []
        self.dfsWithBacktracking(graph, [], 0, len(graph) - 1)
        return self.allPaths