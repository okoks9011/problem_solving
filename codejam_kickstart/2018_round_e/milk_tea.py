# -*- coding: utf-8 -*-

def find_min_complain(prefers):
    min_complain = []
    weight = []

    for prefer in zip(*prefers):
        prefer_one = prefer.count(1)
        prefer_zero = prefer.count(0)
        if prefer_one > prefer_zero:
            min_complain.append(1)
        else:
            min_complain.append(0)
        weight.append((prefer_one, prefer_zero))
    return tuple(min_complain), weight


def cal_complain(comb, weight):
    complain = 0
    for c, w in zip(comb, weight):
        complain += w[c]
    return complain


def find_all_children(comb):
    children = []
    list_comb = list(comb)
    for i in range(len(list_comb)):
        list_comb[i] = 0 if list_comb[i] else 1
        children.append(tuple(list_comb))
        list_comb[i] = 0 if list_comb[i] else 1
    return children


def allowed_min_complain(prefers, forbids):
    history = set()
    cur, weight = find_min_complain(prefers)
    while cur in forbids:
        history.add(cur)
        min_v = float('inf')
        for h in history:
            for child in find_all_children(h):
                if child in history:
                    continue
                child_v = cal_complain(child, weight)
                if min_v > child_v:
                    cur = child
                    min_v = child_v

    return cal_complain(cur, weight)


def main():
    cases = []
    file_name = 'test_milk_tea'
    infile_name = file_name + '.in'
    outfile_name = file_name + '.out'
    with open(infile_name, 'r') as f:
        count = int(f.readline())
        for _ in range(count):
            l = f.readline().split()
            n = int(l[0])
            m = int(l[1])
            p = int(l[2])
            prefers = []
            for _ in range(n):
                prefers.append(tuple(map(int, f.readline().strip())))
            forbids = set()
            for _ in range(m):
                forbids.add(tuple(map(int, f.readline().strip())))
            cases.append((prefers, forbids))
    with open(outfile_name, 'w') as f:
        for idx, case in enumerate(cases, start=1):
            eaten = allowed_min_complain(case[0], case[1])
            line = 'Case #{}: {}'.format(idx, eaten)
            f.write(line + '\n')
            print(line)

main()
