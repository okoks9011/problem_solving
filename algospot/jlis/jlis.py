d = {}

def jlis_rec(A, B, ai, bi):
    global d
    if (ai, bi) in d:
        return d[(ai, bi)]

    result = 1
    last = max(A[ai], B[bi])
    print('ai, bi: {}, {}'.format(ai, bi))
    print(last)
    for ak in range(ai+1, len(A)):
        if A[ak] >= last:
            result = max(result, jlis_rec(A, B, ak, bi))
    for bk in range(bi+1, len(B)):
        if B[bk] >= last:
            result = max(result, jlis_rec(A, B, ai, bk))
    if A[ai] != B[bi]:
        result += 1

    d[(ai, bi)] = result
    return result

def jlis(A, B):
    global d
    result = 0
    for ai in range(len(A)):
        result = max(result, jlis_rec(A, B, ai, 0))
    for bi in range(len(B)):
        result = max(result, jlis_rec(A, B, 0, bi))
    print(result)
    print(d)
    d.clear()

def main():
    c = int(input().strip())
    for _ in range(c):
        n, m = [int(s) for s in input().split()]
        A = [int(s) for s in input().split()]
        B = [int(s) for s in input().split()]
        jlis(A, B)

main()
