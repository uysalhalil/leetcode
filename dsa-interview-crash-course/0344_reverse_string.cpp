#include <iostream>
#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            std::swap(s[l], s[r]);
            ++l;
            --r;
        }
    }
};