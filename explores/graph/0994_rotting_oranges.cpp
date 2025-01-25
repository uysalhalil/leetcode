#include <vector>
class Solution {
   public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        const std::vector<std::pair<int, int>> directions{
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        const int n = static_cast<int>(grid.size());
        const int m = static_cast<int>(grid[0].size());

        auto getNumOfFreshOranges = [&grid, &n, &m]() -> int {
            int numOfFreshOranges(0);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 1) {
                        ++numOfFreshOranges;
                    }
                }
            }
            return numOfFreshOranges;
        };
        int numOfFreshOranges = getNumOfFreshOranges();
        if (numOfFreshOranges == 0) {
            return 0;
        }

        auto getRottenOranges = [&grid, &n,
                                 &m]() -> std::vector<std::pair<int, int>> {
            std::vector<std::pair<int, int>> rottenOranges;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 2) {
                        rottenOranges.push_back({i, j});
                    }
                }
            }
            return rottenOranges;
        };
        std::vector<std::pair<int, int>> rottenOranges = getRottenOranges();

        auto checkBoundary = [&n, &m](const int& row, const int& col) -> bool {
            return row >= 0 && row < n && col >= 0 && col < m;
        };

        auto checkAvailable = [&grid](const int& row, const int& col) -> bool {
            return grid[row][col] == 1;
        };

        int time(0);
        while (!rottenOranges.empty()) {
            ++time;
            std::vector<std::pair<int, int>> nextFrontierRottenOranges;
            while (!rottenOranges.empty()) {
                auto [row, col] = rottenOranges.back();
                rottenOranges.pop_back();
                for (auto& [rowDir, colDir] : directions) {
                    const int nextRow = row + rowDir;
                    const int nextCol = col + colDir;
                    if (checkBoundary(nextRow, nextCol) &&
                        checkAvailable(nextRow, nextCol)) {
                        --numOfFreshOranges;
                        grid[nextRow][nextCol] = 2;
                        nextFrontierRottenOranges.push_back({nextRow, nextCol});
                    }
                }
            }
            rottenOranges = nextFrontierRottenOranges;
            if (numOfFreshOranges <= 0) {
                return time;
            }
        }
        return numOfFreshOranges == 0 ? time : -1;
    }
};