from enum import Enum


class Color(Enum):
    white = 0
    gray = 1
    black = 2


class Solution:
    def findOrder(self, n: int, pre_reqs: List[List[int]]) -> List[int]:
        adjs = [[] for _ in range(n)]
        for u, v in pre_reqs:
            adjs[v].append(u)

        visited = [Color.white] * n
        result = []
        def dfs(cur):
            if visited[cur] == Color.gray:
                return False
            if visited[cur] == Color.black:
                return True

            visited[cur] = Color.gray
            for adj in adjs[cur]:
                if not dfs(adj):
                    return False
            visited[cur] = Color.black
            result.append(cur)
            return True

        for i in range(n):
            if not dfs(i):
                return []

        result.reverse()
        return result
