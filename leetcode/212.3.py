from collections import defaultdict


class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.word = None


def insert(t, s):
    cur = t
    for c in s:
        cur = cur.children[c]
    cur.word = s


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        n = len(board)
        assert n
        m = len(board[0])
        assert m

        root = TrieNode()
        for word in words:
            insert(root, word)

        result = []
        def dfs(i, j, cur):
            if i < 0 or n <= i or j < 0 or m <= j:
                return
            if board[i][j] not in cur.children:
                return

            child = cur.children[board[i][j]]
            if child.word is not None:
                result.append(child.word)
                child.word = None

            tmp = board[i][j]
            board[i][j] = '#'

            dfs(i-1, j, child)
            dfs(i, j+1, child)
            dfs(i+1, j, child)
            dfs(i, j-1, child)

            board[i][j] = tmp

        for i in range(n):
            for j in range(m):
                dfs(i, j, root)
        return list(result)
