class Solution:
    def numSquares(self, n: int) -> int:
        perfect = [i*i for i in range(1, 101)]
        dp = [-1] * (n + 1)
        for i in range(1, n+1):
            root_i = int(math.sqrt(i))
            if i == root_i * root_i:
                dp[i] = 1
                continue
            result_i = n
            for j in range(root_i):
                result_i = min(result_i, dp[i - perfect[j]] + 1)
            dp[i] = result_i
        return dp[n]
