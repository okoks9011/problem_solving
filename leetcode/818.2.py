from functools import lru_cache


class Solution:
    @lru_cache(None)
    def racecar(self, target: int) -> int:
        n = target.bit_length()
        if (2 ** n) - 1 == target:
            return n

        result = self.racecar((2 ** n) - 1 - target) + n + 1
        for i in range(n - 1):
            pos = 2 ** (n - 1) - 2 ** i
            result = min(result, self.racecar(target - pos) + n + i + 1)
        return result
