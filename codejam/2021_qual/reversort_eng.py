def solve():
    n, c = (int(x) for x in input().strip().split())
    if c < n - 1 or n * (n+1) // 2 - 1 < c:
        return 'IMPOSSIBLE'

    remain = c - (n - 1)
    a = list(range(1, n+1))
    for i in range(2, n+1):
        cur_plus = min(i-1, remain)
        remain -= cur_plus

        cur_size = cur_plus + 1
        a[n-i:n-i+cur_size] = list(reversed(a[n-i:n-i+cur_size]))

    return ' '.join(str(x) for x in a)


t = int(input())
for i in range(t):
    r = solve()
    print(f'Case #{i+1}: {r}')
