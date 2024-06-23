#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
   public:
    int minStartValue(std::vector<int>& nums) {
        std::vector<int> cum_sum(nums.size(), 0);
        std::partial_sum(nums.begin(), nums.end(), cum_sum.begin());
        int min_val = *std::min_element(cum_sum.begin(), cum_sum.end());
        return min_val > 0 ? 1 : abs(min_val) + 1;
    }
};