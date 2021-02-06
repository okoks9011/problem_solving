class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        dp = [n + 2 for _ in range(n + 1)]
        inters = [(max(0, i - r), min(n, i + r)) for i, r in enumerate(ranges)]

        dp[0] = 0
        for s, e in inters:
            for i in range(s, e + 1):
                dp[i] = min(dp[i], dp[s] + 1)
        return dp[n] if dp[n] < n + 2 else -1
