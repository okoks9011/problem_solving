class FenwickTree:
    def __init__(self, n):
        self.buf = [0] * (n + 1)

    def add(self, x, v):
        x += 1
        while x < len(self.buf):
            self.buf[x] += v
            x += x & -x

    def get(self, x):
        x += 1
        result = 0
        while x > 0:
            result += self.buf[x]
            x &= x - 1
        return result


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return []

        pad = abs(min(nums)) + 1
        ft = FenwickTree(pad + max(nums) + 1)
        results = []
        for ni in reversed(nums):
            x = ni + pad
            results.append(ft.get(x-1))
            ft.add(x, 1)
        results.reverse()
        return results
