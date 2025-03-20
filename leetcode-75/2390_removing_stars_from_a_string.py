class Solution:
    def removeStars(self, s: str) -> str:
        res = []
        for char in s:
            if char == "*" and len(res) > 0:
                res.pop()
            elif char != "*":
                res.append(char)
        return "".join(res)