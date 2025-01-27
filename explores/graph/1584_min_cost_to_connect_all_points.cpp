#include <climits>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        auto costToConnect = [](const std::vector<int>& p1,
                                const std::vector<int>& p2) -> int {
            return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
        };

        int minCost = 0;
        std::vector<int> connectedNodes;
        connectedNodes.push_back(0);
        std::unordered_set<int> visited;
        visited.insert(0);
        while (connectedNodes.size() < points.size()) {
            int cost = INT_MAX;
            int nodeToConnect = static_cast<int>(points.size());
            for (int i = 0; i < points.size(); ++i) {
                if (visited.find(i) == visited.end()) {
                    int currentCost =
                        costToConnect(points[connectedNodes[0]], points[i]);
                    for (int j = 1; j < connectedNodes.size(); ++j) {
                        currentCost =
                            std::min(currentCost,
                                     costToConnect(points[connectedNodes[j]],
                                                   points[i]));
                    }
                    if (cost > currentCost) {
                        cost = currentCost;
                        nodeToConnect = i;
                    }
                }
            }
            visited.insert(nodeToConnect);
            connectedNodes.push_back(nodeToConnect);
            minCost += cost;
        }
        return minCost;
    }
};