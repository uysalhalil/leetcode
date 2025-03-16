class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i = 0
        j = 0
        res = ""
        while i < len(word1) or j < len(word2):
            v1 = word1[i] if i < len(word1) else ""
            v2 = word2[j] if i < len(word2) else ""
            res += (v1 + v2)
            i += 1
            j += 1
        return res