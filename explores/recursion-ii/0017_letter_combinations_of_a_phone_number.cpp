#include <string>
#include <vector>

class Solution {
   private:
    int n{0};
    std::string currCombination{""};
    std::vector<std::string> res{};
    std::vector<std::string> keyCharMap{"abc", "def",  "ghi", "jkl",
                                        "mno", "pqrs", "tuv", "wxyz"};

    void solve(const std::string digits, int currPos) {
        // goal
        if (currCombination.size() == n) {
            res.push_back(currCombination);
            return;
        }
        std::string choices = keyCharMap[digits[currPos] - '2'];
        for (int i = 0; i < choices.size(); ++i) {
            currCombination += choices[i];
            solve(digits, currPos + 1);
            currCombination.pop_back();
        }
    }

   public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0) return res;

        n = digits.size();
        solve(digits, 0);
        return res;
    }
};