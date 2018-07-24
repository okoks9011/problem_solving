class Solution:
    def __init__(self):
        self.d = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) <= 0:
            return []
        elif len(digits) == 1:
            return list(self.d[digits[0]])

        prev = self.letterCombinations(digits[:-1])
        result = []
        cur_digit = digits[-1]
        for c in self.d[cur_digit]:
            result.extend(s + c for s in prev)
        return result
