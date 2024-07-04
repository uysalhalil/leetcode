#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> findWinners(
        std::vector<std::vector<int>> &matches) {
        std::unordered_set<int> players;
        std::unordered_map<int, int> losses;

        for (auto &match : matches) {
            for (auto &player : match) {
                players.insert(player);
            }
            ++losses[match[1]];
        }

        std::vector<std::vector<int>> res(2, std::vector<int>(0, 0));
        for (auto &player : players) {
            if (losses.find(player) == losses.end()) {
                res[0].push_back(player);
            } else if (losses[player] == 1) {
                res[1].push_back(player);
            }
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};