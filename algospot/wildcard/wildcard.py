d = {}

def wild_match(p, t, pi, ti):
    global d
    if (pi, ti) in d:
        return d[(pi, ti)]

    result = False
    if pi >= len(p) and ti >= len(t):
        result = True
    elif pi >= len(p):
        pass
    elif ti >= len(t):
        if p[pi] == '*':
            result = wild_match(p, t, pi+1, ti)
    else:
        if p[pi] == '*':
            result = (wild_match(p, t, pi+1, ti) or
                      wild_match(p, t, pi, ti+1))
        elif p[pi] == '?':
            result = wild_match(p, t, pi+1, ti+1)
        else:
            result = ((p[pi] == t[ti]) and
                      wild_match(p, t, pi+1, ti+1))
    d[(pi, ti)] = result
    return result

def wild_matches(p, ts):
    global d
    for t in ts:
        d.clear()
        if wild_match(p, t, 0, 0):
            print(t)

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
