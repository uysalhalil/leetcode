#include <vector>

class Solution {
   private:
    std::vector<int> curr;
    std::vector<std::vector<int>> res;

    void solve(int n, int k, int idx) {
        // goal
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }

        // choices - options
        for (int i = idx; i <= n; ++i) {
            curr.push_back(i);
            solve(n, k, i + 1);
            curr.pop_back();
        }
    }

   public:
    std::vector<std::vector<int>> combine(int n, int k) {
        solve(n, k, 1);
        return res;
    }
};