#include <vector>

class Solution {
   public:
    int maxDistance(std::vector<std::vector<int>>& arrays) {
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();

        int maxDist = -1;

        for (int i = 1; i < arrays.size(); ++i) {
            int nextMinVal = arrays[i].front();
            int nextMaxVal = arrays[i].back();

            maxDist = std::max(std::max(std::abs(nextMinVal - maxVal),
                                        std::abs(nextMaxVal - minVal)),
                               maxDist);
            maxVal = std::max(maxVal, nextMaxVal);
            minVal = std::min(minVal, nextMinVal);
        }
        return maxDist;
    }
};