class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_leaf = False


def insert(t, s):
    cur = t
    for c in s:
        if c not in cur.children:
            cur.children[c] = TrieNode()
        cur = cur.children[c]
    cur.is_leaf = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        n = len(board)
        assert n
        m = len(board[0])
        assert m

        root = TrieNode()
        for word in words:
            insert(root, word)

        visited = [[False] * m for _ in range(n)]
        result = set()
        def dfs(i, j, cur, sofar):
            if i < 0 or n <= i or j < 0 or m <= j:
                return
            if visited[i][j]:
                return
            if board[i][j] not in cur.children:
                return

            sofar.append(board[i][j])
            visited[i][j] = True

            child = cur.children[board[i][j]]
            if child.is_leaf:
                result.add(''.join(sofar))

            dfs(i-1, j, child, sofar)
            dfs(i, j+1, child, sofar)
            dfs(i+1, j, child, sofar)
            dfs(i, j-1, child, sofar)

            visited[i][j] = False
            sofar.pop()

        for i in range(n):
            for j in range(m):
                dfs(i, j, root, [])
        return list(result)
