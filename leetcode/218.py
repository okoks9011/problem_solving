class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        points_set = set()
        for left, right, _ in buildings:
            points_set.add(left)
            points_set.add(right)
        points = sorted(points_set)
        loc = {v: i for i, v in enumerate(points)}
        max_heights = [0] * len(points)

        for left, right, height in buildings:
            li, ri = loc[left], loc[right]
            for i in range(li, ri):
                max_heights[i] = max(max_heights[i], height)

        result = []
        for i in range(len(points)):
            xi, yi = points[i], max_heights[i]
            if not result or result[-1][1] != yi:
                result.append([xi, yi])
        return result
