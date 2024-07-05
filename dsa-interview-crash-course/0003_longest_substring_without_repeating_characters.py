class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_l = 0
        idx = 0
        map = {}

        for i in range(len(s)):
            if s[i] in map.keys():
                idx = max(map[s[i]], idx)
            
            map[s[i]] = i + 1
            max_l = max(max_l, i - idx + 1)
        
        return max_l
        