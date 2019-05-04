class Solution:
    def projectionArea(self, grid):
        xy = 0
        for ys in grid:
            xy += sum(1 for y in ys if y != 0)

        zx = sum(max(ys) for ys in grid)

        yz = sum(max(xs) for xs in zip(*grid))

        return xy + zx + yz
