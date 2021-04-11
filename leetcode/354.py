from enum import Enum


class Color(Enum):
    white = 1
    gray = 2
    black = 3


def topological_sort(adjs):
    n = len(adjs)
    visited = [Color.white] * n
    result = []

    def dfs(i):
        if visited[i] == Color.black:
            return True
        if visited[i] == Color.gray:
            return False

        visited[i] = Color.gray

        for j in adjs[i]:
            if not dfs(j):
                return False

        visited[i] = Color.black
        result.append(i)

        return True

    for i in range(n):
        if not dfs(i):
            return []
    return result


class Solution:
    def maxEnvelopes(self, envels: List[List[int]]) -> int:
        assert envels
        n = len(envels)
        adjs = [[] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if envels[i][0] < envels[j][0] and envels[i][1] < envels[j][1]:
                    adjs[i].append(j)

        order = topological_sort(adjs)
        assert order

        dp = [-1] * n
        for i in order:
            cur_max = 0
            for j in adjs[i]:
                assert dp[j] != -1
                cur_max = max(cur_max, dp[j])
            dp[i] = cur_max + 1

        return max(dp)
