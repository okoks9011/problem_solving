# -*- coding: utf-8 -*-
import itertools

def maximum_yogurt(n, k, A):
    A.sort()

    day = 0
    i = 0
    eaten = 0
    while i < n:
        while i < n and A[i] <= day:
            i += 1
        today = min(k, n - i)
        eaten += today
        i += today
        day += 1
    return eaten


def main():
    cases = []
    file_name = 'A-small-attempt0'
    infile_name = file_name + '.in'
    outfile_name = file_name + '.out'
    with open(infile_name, 'r') as f:
        count = int(f.readline())
        for _ in range(count):
            l = f.readline().split()
            n = int(l[0])
            k = int(l[1])
            A = list(map(int, f.readline().split()))
            cases.append((n, k, A))
    with open(outfile_name, 'w') as f:
        for idx, case in enumerate(cases, start=1):
            eaten = maximum_yogurt(case[0], case[1], case[2])
            line = 'Case #{}: {}'.format(idx, eaten)
            f.write(line + '\n')
            print(line)

main()
