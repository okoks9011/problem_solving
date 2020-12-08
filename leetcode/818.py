class Solution:
    def racecar(self, target: int) -> int:
        b = ''
        while target > 0:
            if target % 2 == 1:
                b += '1'
            else:
                b += '0'
            target //= 2
        b = '0' + ''.join(reversed(b))
        result = 0
        n = len(b)
        for i in range(1, n):
            if b[i-1] != b[i]:
                result += n - i + 1
        return result - 1
