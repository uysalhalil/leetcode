#include <climits>
#include <string>
#include <unordered_map>
class Solution {
   public:
    int maxNumberOfBalloons(std::string text) {
        std::string search_word = "balloon";
        std::unordered_map<char, int> search_space;
        for (auto &c : search_word) ++search_space[c];

        std::unordered_map<char, int> input_map;
        for (auto &c : text) ++input_map[c];

        int max_search_word = INT_MAX;
        for (auto &[key, val] : search_space) {
            max_search_word = std::min(max_search_word, input_map[key] / val);
        }

        return max_search_word;
    }
};