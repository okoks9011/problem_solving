class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        moves = [
            (-2, 1), (-1, 2),
            (1, 2), (2, 1),
            (2, -1), (1, -2),
            (-1, -2), (-2, -1),
        ]

        board = [[0.] * N for _ in range(N)]
        board[r][c] = 1.0
        for _ in range(K):
            next_board = [[0.] * N for _ in range(N)]
            for i in range(N):
                for j in range(N):
                    prob = board[i][j] / 8
                    for di, dj in moves:
                        ni = i + di
                        nj = j + dj
                        if ni < 0 or N <= ni or nj < 0 or N <= nj:
                            continue
                        next_board[ni][nj] += prob
            board = next_board

        return sum(sum(row) for row in board)
