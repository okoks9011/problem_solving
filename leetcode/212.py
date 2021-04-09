class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        n = len(board)
        assert n
        m = len(board[0])
        assert m

        words_set = set(words)
        result = set()
        visited = [[False] * m for _ in range(n)]
        def dfs(i, j, cur):
            if len(cur) > 10:
                return
            if i < 0 or n <= i or j < 0 or m <= j:
                return
            if visited[i][j]:
                return
            visited[i][j] = True
            cur.append(board[i][j])
            cur_w = ''.join(cur)
            if cur_w in words_set:
                result.add(cur_w)
            dfs(i-1, j, cur)
            dfs(i, j+1, cur)
            dfs(i+1, j, cur)
            dfs(i, j-1, cur)
            cur.pop()
            visited[i][j] = False

        for i in range(n):
            for j in range(m):
                dfs(i, j, [])
        return list(result)
