#include <numeric>
#include <vector>

class Solution {
   public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        int prev = 0;
        std::vector<int> prefix_sum(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i] = prev + nums[i];
            prev = prefix_sum[i];
        }
        return prefix_sum;
    }

    std::vector<int> runningSumStd(std::vector<int>& nums) {
        int prev = 0;
        std::vector<int> prefix_sum(nums.size(), 0);
        std::partial_sum(nums.begin(), nums.end(), prefix_sum.begin());
        return prefix_sum;
    }
};