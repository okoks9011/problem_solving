import math


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        pool = list(range(1, n+1))
        x = math.factorial(n)

        k -= 1
        result = ''
        for i in range(n, 0, -1):
            x //= i
            pos, k = divmod(k, x)
            result += str(pool[pos])
            pool.pop(pos)
        return result
