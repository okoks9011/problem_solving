def solve():
    n, k = [int(x) for x in input().strip().split()]
    s = input().strip()

    good = 0
    for i in range(n // 2):
        if s[i] != s[n-1-i]:
            good += 1
    return abs(k - good)


t = int(input())
for i in range(t):
    r = solve()
    print(f'Case #{i+1}: {r}')
