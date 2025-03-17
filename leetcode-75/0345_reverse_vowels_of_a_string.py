class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels: set = set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"])
        i: int = 0
        j: int = len(s) - 1
        s = list(s)

        while i < j:
            if s[i] in vowels and s[j] in vowels:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1
            elif s[i] in vowels:
                j -= 1
            elif s[j] in vowels:
                i += 1
            else:
                i += 1
                j -= 1

        s = "".join(s)
        return s