#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        for (auto& num : nums) ++freqMap[num];
        std::priority_queue<std::pair<int, int>> maxHeap;
        for (auto& [key, freq] : freqMap) maxHeap.push({freq, key});
        std::vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};