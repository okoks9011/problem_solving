def solve():
    n = int(input())
    a = [int(x) for x in input().split()]

    time, cur = 1, 1
    for i in range(n-1):
        d = a[i] - a[i+1]
        while d > 0:
            d -= cur
            cur *= 2
            time += 1
    return time


t = int(input())
for _ in range(t):
    print(solve()-1)
