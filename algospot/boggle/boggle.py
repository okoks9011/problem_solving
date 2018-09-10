from collections import namedtuple

Game = namedtuple('Game', ['board', 'words'])
delta = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

def boggle_check(board, word, remain, sofar, i, j):
    if i < 0 or i >= 5 or j < 0 or j >= 5:
        return False
    sofar.append(board[i][j])
    if remain == 1:
        if all(s == w for s, w in zip(sofar, word)):
            return True
    else:
        for di, dj in delta:
            if boggle_check(board, word, remain-1, sofar, i+di, j+dj):
                return True
    sofar.pop()
    return False

def boggle_word(board, word):
    for i in range(5):
        for j in range(5):
            if boggle_check(board, word, len(word), [], i, j):
                return True
    return False

def boggle(game):
    board, words = game
    for word in words:
        if boggle_word(board, word):
            print(word + ' Yes')
        else:
            print(word + ' No')

def main():
    n = int(input())
    cases = []
    for _ in range(n):
        board = []
        for _ in range(5):
            board.append(list(input()))
        k = int(input())
        words = []
        for _ in range(k):
            words.append(input())
        cases.append(Game(board, words))

    for case in cases:
        boggle(case)

main()
