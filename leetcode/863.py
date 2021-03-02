class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        ax1, ay1, ax2, ay2 = rec1
        bx1, by1, bx2, by2 = rec2

        def is_overlap(start1, end1, start2, end2):
            return start1 < end2 and start2 < end1

        def is_rec(x1, y1, x2, y2):
            return x1 < x2 and y1 < y2

        return (
            is_rec(ax1, ay1, ax2, ay2) and \
            is_rec(bx1, by1, bx2, by2) and \
            is_overlap(ax1, ax2, bx1, bx2) and \
            is_overlap(ay1, ay2, by1, by2)
        )
