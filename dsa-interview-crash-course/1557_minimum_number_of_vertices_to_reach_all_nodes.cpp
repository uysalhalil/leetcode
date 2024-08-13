#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
   private:
    std::vector<bool> visited;                               // visited nodes
    std::unordered_set<int> startingNodes;                   // starting nodes
    std::unordered_map<int, std::unordered_set<int>> graph;  // build graph

    void buildGraph(const std::vector<std::vector<int>> &edges) {
        for (auto &edge : edges) {
            graph[edge[0]].insert(edge[1]);
        }
    }

    void dfs(int currentNode) {
        if (visited[currentNode]) {
            if (startingNodes.find(currentNode) != startingNodes.end()) {
                startingNodes.erase(currentNode);
            }
            return;
        }
        visited[currentNode] = true;
        for (auto neighbor : graph[currentNode]) {
            dfs(neighbor);
        }
    }

   public:
    std::vector<int> findSmallestSetOfVertices(
        int n, std::vector<std::vector<int>> &edges) {
        // initialize variables
        visited.resize(n, false);
        std::vector<int> res{};

        // build graph
        buildGraph(edges);

        // traverse graph
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                startingNodes.insert(i);
                dfs(i);
            }
        }

        for (auto &startingNode : startingNodes) {
            res.push_back(startingNode);
        }

        // sort(begin(res), end(res));
        return res;
    }
};