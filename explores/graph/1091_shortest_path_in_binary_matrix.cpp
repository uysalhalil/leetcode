#include <queue>
#include <vector>

class Solution {
   public:
    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
        // by the description of the question "nxn"
        const std::vector<std::pair<int, int>> directions{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
            {1, 1},   {1, 0},  {1, -1}, {0, -1}};
        const int n = static_cast<int>(grid.size());
        // initial edge case
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        // set up the queue for the BFS
        std::queue<std::pair<int, int>> level;
        // visited matrix for not visiting twice
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

        auto checkBoundary = [&n](const int& row, const int& col) -> bool {
            return row >= 0 && row < n && col >= 0 && col < n;
        };

        auto checkAvailable = [&grid, &visited](const int& row,
                                                const int& col) -> bool {
            return grid[row][col] == 0 && !visited[row][col];
        };

        level.push({0, 0});
        visited[0][0] = true;
        int currentPathLength = 1;
        while (!level.empty()) {
            std::queue<std::pair<int, int>> nextLevel;
            while (!level.empty()) {
                auto [row, col] = level.front();
                level.pop();
                if (row == n - 1 && col == n - 1) {
                    return currentPathLength;
                }
                for (auto& [rowDir, colDir] : directions) {
                    const int&& nextRow = row + rowDir;
                    const int&& nextCol = col + colDir;
                    if (checkBoundary(nextRow, nextCol) &&
                        checkAvailable(nextRow, nextCol)) {
                        nextLevel.push({nextRow, nextCol});
                        visited[nextRow][nextCol] = true;
                    }
                }
            }
            level = nextLevel;
            ++currentPathLength;
        }
        return -1;
    }
};