#include <stack>
#include <utility>
#include <vector>

class Solution {
   public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<std::pair<int, int>> temps;
        std::vector<int> days(temperatures.size(), 0);

        temps.push({temperatures.front(), 0});
        for (int i = 1; i < temperatures.size(); ++i) {
            while (!temps.empty() && (temps.top().first < temperatures[i])) {
                days[temps.top().second] = i - temps.top().second;
                temps.pop();
            }
            temps.push({temperatures[i], i});
        }
        return days;
    }
};