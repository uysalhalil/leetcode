from typing import List


class Solution:
    def getEquationNodes(self, equations: List[List[str]]) -> None:
        self.nodes = set()
        for equation in equations:
            self.nodes.add(equation[0])
            self.nodes.add(equation[1])

    def traverseGraph(self, source: str, destination: str, value: float) -> None:
        if (source == destination):
            self.reached = True
            self.value = value
            return

        self.visited.add(source)
        for neighbor in self.graph[source]:
            if neighbor[0] not in self.visited:
                self.traverseGraph(neighbor[0], destination, neighbor[1] * value)


    def buildEquationGraph(self, equations: List[List[str]], values: List[float]) -> None:
        self.graph = {}
        for i, equation in enumerate(equations):
            if equation[0] not in self.graph:
                self.graph[equation[0]] = []
            self.graph[equation[0]].append([equation[1], values[i]])

            if equation[1] not in self.graph:
                self.graph[equation[1]] = []
            self.graph[equation[1]].append([equation[0], 1 / values[i]])

    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        self.buildEquationGraph(equations, values)
        self.getEquationNodes(equations)

        res = [-1] * len(queries)
        for i, query in enumerate(queries):
            if query[0] in self.nodes and query[1] in self.nodes:
                self.reached = False
                self.visited = set()
                self.traverseGraph(query[0], query[1], 1)
                if self.reached:
                    res[i] = self.value

        return res