#include <string>
#include <vector>

class Solution {
   public:
    bool checkIfPangram(std::string sentence) {
        std::vector<bool> alpha(26, false);
        int counter = 26;
        for (auto&& c : sentence) {
            if (!alpha[c - 'a']) --counter;
            alpha[c - 'a'] = true;
        }
        return !counter;
    }
};