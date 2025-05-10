#include <string>
using std::string;

class Solution {
   private:
    bool isLetter(const char &c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
    }

   public:
    string truncateSentence(string s, int k) {
        string res = "";
        int i = 0;
        int wordCount = 0;
        while (i < s.size()) {
            ++wordCount;
            while (i < s.size() && isLetter(s[i])) {
                res += s[i];
                ++i;
            }

            if (wordCount == k) {
                return res;
            }

            res += ' ';
            while (i < s.size() && !isLetter(s[i])) {
                ++i;
            }
        }

        return "";  // error handle
    }
};