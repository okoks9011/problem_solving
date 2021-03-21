def count(x, y):
    type1 = max(0, min(x, y // 2) - 1)
    type2 = max(0, min(y, x // 2) - 1)
    return type1 + type2


def solve():
    r, c = [int(x) for x in input().strip().split()]
    grid = []
    for _ in range(r):
        grid.append([int(x) for x in input().strip().split()])

    upper = [[0] * c for _ in range(r)]
    for j in range(c):
        cur = 0
        for i in range(r):
            if grid[i][j] == 1:
                cur += 1
            else:
                cur = 0
            upper[i][j] = cur

    lower = [[0] * c for _ in range(r)]
    for j in range(c):
        cur = 0
        for i in reversed(range(r)):
            if grid[i][j] == 1:
                cur += 1
            else:
                cur = 0
            lower[i][j] = cur

    result = 0
    for i in range(r):
        cur = 0
        for j in range(c):
            if grid[i][j] == 1:
                cur += 1
            else:
                cur = 0
            if cur < 2:
                continue
            cell = count(cur, upper[i][j])
            cell += count(cur, lower[i][j])
            result += cell

        cur = 0
        for j in reversed(range(c)):
            if grid[i][j] == 1:
                cur += 1
            else:
                cur = 0
            if cur < 2:
                continue
            cell = count(cur, upper[i][j])
            cell += count(cur, lower[i][j])
            result += cell
    return result


t = int(input())
for i in range(t):
    r = solve()
    print(f'Case #{i+1}: {r}')
