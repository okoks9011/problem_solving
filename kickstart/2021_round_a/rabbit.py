def solve():
    r, c = [int(x) for x in input().strip().split()]

    grid = []
    for _ in range(r):
        grid.append([int(x) for x in input().strip().split()])

    seq = []
    for i in range(r):
        for j in range(c):
            seq.append((grid[i][j], i, j))
    seq.sort(reverse=True)

    visited = [[False] * c for _ in range(r)]
    ds = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    def dfs(i, j, v):
        if i < 0 or r <= i or j < 0 or c <= j:
            return 0
        if visited[i][j] and grid[i][j] >= v:
            return 0
        if grid[i][j] > v:
            return 0

        cur_result = v - grid[i][j]
        grid[i][j] = v
        visited[i][j] = True
        for di, dj in ds:
            ni, nj = i + di, j + dj
            cur_result += dfs(ni, nj, v - 1)
        return cur_result

    result = 0
    for v, i, j in seq:
        result += dfs(i, j, v)
    return result


t = int(input())
for i in range(t):
    r = solve()
    print(f'Case #{i+1}: {r}')
