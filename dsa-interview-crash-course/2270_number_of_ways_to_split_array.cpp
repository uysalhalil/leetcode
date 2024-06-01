#include <vector>

class Solution {
   public:
    int waysToSplitArray(std::vector<int>& nums) {
        std::vector<long> prefix(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = static_cast<long>(nums[i]) + prefix[i];
        }

        int num_ways = 0;
        for (int i = 1; i < prefix.size() - 1; ++i) {
            if (prefix[i] >= prefix.back() - prefix[i]) {
                ++num_ways;
            }
        }

        return num_ways;
    }
};