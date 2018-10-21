def mixture(x, y):
    if x == 0 and y == 0:
        return set()
    result = {x * y}
    if x != 0 and y % x == 0:
        result.add(y // x)
    if y != 0 and x % y == 0:
        result.add(x // y)
    return result


def triplets(A):
    d = {}
    result = 0
    for m in mixture(A[0], A[1]):
        if m not in d:
            d[m] = 0
        d[m] += 1
    if A[0] == 0 and A[1] == 0:
        result += len(A[2:])
    for c in range(2, len(A)):
        if A[c] in d:
            result += d[A[c]]
        for i in range(c):
            for m in mixture(A[i], A[c]):
                if m not in d:
                    d[m] = 0
                d[m] += 1
            if A[i] == 0 and A[c] == 0:
                result += len(A[c+1:])

    return result


def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        A = [int(s) for s in input().split()]
        print('Case #{}: {}'.format(i+1, triplets(A)))


main()
