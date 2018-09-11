def picnic_pick(chosen, remain, candi):
    if not candi:
        return 0
    c1, c2 = candi[0]
    if c1 in chosen or c2 in chosen:
        return 0
    if remain == 1:
        return 1

    chosen.add(c1)
    chosen.add(c2)
    result = 0
    for i in range(1, len(candi)):
        result += picnic_pick(chosen, remain-1, candi[i:])
    chosen.remove(c2)
    chosen.remove(c1)
    return result

def picnic(n, m, pairs):
    result = 0
    for i in range(len(pairs)):
        result += picnic_pick(set(), n//2, pairs[i:])
    return result

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
