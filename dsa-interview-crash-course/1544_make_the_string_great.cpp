#include <stack>
#include <string>

class Solution {
   public:
    std::string makeGood(std::string s) {
        std::stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < s.size(); ++i) {
            if (st.empty()) {
                st.push(s[i]);
            } else if (toupper(s[i]) == toupper(st.top())) {
                if (s[i] == st.top()) {
                    st.push(s[i]);
                } else {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }

        std::string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};