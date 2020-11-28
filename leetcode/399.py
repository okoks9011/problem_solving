from collections import defaultdict


class Solution:
    def dfs(self, cur, t, adjs, visited):
        if cur == t:
            return 1.0

        visited.add(cur)
        for next_, v in adjs[cur]:
            if next_ in visited:
                continue
            cost = self.dfs(next_, t, adjs, visited)
            if cost >= 0:
                cost *= v
                return cost
        return -1.0

    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        adjs = defaultdict(list)
        for (x, y), v in zip(equations, values):
            if x == y:
                continue
            adjs[x].append((y, v))
            adjs[y].append((x, 1.0 / v))

        result = []
        for qx, qy in queries:
            if qx not in adjs or qy not in adjs:
                result.append(-1.0)
                continue
            visited = set()
            result.append(self.dfs(qx, qy, adjs, visited))
        return result
