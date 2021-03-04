class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        assert n >= 1
        m = len(board[0])
        assert m >= 1
        l = len(word)

        visited = [[False] * m for _ in range(n)]
        ds = {(-1, 0), (0, 1), (1, 0), (0, -1)}

        def dfs(i, j, t):
            if l == t:
                return True
            if i < 0 or n <= i or j < 0 or m <= j:
                return False
            if visited[i][j]:
                return False
            if board[i][j] != word[t]:
                return False

            visited[i][j] = True
            for di, dj in ds:
                ci, cj = i + di, j + dj
                if dfs(ci, cj, t + 1):
                    return True
            visited[i][j] = False

            return False

        for i in range(n):
            for j in range(m):
                if dfs(i, j, 0):
                    return True
        return False
