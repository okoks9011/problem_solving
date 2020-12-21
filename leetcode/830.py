class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        start = 0
        cur_char = s[0]
        intervals = []
        for i, c in enumerate(s):
            if c != cur_char:
                if i - start >= 3:
                    intervals.append((start, i - 1))
                start = i
                cur_char = c
        if len(s) - start >= 3:
            intervals.append((start, len(s) - 1))

        return intervals
