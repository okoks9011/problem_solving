d = {}

def wild_match(p, t, pi, ti):
    global d
    if (pi, ti) in d:
        return d[(pi, ti)]
    result = False

    if pi < len(p) and ti < len(t):
        if p[pi] == '?' or p[pi] == t[ti]:
            result = wild_match(p, t, pi+1, ti+1)

    if pi == len(p):
        result = ti == len(t)
    elif p[pi] == '*':
        result = wild_match(p, t, pi+1, ti)
        if ti < len(t):
            result = result or wild_match(p, t, pi, ti+1)

    d[(pi, ti)] = result
    return result

def wild_matches(p, ts):
    global d
    result = []
    for t in ts:
        d.clear()
        if wild_match(p, t, 0, 0):
            result.append(t)
    result.sort()
    for r in result:
        print(r)

def main():
    c = int(input().strip())
    for _ in range(c):
        p = input().strip()
        tc = int(input().strip())
        ts = []
        for _ in range(tc):
            ts.append(input().strip())
        wild_matches(p, ts)

main()
