class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        n = len(grid)
        assert n > 0
        m = len(grid[0])
        assert m > 0

        dp = [[0] * m for _ in range(n)]
        if grid[0][0] != 1:
            dp[0][0] = 1
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    continue
                dp[i][j] += dp[i-1][j] if i > 0 else 0
                dp[i][j] += dp[i][j-1] if j > 0 else 0
        return dp[-1][-1]
