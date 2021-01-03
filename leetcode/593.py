class Solution:
    def square_length(self, a: List[int], b: List[int]):
        x_diff = a[0] - b[0]
        y_diff = a[1] - b[1]
        return x_diff * x_diff + y_diff * y_diff

    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        if p1 == p2 == p3 == p4:
            return False

        pairs = [
            (p1, p2), (p1, p3), (p1, p4),
            (p2, p3), (p2, p4),
            (p3, p4),
        ]
        lens = [self.square_length(a, b) for a, b in pairs]
        lens.sort()

        if not (lens[0] == lens[1] == lens[2] == lens[3]):
            return False
        if not (lens[4] == lens[5]):
            return False
        return lens[0] * 2 == lens[4]
