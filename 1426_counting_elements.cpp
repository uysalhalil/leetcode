#include <unordered_map>
#include <vector>

class Solution {
   public:
    int countElements(std::vector<int> &arr) {
        std::unordered_map<int, int> map;
        for (auto &a : arr) {
            ++map[a];
        }

        int elem = 0;
        for (auto &[key, freq] : map) {
            if (map.find(key + 1) != map.end()) elem += freq;
        }

        return elem;
    }
};