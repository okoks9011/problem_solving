class Solution:
    def longestAt(self, s, left, right):
        longest = 0, ''
        while 0 <= left and right < len(s) and s[left] == s[right]:
            longest = right - left + 1, s[left:right+1]
            left -= 1
            right += 1

        return longest

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        longest = 0, ''
        for i in range(len(s)):
            longest = max(longest, self.longestAt(s, i, i))
        for i in range(len(s)-1):
            longest = max(longest, self.longestAt(s, i, i+1))

        return longest[1]
