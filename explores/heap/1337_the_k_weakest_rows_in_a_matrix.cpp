#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        std::unordered_map<int, std::vector<int>> strengths;

        for (int row = 0; row < mat.size(); ++row) {
            int strength = 0;
            for (int col = 0; col < mat[row].size(); ++col) {
                strength += mat[row][col];
            }
            strengths[strength].push_back(row);
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (auto& [strength, idx] : strengths) {
            pq.push({strength});
        }

        std::vector<int> res;
        int currSize = 0;
        while (currSize < k) {
            int w = pq.top();
            pq.pop();
            currSize += strengths[w].size();
            res.insert(res.end(), strengths[w].begin(), strengths[w].end());
            while (currSize > k) {
                res.pop_back();
                --currSize;
            }
        }

        return res;
    }
};