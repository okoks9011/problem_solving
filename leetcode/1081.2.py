class Solution:
    def smallestSubsequence(self, s: str) -> str:
        loc = {}
        for i, c in enumerate(s):
            loc[c] = i

        stack = []
        for i, c in enumerate(s):
            if c in stack:
                continue

            while stack and stack[-1] > c and loc[stack[-1]] > i:
                stack.pop()
            stack.append(c)

        return ''.join(stack)
