class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        if not b:
            return 0

        x = len(b) // len(a)
        if b in x * a:
            return x
        if b in (x+1) * a:
            return x+1
        if b in (x+2) * a:
            return x+2
        return -1
