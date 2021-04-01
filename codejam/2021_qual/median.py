import sys


total_query = 0


def ask(a, b, c):
    global total_query
    print(a, b, c)
    r = int(input().strip())
    total_query += 1

    if r == -1:
        sys.exit(0)
    return r


def solve(n):
    m = ask(1, 2, 3)
    arr = [1, 2, 3]
    arr.remove(m)
    arr.insert(1, m)

    for i in range(4, n+1):
        left, right = 0, len(arr)-1
        while left <= right:
            if left < right:
                r = ask(arr[left], i, arr[right])
            elif left == right:
                r = ask(arr[left], i, arr[left+1])
            else:
                assert False

            if r == arr[left]:
                arr.insert(left, i)
                break
            elif r == arr[right]:
                arr.insert(right+1, i)
                break
            elif r == i:
                if right - left <= 1:
                    arr.insert(left+1, i)
                    break
                left, right = left+1, right-1
            else:
                assert False
        assert left <= right

    print(' '.join(str(x) for x in arr))
    r = int(input().strip())
    if r != 1:
        sys.exit(0)


t, n, q = (int(x) for x in input().strip().split())
for _ in range(t):
    solve(n)
