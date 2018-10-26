from collections import defaultdict


def triplets(A):
    n = len(A)
    A.sort()
    i = 0
    while i < len(A) and A[i] == 0:
        i += 1
    zeros = i
    A = A[i:]

    d = defaultdict(int)
    acc = 0
    for i in reversed(range(len(A))):
        for j in reversed(range(i)):
            if A[i] * A[j] in d:
                acc += d[A[i] * A[j]]
        d[A[i]] += 1

    if zeros >= 3:
        acc += (zeros * (zeros - 1) * (zeros - 2)) // 6
    if zeros >= 2:
        acc += ((zeros * (zeros - 1)) // 2) * (n - zeros)
    return acc


def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        A = [int(s) for s in input().split()]
        print('Case #{}: {}'.format(i+1, triplets(A)))


main()
