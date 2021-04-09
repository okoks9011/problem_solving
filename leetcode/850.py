class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        points_set = set()
        for _, y1, _, y2 in rectangles:
            points_set.add(y1)
            points_set.add(y2)
        points = sorted(points_set)
        loc = {v: i for i, v in enumerate(points)}
        n = len(points)

        min_x, max_x = [int(1e9)+1] * n, [-1] * n
        for x1, y1, x2, y2 in rectangles:
            for i in range(loc[y1], loc[y2]+1):
                min_x[i] = min(min_x[i], x1)
                max_x[i] = max(max_x[i], x2)

        MOD = int(1e9) + 7
        result = 0
        for i in range(1, n):
            left = max(min_x[i-1], min_x[i])
            right = min(max_x[i-1], max_x[i])
            if left >= right:
                continue
            result += (points[i]-points[i-1]) * (right - left)
            result %= MOD
        return result
