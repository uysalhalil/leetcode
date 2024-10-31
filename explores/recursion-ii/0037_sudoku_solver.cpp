#include <vector>

class Solution {
   private:
    std::vector<std::vector<bool>> cols;
    std::vector<std::vector<bool>> rows;
    std::vector<std::vector<bool>> subBoard;

   public:
    int getSubBoardIndex(int row, int col) {
        // key 3
        int rowMod = row / 3;
        int colMod = col / 3;
        return rowMod * 3 + colMod;
    }
    bool solve(int row, int col, std::vector<std::vector<char>>& board) {
        if (col == board[0].size()) {
            col = 0;
            ++row;
        }
        // goal
        if (row == board.size()) {
            return true;
        }

        // key 1
        if (board[row][col] != '.') {
            return solve(row, col + 1, board);
        }

        int subBoardIndex = getSubBoardIndex(row, col);
        // choices
        for (int i = 0; i < 9; ++i) {
            // constraints
            if (!rows[row][i] && !cols[col][i] && !subBoard[subBoardIndex][i]) {
                // track
                rows[row][i] = true;
                cols[col][i] = true;
                subBoard[subBoardIndex][i] = true;
                board[row][col] = i + 1 + '0';
                // recurse
                if (solve(row, col + 1, board)) {
                    return true;
                }
                // backtrack
                board[row][col] = '.';
                subBoard[subBoardIndex][i] = false;
                cols[col][i] = false;
                rows[row][i] = false;
            }
        }

        return false;
    }
    void solveSudoku(std::vector<std::vector<char>>& board) {
        cols.resize(9, std::vector<bool>(9, false));
        rows.resize(9, std::vector<bool>(9, false));
        subBoard.resize(9, std::vector<bool>(9, false));

        // key 2
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    int subBoardIndex = getSubBoardIndex(i, j);
                    cols[j][board[i][j] - '0' - 1] = true;
                    rows[i][board[i][j] - '0' - 1] = true;
                    subBoard[subBoardIndex][board[i][j] - '0' - 1] = true;
                }
            }
        }
        solve(0, 0, board);
    }
};