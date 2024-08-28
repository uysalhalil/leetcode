#include <queue>
#include <vector>

class Solution {
   public:
    int connectSticks(std::vector<int>& sticks) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq(
            sticks.begin(), sticks.end());

        int cost{0};

        while (pq.size() > 1) {
            int v1 = pq.top();
            pq.pop();
            int v2 = pq.top();
            pq.pop();
            cost += (v1 + v2);
            pq.push(v1 + v2);
        }

        return cost;
    }
};