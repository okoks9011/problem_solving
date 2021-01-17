class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if s == '' and p == '':
            return True
        if p == '':
            return False

        if len(p) < 2 or p[1] != '*':
            if len(s) < 1:
                return False
            if p[0] == '.':
                return self.isMatch(s[1:], p[1:])
            else:
                return s[0] == p[0] and self.isMatch(s[1:], p[1:])
        else:
            for i in range(len(s)):
                if self.isMatch(s[i:], p[2:]):
                    return True
                if p[0] != '.' and s[i] != p[0]:
                    return False
            return self.isMatch('', p[2:])
