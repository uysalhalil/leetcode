from typing import List
from UnionFind import UnionFind


class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        uf = UnionFind(len(s))

        for pair in pairs:
            uf.union(pair[0], pair[1])

        map = {}
        for i in range(len(s)):
            province = uf.find(i)
            if (province in map):
                map[province].append([s[i], i])
            else:
                map[province] = [[s[i], i]]

        chars = ["" for i in range(len(s))]
        for key, value in map.items():
            values = [x[0] for x in value]
            indices = [x[1] for x in value]
            values.sort()
            for i in range(len(indices)):
                chars[indices[i]] = values[i]

        res = ''.join(chars)
        return res