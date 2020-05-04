#!/usr/bin/python3
import collections


def solve():
    n, d = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]

    cnt = collections.Counter(a)
    if d == 2:
        for k, v in cnt.items():
            if v >= 2:
                print('0', end='')
                return
    elif d == 3:
        for k, v in cnt.items():
            if v >= 3:
                print('0', end='')
                return
        for k, v in cnt.items():
            if v >= 2 and any(s > k for s in cnt):
                print('1', end='')
                return
            if v >= 1 and (k * 2) in cnt:
                print('1', end='')
                return
    print(d-1, end='')


t = int(input())

for i in range(t):
    print('Case #{}: '.format(i+1), end='')
    solve()
    print()
