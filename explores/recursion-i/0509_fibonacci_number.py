class Solution:
    def rec(self, n: int, memo: dict) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1

        if n in memo:
            return memo[n]

        memo[n] = self.rec(n-1, memo) + self.rec(n-2, memo)
        return memo[n]

    def fib(self, n: int) -> int:
        return self.rec(n, {})