import sys

d = {}

def jlis_rec(A, B, ai, bi):
    global d
    if (ai, bi) in d:
        return d[(ai, bi)]

    result = 2
    av = A[ai] if ai != -1 else float('-inf')
    bv = B[bi] if bi != -1 else float('-inf')
    last = max(av, bv)
    for ak in range(ai+1, len(A)):
        if A[ak] > last:
            result = max(result, jlis_rec(A, B, ak, bi)+1)
    for bk in range(bi+1, len(B)):
        if B[bk] > last:
            result = max(result, jlis_rec(A, B, ai, bk)+1)

    d[(ai, bi)] = result
    return result

def jlis(A, B):
    global d
    print(jlis_rec(A, B, -1, -1)-2)
    d.clear()

def main():
    c = int(input().strip())
    for _ in range(c):
        n, m = [int(s) for s in input().split()]
        A = [int(s) for s in input().split()]
        B = [int(s) for s in input().split()]
        jlis(A, B)

if sys.version_info.major == 2:
    input = raw_input
main()
