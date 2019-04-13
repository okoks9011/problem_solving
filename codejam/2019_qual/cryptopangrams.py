#!/usr/bin/env python3
import math
import string


def find_keyfactor(c):
    for i in range(1, len(c)):
        if c[i-1] != c[i]:
            return (i, math.gcd(c[i-1], c[i]))
    assert False


def extract_factors(key, t):
    result = []
    cur = key
    for ti in t:
        cur = ti // cur
        result.append(cur)
    return result


def solve():
    n, l = [int(i) for i in input().split()]
    c = [int(i) for i in input().split()]

    idx, key = find_keyfactor(c)
    left_factors = reversed(extract_factors(key, reversed(c[:idx])))
    right_factors = extract_factors(key, c[idx:])

    f = list(left_factors)
    f.append(key)
    f += right_factors

    dic = {}
    for k, v in zip(sorted(set(f)), string.ascii_uppercase):
        dic[k] = v
    assert len(dic) == 26

    return ''.join(dic[fi] for fi in f)


t = int(input())

for i in range(t):
    s = solve()
    print('Case #{}: {}'.format(i+1, s))
