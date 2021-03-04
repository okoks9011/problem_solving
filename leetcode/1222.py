class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        ds = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1), (0, 1),
            (1, -1), (1, 0), (1, 1),
        ]
        qs = set((qi, qj) for qi, qj in queens)

        result = []
        for di, dj in ds:
            ci, cj = king
            for _ in range(7):
                ci += di
                cj += dj
                if (ci, cj) in qs:
                    result.append([ci, cj])
                    break
        return result
