# -*- coding: utf-8 -*-

from collections import namedtuple

Move = namedtuple('Move', ['fx', 'fy', 'tx', 'ty'])

def make_them_even(cells):
    moves = []
    for i, row in enumerate(cells):
        for j in range(len(row) - 1):
            if row[j] % 2:
                row[j] -= 1
                row[j+1] += 1
                moves.append(Move(i+1, j+1, i+1, j+2))

    w = len(cells[0])
    for i in range(len(cells) - 1):
        if cells[i][-1] % 2:
            cells[i][-1] -= 1
            cells[i+1][-1] += 1
            moves.append(Move(i+1, w, i+2, w))
    return moves

def main():
    h, w = [int(s) for s in input().split()]
    cells = []
    for _ in range(h):
        row = [int(s) for s in input().split()]
        cells.append(row)
    moves = make_them_even(cells)
    print(len(moves))
    for move in moves:
        print(move.fx, move.fy, move.tx, move.ty)

main()
