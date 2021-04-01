from functools import lru_cache


@lru_cache(None)
def get_median(i, j, k):
    print(i, j, k)
    return int(input())


t, n, a = map(int, input().split())
for _ in range(t):
    chain = [1, 2]
    for new_number in range(3, n + 1):
        lc = len(chain)
        i, j = -2, -1

        while i + lc >= 0:
            median = get_median(chain[i], chain[j], new_number)
            if median == chain[j]:
                chain.insert(j + 1 + lc, new_number)
                break
            elif median == new_number:
                chain.insert(j + lc, new_number)
                break
            else:
                i, j = i - 1, j - 1
        if i + lc < 0:
            chain.insert(0, new_number)
    print(' '.join(map(str, chain)))  # 1 3 5 4 2
    ans = int(input())
    if ans != 1:
        break
    get_median.cache_clear()
