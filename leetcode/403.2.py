import functools


class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        if stones[1] != 1:
            return False
        loc = {v: k for k, v in enumerate(stones)}

        @lru_cache(None)
        def dp(i, k):
            if i == n-1:
                return True
            for nk in range(k+1, k-2, -1):
                if nk <= 0:
                    continue
                next_stone = stones[i] + nk
                if next_stone not in loc:
                    continue
                if dp(loc[next_stone], nk):
                    return True
            return False
        return dp(1, 1)
