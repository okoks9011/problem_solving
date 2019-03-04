def count_pairing(taken, pairs, n):
    if len(taken) == n:
        return 1
    i = next(c for c in range(n) if c not in taken)
    result = 0
    for j in range(i+1, n):
        if j not in taken and (i, j) in pairs:
            taken.add(i)
            taken.add(j)
            result += count_pairing(taken, pairs, n)
            taken.remove(j)
            taken.remove(i)
    return result

def picnic(n, m, pairs):
    new_pairs = set()
    for i, j in pairs:
        new_pairs.add((i, j))
        new_pairs.add((j, i))
    return count_pairing(set(), new_pairs, n)

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
