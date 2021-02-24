class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        m = len(grid)
        assert 0 < m
        n = len(grid[0])
        assert 0 < n

        for i, j in hits:
            grid[i][j] -= 1

        ds = [
            (-1, 0), (0, 1), (1, 0), (0, -1),
        ]
        def dfs(i, j):
            if i < 0 or m <= i or j < 0 or n <= j:
                return 0
            if grid[i][j] != 1:
                return 0
            grid[i][j] = 2
            result = 1
            for di, dj in ds:
                ni, nj = i + di, j + dj
                result += dfs(ni, nj)
            return result

        for j in range(n):
            dfs(0, j)

        def stable_check(i, j):
            if i == 0:
                return True
            for di, dj in ds:
                ni, nj = i + di, j + dj
                if ni < 0 or m <= ni or nj < 0 or n <= nj:
                    continue
                if grid[ni][nj] == 2:
                    return True
            return False

        result = []
        for i, j in reversed(hits):
            grid[i][j] += 1
            if stable_check(i, j) and grid[i][j] == 1:
                result.append(dfs(i, j) - 1)
            else:
                result.append(0)
        result.reverse()
        return result
