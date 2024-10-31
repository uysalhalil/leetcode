#include <unordered_set>
#include <vector>

class Solution {
   private:
    int nSolutions = 0;
    std::vector<std::vector<bool>> board;
    std::unordered_set<int> cols, diag, xDiag;

    void solve(int row) {
        // goal
        if (row == board.size()) {
            ++nSolutions;
            return;
        }
        // choices
        for (int c = 0; c < board.size(); ++c) {
            // constraints
            if (cols.find(c) == cols.end() &&
                diag.find(row - c) == diag.end() &&
                xDiag.find(row + c) == xDiag.end()) {
                // track
                cols.insert(c);
                diag.insert(row - c);
                xDiag.insert(row + c);
                board[row][c] = true;
                // recurse
                solve(row + 1);
                // backtrack
                board[row][c] = false;
                xDiag.erase(row + c);
                diag.erase(row - c);
                cols.erase(c);
            }
        }
    }

   public:
    int totalNQueens(int n) {
        board.resize(n, std::vector<bool>(n, false));
        solve(0);
        return nSolutions;
    }
};