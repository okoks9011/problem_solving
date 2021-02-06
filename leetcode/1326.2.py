class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        dp = [n + 2 for _ in range(n + 1)]
        inters = [(max(0, i - r), min(n, i + r)) for i, r in enumerate(ranges)]

        dp[0] = 0
        for i in range(1, n + 1):
            for inter in inters:
                if inter[0] <= i <= inter[1]:
                    dp[i] = min(dp[i], dp[inter[0]] + 1)
        return dp[n] if dp[n] < n + 2 else -1
