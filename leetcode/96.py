class Solution:
    def numTrees(self, n: int) -> int:
        assert n < 20
        dp = [0] * 20
        dp[0], dp[1], dp[2] = 1, 1, 2

        for i in range(3, n + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i-1-j]

        return dp[n]
