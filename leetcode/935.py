class Solution:
    def knightDialer(self, n: int) -> int:
        jump = {
            0: [4, 6],
            1: [6, 8],
            2: [7, 9],
            3: [4, 8],
            4: [0, 3, 9],
            5: [],
            6: [1, 7, 0],
            7: [2, 6],
            8: [1, 3],
            9: [2, 4],
        }

        mod = 1_000_000_007
        dp = [1] * 10
        for _ in range(n - 1):
            new_dp = [0] * 10
            for u in range(10):
                for v in jump[u]:
                    new_dp[u] += dp[v]
                    new_dp[u] %= mod
            dp = new_dp
        return sum(dp) % mod
