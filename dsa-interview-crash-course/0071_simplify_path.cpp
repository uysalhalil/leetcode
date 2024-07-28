#include <stack>
#include <string>

class Solution {
   public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> st;
        int i = 1;
        // push folder names into a stack
        while (i < path.size()) {
            std::string fname = "";
            while (i < path.size() && path[i] != '/') {
                fname += path[i];
                ++i;
            }
            while (path[i] == '/') {
                ++i;
            }
            st.push(fname);
        }
        // clean up the stack to remove the pops and current folders.
        std::stack<std::string> folders;
        int nPop = 0;
        while (!st.empty()) {
            std::string fname = st.top();
            st.pop();
            if (fname.compare(".") == 0 || fname.compare("") == 0) {
                // DO NOTHING
            } else if (fname.compare("..") == 0) {
                ++nPop;
            } else if (nPop == 0) {
                folders.push(fname);
            } else {
                --nPop;
            }
        }
        // combine the simplified path together.
        std::string simplified_path = "/";
        while (!folders.empty()) {
            simplified_path += folders.top() + "/";
            folders.pop();
        }

        if (simplified_path.length() > 1) {
            simplified_path.pop_back();
        }
        return simplified_path;
    }
};