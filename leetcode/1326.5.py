class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        dp = [n + 2 for _ in range(n + 1)]
        inters = [(max(0, i - r), min(n, i + r)) for i, r in enumerate(ranges)]

        dp[0] = 0
        for s, e in sorted(inters, key=lambda x: x[1]):
            if s == e:
                continue
            dp[e] = min(dp[e], min(dp[i] for i in range(s, e)) + 1)
        return dp[n] if dp[n] < n + 2 else -1
