from typing import List


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # edges that go to judge is N-1
        in_degree = [0 for x in range(n)]
        out_degree = [0 for x in range(n)]
        for tr in trust:
            out_degree[tr[0] - 1] += 1
            in_degree[tr[1] - 1] += 1
        
        for i in range(n):
            if in_degree[i] == n - 1 and out_degree[i] == 0:
                return i + 1
        
        return -1
