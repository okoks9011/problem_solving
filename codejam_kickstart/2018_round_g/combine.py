from sortedcontainers import SortedDict
from collections import namedtuple


Interval = namedtuple("Interval", ["idx", "start", "dups"])


def pick_score(ki, ranks):
    i = 0
    while i < len(ranks) and ki >= ranks[i].idx:
        i += 1
    i -= 1
    r = ranks[i]
    if r.dups != 0:
        return r.start - (ki - r.idx) // r.dups
    else:
        return 0


def combine(n, q, x_iter, y_iter, z_iter):
    d = SortedDict()
    for _ in range(n):
        xi, yi = next(x_iter), next(y_iter)
        li = min(xi, yi) + 1
        ri = max(xi, yi) + 1
        d[ri] = d.get(ri, 0) + 1
        d[li-1] = d.get(li-1, 0) - 1
    for k in list(d.keys()):
        if d[k] == 0:
            d.pop(k, None)
    acc = 0
    for k in reversed(d):
        d[k] += acc
        acc = d[k]

    keys = list(reversed(d.keys()))
    ranks = []
    acc = 1
    for i, k in enumerate(keys):
        start = keys[i]
        dups = d[start]
        ranks.append(Interval(acc, start, dups))
        if i + 1 < len(keys):
            count = start - keys[i+1]
            acc += count * dups

    result = 0
    for i in range(1, q+1):
        zi = next(z_iter)
        ki = zi + 1
        result += i * pick_score(ki, ranks)
    return result


def gen_iter(v1, v2, a, b, c, m, n):
    if n >= 1:
        yield v1
    if n >= 2:
        yield v2
    for _ in range(n-2):
        vi = (a * v2 + b * v1 + c) % m
        yield vi
        v1, v2 = v2, vi


def main():
    t = int(input())
    for i in range(t):
        n, q = [int(s) for s in input().split()]
        x1, x2, a1, b1, c1, m1 = [int(s) for s in input().split()]
        y1, y2, a2, b2, c2, m2 = [int(s) for s in input().split()]
        z1, z2, a3, b3, c3, m3 = [int(s) for s in input().split()]
        x_iter = gen_iter(x1, x2, a1, b1, c1, m1, n)
        y_iter = gen_iter(y1, y2, a2, b2, c2, m2, n)
        z_iter = gen_iter(z1, z2, a3, b3, c3, m3, q)
        print('Case #{}: {}'.format(i+1, combine(n, q, x_iter, y_iter, z_iter)))


main()
