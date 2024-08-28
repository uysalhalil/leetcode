#include <queue>
#include <vector>

class Solution {
   public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        pq.push(intervals[0][1]);
        int nRooms{static_cast<int>(pq.size())};
        for (int i = 1; i < intervals.size(); ++i) {
            if (pq.top() <= intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
            nRooms = std::max(nRooms, static_cast<int>(pq.size()));
        }
        return nRooms;
    }
};