#include <cmath>
#include <queue>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> kClosest(
        std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<double, std::vector<int>>,
                            std::vector<std::pair<double, std::vector<int>>>,
                            std::less<std::pair<double, std::vector<int>>>>
            pq;

        for (auto& point : points) {
            double dist =
                std::sqrt(std::pow(point[0], 2.0) + std::pow(point[1], 2.0));
            pq.push({dist, {point[0], point[1]}});
            if (pq.size() > k) pq.pop();
        }
        std::vector<std::vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};