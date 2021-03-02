class Solution:
    def smallestSubsequence(self, s: str) -> str:
        if not s:
            return ''

        n = len(s)
        total = set(s)
        cur = set()
        i = n-1
        while i >= 0:
            cur.add(s[i])
            if len(cur) == len(total):
                break
            i -= 1
        assert i >= 0

        loc = {}
        while i >= 0:
            loc[s[i]] = i
            i -= 1

        selected = min(loc.keys())
        remain = s[loc[selected]+1:]
        filtered = ''.join(c for c in remain if c != selected)

        return selected + self.smallestSubsequence(filtered)
