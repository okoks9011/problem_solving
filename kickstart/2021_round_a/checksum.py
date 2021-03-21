def remove_solo(a):
    n = len(a)
    cur_sum = sum(sum(row) for row in a)
    while True:
        for i in range(n):
            ti, tj = -1, -1
            row_sum = 0
            for j in range(n):
                if a[i][j] == 0:
                    continue
                row_sum += 1
                ti, tj = i, j
            if row_sum == 1:
                a[ti][tj] = 0
        for j in range(n):
            ti, tj = -1, -1
            col_sum = 0
            for i in range(n):
                if a[i][j] == 0:
                    continue
                col_sum += 1
                ti, tj = i, j
            if col_sum == 1:
                a[ti][tj] = 0
        new_sum = sum(sum(row)for row in a)
        if cur_sum == new_sum:
            break
        cur_sum = new_sum

def solve():
    n = int(input().strip())

    a = []
    for _ in range(n):
        a.append([int(x) for x in input().strip().split()])
    b = []
    for _ in range(n):
        b.append([int(x) for x in input().strip().split()])
    row_xor = [int(x) for x in input().strip().split()]
    col_xor = [int(x) for x in input().strip().split()]

    for i in range(n):
        for j in range(n):
            if a[i][j] == -1:
                a[i][j] = 1
            else:
                a[i][j] = 0

    result = 0
    while True:
        remove_solo(a)
        cur_sum = sum(sum(row) for row in a)
        if cur_sum == 0:
            break

        cur_cost = float('inf')
        ti, tj = -1, -1
        for i in range(n):
            for j in range(n):
                if a[i][j] != 1:
                    continue
                if cur_cost > b[i][j]:
                    ti, tj = i, j
                    cur_cost = b[i][j]
        result += cur_cost
        a[ti][tj] = 0
    return result


t = int(input().strip())
for i in range(t):
    r = solve()
    print(f'Case #{i+1}: {r}')
