class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        min_elems = {min(row) for row in matrix}
        trans = list(zip(*matrix))
        max_elems = {max(col) for col in trans}

        return list(min_elems & max_elems)
