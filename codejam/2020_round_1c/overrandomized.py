#!/usr/bin/python3
import collections


def solve():
    u = int(input())
    buf = []
    for _ in range(10000):
        buf.append((input().split())[-1])

    cnt = collections.Counter()
    total = set()
    for word in buf:
        total |= set(word)
        if len(word) != u:
            continue
        cnt[word[0]] += 1

    total -= set(cnt.keys())
    assert(len(total) == 1)

    result = ''.join(sorted(cnt, key=lambda x: cnt[x], reverse=True))
    result = total.pop() + result
    print(result, end='')


t = int(input())
for i in range(t):
    print('Case #{}:'.format(i+1), end=' ')
    solve()
    print()
