import sys
import heapq


input = sys.stdin.readline


def solve():
    r, c = map(int, input().strip().split())
    grid = []
    for _ in range(r):
        grid.append([int(x) for x in input().strip().split()])

    max_pq = []
    for i in range(r):
        for j in range(c):
            if grid[i][j] == 0:
                continue
            heapq.heappush(max_pq, (-grid[i][j], i, j))

    ds = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    result = 0
    while max_pq:
        v, i, j = heapq.heappop(max_pq)
        v = -v
        if grid[i][j] != v:
            continue
        for di, dj in ds:
            ni, nj = i + di, j + dj
            if ni < 0 or r <= ni or nj < 0 or c <= nj:
                continue
            if grid[ni][nj] >= v - 1:
                continue
            result += v - 1 - grid[ni][nj]
            grid[ni][nj] = v - 1
            heapq.heappush(max_pq, (-(v - 1), ni, nj))
    return result


t = int(input().strip())
for i in range(t):
    r = solve()
    print(f'Case #{i+1}: {r}')
