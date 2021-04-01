def solve():
    line = input().strip().split()
    x, y = int(line[0]), int(line[1])
    s = line[2].replace('?', '')

    result = 0
    for i in range(1, len(s)):
        if s[i-1:i+1] == 'CJ':
            result += x
        elif s[i-1:i+1] == 'JC':
            result += y
    return result


t = int(input())
for i in range(t):
    r = solve()
    print(f'Case #{i+1}: {r}')
