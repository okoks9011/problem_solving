import sys

INF = 9999
switch = [
    (0, 1, 2),  # 0
    (3, 7, 9, 11),
    (4, 10, 14, 15),
    (0, 4, 5, 6, 7),
    (6, 7, 8, 10, 12),
    (0, 2, 14, 15),  # 5
    (3, 14, 15),
    (4, 5, 7, 14, 15),
    (1, 2, 3, 4, 5),
    (3, 4, 5, 9, 13),
]

def clocksync(clocks, cur, cnt):
    if cur == 10:
        for c in clocks:
            if c % 12:
                return INF
        return cnt
    min_cnt = INF
    for i in range(4):
        min_cnt = min(min_cnt, clocksync(clocks, cur+1, cnt))
        # press switch
        for c in switch[cur]:
            clocks[c] += 3
        cnt += 1
    return min_cnt

def main():
    c = int(input())
    for _ in range(c):
        clocks = [int(s) for s in input().split()]
        cnt = clocksync(clocks, 0, 0)
        if cnt == INF:
            print('-1')
        else:
            print(cnt)

if sys.version_info.major == 2:
    input = raw_input
main()
