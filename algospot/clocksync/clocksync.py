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

def press_switch(clocks, cur):
    for c in switch[cur]:
        clocks[c] += 3

def clocksync(clocks, cur, cnt):
    if cur == 10:
        if all(c % 12 == 0 for c in clocks):
            return cnt
        else:
            return float('inf')
    min_cnt = float('inf')
    for i in range(4):
        min_cnt = min(min_cnt, clocksync(clocks, cur+1, cnt))
        press_switch(clocks, cur)
        cnt += 1
    return min_cnt

def main():
    c = int(input())
    for _ in range(c):
        clocks = [int(s) for s in input().split()]
        cnt = clocksync(clocks, 0, 0)
        if cnt == float('inf'):
            print('-1')
        else:
            print(cnt)

main()
