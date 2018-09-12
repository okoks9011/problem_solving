blocks = [
    [(0, 0), (0, 1), (1, 0)],
    [(0, 0), (1, -1), (1, 0)],
    [(0, 0), (0, 1), (1, 1)],
    [(0, 0), (1, 0), (1, 1)],
]

def place_block(board, i, j, block, w):
    for di, dj in block:
        board[di+i][dj+j] = w

def is_placeable(board, i, j, block):
    h, w = len(board), len(board[0])
    for di, dj in block:
        ni, nj = di+i, dj+j
        if 0 > ni or ni >= h or 0 > nj or nj >= w:
            return False
        if board[ni][nj] != '.':
            return False
    return True

def find_first_white(board):
    for i, row in enumerate(board):
        for j, w in enumerate(row):
            if w == '.':
                return i, j
    return None, None

def count_boardcover(board, w_cnt):
    if w_cnt == 0:
        return 1
    h, w = len(board), len(board[0])
    i, j = find_first_white(board)
    result = 0
    for block in blocks:
        if is_placeable(board, i, j, block):
            place_block(board, i, j, block, '#')
            result += count_boardcover(board, w_cnt-3)
            place_block(board, i, j, block, '.')
    return result

def boardcover(board, h, w):
    w_cnt = 0
    for row in board:
        w_cnt += sum(1 for w in row if w == '.')
    if w_cnt % 3:
        return 0
    return count_boardcover(board, w_cnt)

def main():
    c = int(input())
    for _ in range(c):
        h, w = [int(s) for s in input().split()]
        board = []
        for _ in range(h):
            row = [w for w in input().strip()]
            board.append(row)
        print(boardcover(board, h, w))

main()
