#include <string>
#include <unordered_map>
class Solution {
   public:
    bool areOccurrencesEqual(std::string s) {
        std::unordered_map<char, int> map;
        for (auto &c : s) {
            ++map[c];
        }
        int prev = map.begin()->second;
        for (auto &[key, val] : map) {
            if (val != prev) {
                return false;
            }
        }

        return true;
    }
};