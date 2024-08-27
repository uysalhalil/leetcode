#include <queue>
#include <vector>

class Solution {
   public:
    int lastStoneWeight(std::vector<int>& stones) {
        int s = stones.size();
        // edge case for single stone
        if (s == 1) return stones.back();

        std::priority_queue<int, std::vector<int>, std::less<int>> pq(
            stones.begin(), stones.end());
        while (s > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            s -= 2;
            if (s1 != s2) {
                pq.push(s1 - s2);
                ++s;
            }
        }
        return s > 0 ? pq.top() : 0;
    }
};