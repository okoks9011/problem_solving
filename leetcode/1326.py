class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        assert n > 0
        inter = []
        for i, r in enumerate(ranges):
            inter.append([i - r, i + r])
        inter.sort()

        cnt = 0
        farthest = 0
        i = 0
        while farthest < n:
            next_reach = farthest
            while i <= n and inter[i][0] <= farthest:
                next_reach = max(next_reach, inter[i][1])
                i += 1
            if next_reach == farthest:
                return -1
            cnt += 1
            farthest = next_reach
        return cnt
