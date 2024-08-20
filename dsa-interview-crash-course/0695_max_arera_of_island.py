from typing import List


class Solution:
    def inGraph(self, row: int, col: int) -> bool:
        return (0 <= row and row < self.rows) and \
            (0 <= col and col < self.cols)

    def dfsTraverseGraph(self, row: int, col: int, grid: List[List[int]]) -> None:
        if not self.inGraph(row, col) or self.visited[row][col]:
            return

        self.visited[row][col] = True

        if grid[row][col] == 0:
            return

        self.currentArea += grid[row][col]
        for direction in self.directions:
            self.dfsTraverseGraph(row + direction[0], col + direction[1], grid)

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.rows = len(grid)
        self.cols = len(grid[0])
        # self.visited = [[False] * self.cols] * self.rows
        self.visited = [[False for _ in range(self.cols)] for _ in range(self.rows)]
        self.directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        maxArea = 0
        for row in range(self.rows):
            for col in range(self.cols):
                if grid[row][col] == 1:
                    if not self.visited[row][col]:
                        self.currentArea = 0
                        self.dfsTraverseGraph(row, col, grid)
                        maxArea = max(maxArea, self.currentArea)
                else:
                    self.visited[row][col] = True

        return maxArea
