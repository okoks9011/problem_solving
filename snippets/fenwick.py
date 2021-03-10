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
