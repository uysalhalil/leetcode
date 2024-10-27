#include <vector>

class Solution {
   public:
    std::vector<int> mergeSort(std::vector<int> nums) {
        if (nums.size() <= 1) {
            return nums;
        }

        int m = static_cast<int>(nums.size()) / 2;

        // create helper vectors
        std::vector<int> left{nums.begin(), nums.begin() + m};
        std::vector<int> right{nums.begin() + m, nums.end()};

        // divide left and right
        left = mergeSort(left);
        right = mergeSort(right);

        // conquer
        std::vector<int> merged(left.size() + right.size(), 0);
        int i = 0, j = 0, k = 0;
        while (i < merged.size()) {
            if (j >= left.size()) {
                merged[i] = right[k];
                ++k;
            } else if (k >= right.size()) {
                merged[i] = left[j];
                ++j;
            } else if (left[j] <= right[k]) {
                merged[i] = left[j];
                ++j;
            } else {
                merged[i] = right[k];
                ++k;
            }
            ++i;
        }
        return merged;
    }

    std::vector<int> sortArray(std::vector<int>& nums) {
        return mergeSort(nums);
    }
};