from collections import defaultdict
import math


class Solution:
    def get_length_square(self, p1, p2):
        diff_x, diff_y = p1[0] - p2[0], p1[1] - p2[1]
        return diff_x * diff_x + diff_y * diff_y

    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        n = len(points)
        if n < 4:
            return 0

        point_groups = defaultdict(list)
        for i in range(n):
            pi = points[i]
            for j in range(i+1, n):
                pj = points[j]
                mid_x, mid_y = (pi[0] + pj[0]) / 2, (pi[1] + pj[1]) / 2
                len_square = self.get_length_square(pi, pj)
                point_groups[(mid_x, mid_y, len_square)].append((pi, pj))

        result = float('inf')
        for group in point_groups.values():
            g = len(group)
            if g <= 1:
                continue
            for i in range(g):
                p1, _ = group[i]
                for j in range(i+1, g):
                    p3, p4 = group[j]
                    area = math.sqrt(self.get_length_square(p1, p3)) * math.sqrt(self.get_length_square(p1, p4))
                    result = min(result, area)

        if result < float('inf'):
            return result
        else:
            return 0
