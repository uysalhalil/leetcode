#include <unordered_set>
#include <vector>

class Solution {
   private:
    int n;
    std::vector<std::vector<int>> res;
    std::unordered_set<int> used_values;
    std::vector<int> curr_permutation = {};

    void solve(const std::vector<int>& nums) {
        // goal
        if (curr_permutation.size() == n) {
            res.push_back(curr_permutation);
            return;
        }

        // choices
        for (int i = 0; i < n; ++i) {
            // constraint
            if (used_values.find(nums[i]) == used_values.end()) {
                used_values.insert(nums[i]);
                curr_permutation.push_back(nums[i]);
                solve(nums);
                // backtrack
                used_values.erase(nums[i]);
                curr_permutation.pop_back();
            }
        }
    }

   public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        n = nums.size();
        solve(nums);
        return res;
    }
};