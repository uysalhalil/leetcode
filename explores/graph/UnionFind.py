class UnionFind:
    def __init__(self, n: int):
        self.provinces = n
        self.hasCycle = False
        self.root = [x for x in range(n)]
        self.rank = [1 for x in range(n)]

    def find(self, x: int) -> int:
        if x == self.root[x]:
            return x

        self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x: int, y: int) -> None:
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            self.provinces -= 1
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX
            elif self.rank[rootY] > self.rank[rootX]:
                self.root[rootX] = rootY
            else:
                self.root[rootY] = rootX
                self.rank[rootX] += 1
        else:
            self.hasCycle = True

    def connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)