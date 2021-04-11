def get_block(i, j):
    return 3 * (i//3) + (j//3)

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        blocks = [set() for _ in range(9)]
        empty = 0
        for i in range(9):
            for j in range(9):
                aij = board[i][j]
                if not aij.isdigit():
                    empty += 1
                    continue
                x = int(aij)
                rows[i].add(x)
                cols[j].add(x)
                blocks[get_block(i, j)].add(x)

        while empty > 0:
            new_empty = empty
            for i in range(9):
                for j in range(9):
                    candi = set(range(9))
                    candi -= rows[i]
                    candi -= cols[i]
                    candi -= blocks[get_block(i, j)]
                    if len(candi) > 1:
                        continue

                    v = candi.pop()
                    rows[i].add(v)
                    cols[j].add(v)
                    blocks[get_block(i, j)].add(v)
                    board[i][j] = str(v)
                    new_empty -= 1
            if new_empty == empty:
                assert False

            empty = new_empty
