#include <vector>
class Solution {
   public:
    void wiggleSort(std::vector<int>& nums) {
        std::vector<int> wind(3, 0);
        for (int i = 1; i < nums.size() - 1; i += 2) {
            std::copy(nums.begin() + i - 1, nums.begin() + i + 2, wind.begin());
            std::sort(wind.begin(), wind.end());
            nums[i - 1] = wind[0];
            nums[i] = wind[2];
            nums[i + 1] = wind[1];
        }
        if (!(nums.size() % 2) &&
            (nums[nums.size() - 2] > nums[nums.size() - 1])) {
            std::swap(nums[nums.size() - 2], nums[nums.size() - 1]);
        }
    }
};