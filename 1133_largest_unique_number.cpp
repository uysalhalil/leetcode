#include <unordered_map>
#include <vector>

class Solution {
   public:
    int largestUniqueNumber(std::vector<int> &nums) {
        int mx = -1;

        std::unordered_map<int, int> map;
        for (auto &num : nums) ++map[num];

        for (auto &[key, val] : map)
            if (val == 1) mx = std::max(mx, key);

        return mx;
    }
};