class Solution:
    def countPalindromeAt(self, left, right):
        counts = 0
        while (left >= 0 and
               right < len(self.s) and
               self.s[left] == self.s[right]):
            counts += 1
            left -= 1
            right += 1

        return counts

    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.s = s
        total = 0

        # odd length palindromes
        for i in range(len(s)):
            total += self.countPalindromeAt(i, i)

        # even length palindromes
        for i in range(len(s)-1):
            total += self.countPalindromeAt(i, i+1)

        return total
