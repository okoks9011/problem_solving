def solve():
    n = int(input())
    a = [int(x) for x in input().strip().split()]

    result = 0
    for i in range(n-1):
        min_v = min(a[i:])
        min_idx = a[i:].index(min_v) + i
        result += min_idx - i + 1
        a[i:min_idx+1] = list(reversed(a[i:min_idx+1]))

    return result


t = int(input())
for i in range(t):
    r = solve()
    print(f'Case #{i+1}: {r}')
