import itertools


class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        result = [0] * (len(num1) + len(num2))
        for i, n1 in enumerate(map(int, num1)):
            for j, n2 in enumerate(map(int, num2)):
                result[i + j + 1] += n1 * n2

        for i in range(len(result) - 1, 0, -1):
            result[i - 1] += result[i] // 10
            result[i] %= 10

        nz_result = itertools.dropwhile(lambda x: x == 0, result)
        return ''.join(map(str, nz_result)) or '0'
