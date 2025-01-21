from typing import Optional
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def buildConnections(self, node: Optional["Node"]):
        if node.val in self.visited:
            return

        self.visited.add(node.val)
        # undirected graph connection
        for neighbor in node.neighbors:
            if neighbor.val not in self.visited:
                self.graph[node.val].neighbors.append(self.graph[neighbor.val])
                self.graph[neighbor.val].neighbors.append(self.graph[node.val])

        for neighbor in node.neighbors:
            self.buildConnections(neighbor)


    def generateNodes(self, node: Optional["Node"]) -> None:
        if node.val in self.graph:
            return

        n = Node(node.val)
        self.graph[node.val] = n
        for neigbor in node.neighbors:
            self.generateNodes(neigbor)

    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return None

        self.visited = set()
        self.graph = {}
        # create cloned nodes
        self.generateNodes(node)
        # build connections
        self.buildConnections(node)

        return self.graph[1]
