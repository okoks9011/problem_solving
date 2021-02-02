from collections import Counter


def get_score(x: int) -> int:
    c = Counter(str(bin(x))[1:])
    return c['0'] * 1 + c['1'] * 2


class Solution:
    def integerReplacement(self, n: int) -> int:
        if n == 1:
            return 0
        elif n % 2 == 0:
            return 1 + self.integerReplacement(n // 2)

        if get_score(n+1) > get_score(n-1):
            return 1 + self.integerReplacement(n - 1)
        else:
            return 1 + self.integerReplacement(n + 1)
