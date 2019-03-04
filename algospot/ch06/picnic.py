def picnic_pick(chosen, remain, candi):
    if remain == 0:
        return 1
    if not candi:
        return 0
    result = 0
    for i in range(len(candi)):
        c1, c2 = candi[i]
        if (c1 not in chosen) and (c2 not in chosen):
            chosen.add(c1)
            chosen.add(c2)
            result += picnic_pick(chosen, remain-1, candi[i+1:])
            chosen.remove(c1)
            chosen.remove(c2)
    return result

def picnic(n, m, pairs):
    return picnic_pick(set(), n//2, pairs)

def main():
    c = int(input())
    cases = []
    for _ in range(c):
        n, m = [int(s) for s in input().split()]
        raw_pairs = [int(s) for s in input().split()]
        pairs = []
        for i in range(len(raw_pairs)//2):
            pairs.append((raw_pairs[2*i], raw_pairs[2*i+1]))
        print(picnic(n, m, pairs))

main()
