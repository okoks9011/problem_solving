class ProductOfNumbers:
    def __init__(self):
        self.buf = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.buf = [1]
        else:
            self.buf.append(self.buf[-1] * num)

    def getProduct(self, k: int) -> int:
        if k >= len(self.buf):
            return 0
        return self.buf[-1] // self.buf[-k-1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
