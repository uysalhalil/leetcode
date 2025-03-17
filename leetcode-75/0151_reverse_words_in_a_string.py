class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        s = s.split(" ")
        s.reverse()
        s = [word for word in s if word != ""]
        s = " ".join(s)
        return s