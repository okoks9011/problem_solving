import collections


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        cnt = collections.Counter(deck)
        numbers = list(cnt.values())
        x = numbers.pop()
        for a in numbers:
            x = gcd(x, a)
        return x >= 2
