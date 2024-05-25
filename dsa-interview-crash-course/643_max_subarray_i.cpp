#include <vector>

class Solution
{
public:
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        double subSum = 0;
        for (int i = 0; i < k; ++i)
            subSum += static_cast<double>(nums[i]);
        double maxAvg = subSum / k;
        for (int i = k; i < nums.size(); ++i)
        {
            subSum -= nums[i - k];
            subSum += nums[i];
            maxAvg = std::max(maxAvg, subSum / k);
        }
        return maxAvg;
    }
};