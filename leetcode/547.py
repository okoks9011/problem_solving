class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, u):
        v = self.parent[u]
        if v == u:
            return u
        else:
            self.parent[u] = self.find(v)
            return self.parent[u]

    def union(self, u1, u2):
        v1, v2 = self.find(u1), self.find(u2)
        if v1 != v2:
            self.parent[v2] = v1

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)

        ds = DisjointSet(n)
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if isConnected[i][j]:
                    ds.union(i, j)

        return len({ds.find(i) for i in range(n)})
