#include <vector>
class Solution {
   private:
    int nRow{0};
    int nCol{0};
    int nIslands{0};
    std::vector<std::vector<bool>> visited;
    std::vector<std::pair<int, int>> directions{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isInside(const int &currentRow, const int &currentCol) {
        return 0 <= currentCol && currentCol < nCol && 0 <= currentRow &&
               currentRow < nRow;
    }

    void traverse(const std::vector<std::vector<char>> &grid, int currentRow,
                  int currentCol) {
        if (!isInside(currentRow, currentCol) ||
            visited[currentRow][currentCol] == true ||
            grid[currentRow][currentCol] != '1')
            return;

        visited[currentRow][currentCol] = true;

        for (auto &[x, y] : directions) {
            traverse(grid, currentRow + x, currentCol + y);
        }
    }

   public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        nRow = grid.size();
        nCol = grid[0].size();
        visited.resize(nRow, std::vector<bool>(nCol, false));
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ++nIslands;
                    traverse(grid, i, j);
                }
            }
        }
        return nIslands;
    }
};