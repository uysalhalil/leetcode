#include <string>
#include <unordered_map>

class Solution {
   public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> magazine_map;
        for (auto& c : magazine) ++magazine_map[c];

        for (auto& c : ransomNote) {
            if (magazine_map.find(c) == magazine_map.end() ||
                magazine_map[c] == 0)
                return false;
            --magazine_map[c];
        }
        return true;
    }
};