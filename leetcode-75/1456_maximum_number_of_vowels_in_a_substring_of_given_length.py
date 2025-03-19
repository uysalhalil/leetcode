class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowelSet = set(["a", "e", "i", "o", "u"])
        nMaxVowels = 0
        nVovels = 0
        for i in range(k):
            if s[i] in vowelSet:
                nVovels += 1
            nMaxVowels = max(nMaxVowels, nVovels)

        for i in range(k, len(s)):
            if s[i - k] in vowelSet:
                nVovels -= 1
            if s[i] in vowelSet:
                nVovels += 1
            nMaxVowels = max(nMaxVowels, nVovels)

        return nMaxVowels
