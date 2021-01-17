class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        n = len(points)
        points_set = set()
        for x, y in points:
            points_set.add((x, y))

        MAX_V = 40000 ** 2 + 1
        result = MAX_V
        for i in range(n):
            xi, yi = points[i]
            for j in range(i+1, n):
                xj, yj = points[j]
                if xi == xj or yi == yj:
                    continue
                if (xi, yj) not in points_set or (xj, yi) not in points_set:
                    continue
                result = min(result, abs(xi - xj) * abs(yi - yj))

        if result == MAX_V:
            return 0
        else:
            return result
