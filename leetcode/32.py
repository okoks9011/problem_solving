class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        result = 0
        for i, si in enumerate(s):
            if si == '(':
                stack.append(i)
            elif si == ')':
                stack.pop()
                if not stack:
                    stack.append(i)
                    continue

                result = max(result, i-stack[-1])
            else:
                assert False

        return result
