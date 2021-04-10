class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        result = 0
        heights.append(0)
        for right in range(len(heights)):
            while stack and heights[stack[-1]] >= heights[right]:
                cur = stack.pop()
                left = stack[-1] if stack else -1
                area = (right-left-1) * heights[cur]
                result = max(result, area)
            stack.append(right)
        return result
