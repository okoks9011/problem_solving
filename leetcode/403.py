import bisect
import functools


class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        if stones[1] != 1:
            return False

        @lru_cache(None)
        def dp(i, k):
            if i == n-1:
                return True
            for nk in range(k+1, k-2, -1):
                if nk <= 0:
                    continue
                next_stone = stones[i] + nk
                ni = bisect.bisect_left(stones, next_stone)
                if ni < n and stones[ni] == next_stone:
                    if dp(ni, nk):
                        return True
            return False
        return dp(1, 1)
