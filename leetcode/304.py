class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        n = len(matrix)
        assert n > 0
        m = len(matrix[0])
        assert m > 0

        acc = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                acc[i][j] = acc[i][j-1] + acc[i-1][j] - acc[i-1][j-1] + matrix[i-1][j-1]
        self.acc = acc

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row2, col2 = row2 + 1, col2 + 1
        return self.acc[row2][col2] - self.acc[row2][col1] - self.acc[row1][col2] + self.acc[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
