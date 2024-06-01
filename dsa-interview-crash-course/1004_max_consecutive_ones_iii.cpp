#include <vector>

class Solution {
   public:
    int longestOnes(std::vector<int> &nums, int k) {
        int l = 0;
        int max_width = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) {
                --k;
            }
            if (k < 0) {
                if (!nums[l]) {
                    ++k;
                }
                ++l;
            }
            max_width = std::max(max_width, i - l + 1);
        }
        return max_width;
    }
};