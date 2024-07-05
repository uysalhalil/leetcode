#include <vector>

class Solution {
   public:
    int pivotIndex(std::vector<int>& nums) {
        int prev = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] += prev;
            prev = nums[i];
        }

        prev = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int post = nums.back() - nums[i];
            if (prev == post) return i;
            prev = nums[i];
        }
        return -1;
    }
};