input()
ns = [int(x) for x in input().split()]

loc = {0: -1}
start = -1
acc = 0
result = 0
for i, v in enumerate(ns):
    acc += v
    if acc in loc:
        start = max(start, loc[acc] + 1)
    result += i - start
    loc[acc] = i
print(result)
