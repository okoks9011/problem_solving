class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        points = sorted(set(startTime) | set(endTime))
        loc = {point: i for i, point in enumerate(points)}

        elems = []
        for s, e, p in zip(startTime, endTime, profit):
            elems.append((loc[s], loc[e], p))
        elems.sort(key=lambda x: x[1])

        dp = [0] * len(points)
        cur = 1
        for si, ei, p in elems:
            while cur <= ei:
                dp[cur] = max(dp[cur], dp[cur-1])
                cur += 1
            dp[ei] = max(dp[ei], dp[si] + p)
        return max(dp)
