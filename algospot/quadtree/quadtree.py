def reverse(qt_iter):
    c = next(qt_iter)
    if c == 'b' or c == 'w':
        return c

    sub = []
    for _ in range(4):
        sub.append(reverse(qt_iter))
    return ''.join(['x', sub[2], sub[3], sub[0], sub[1]])

def main():
    c = int(input().strip())
    for _ in range(c):
        qt_raw = input().strip()
        print(reverse(iter(qt_raw)))

main()
