class Solution:
    def appendSeq(self, seq, r, c):
        if 0 <= r < self.R and 0 <= c < self.C:
            seq.append([r, c])

    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        self.R, self.C = R, C
        seq = [[r0, c0]]
        size = 1
        while len(seq) < R * C:
            for _ in range(size):
                c0 += 1
                self.appendSeq(seq, r0, c0)
            for _ in range(size):
                r0 += 1
                self.appendSeq(seq, r0, c0)
            for _ in range(size+1):
                c0 -= 1
                self.appendSeq(seq, r0, c0)
            for _ in range(size+1):
                r0 -= 1
                self.appendSeq(seq, r0, c0)
            size += 2
        return seq
