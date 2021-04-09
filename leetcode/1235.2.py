import bisect


class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        slots = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        dp = [[0, 0]]
        for s, e, p in slots:
            si = bisect.bisect_right(dp, [s, float('inf')]) - 1
            cur_profit = dp[si][1] + p
            if dp[-1][1] < cur_profit:
                dp.append([e, cur_profit])
        return dp[-1][1]
