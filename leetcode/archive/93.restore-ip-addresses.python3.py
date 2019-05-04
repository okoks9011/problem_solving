class Solution:
    def isValid(self, t):
        if not t:
            return False
        # to exclude 012 or 001 or 000
        return len(t) == 1 or (t[0] != '0' and 0 <= int(t) <= 255)

    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        for i in range(1, 4):
            first = s[:i]
            if not self.isValid(first):
                continue
            for j in range(1, 4):
                second = s[i:i+j]
                if not self.isValid(second):
                    continue
                for k in range(1, 4):
                    third = s[i+j:i+j+k]
                    fourth = s[i+j+k:]
                    if self.isValid(third) and self.isValid(fourth):
                        result.append('{}.{}.{}.{}'.format(
                            first, second, third, fourth))
        return result
