#!/usr/bin/env python3

import random
import collections

Stone = collections.namedtuple('Stone', ['s', 'e', 'l'])

def gen_input(cases):
    with open('stone_input_gen', 'w') as f:
        f.write('{}\n'.format(len(cases)))
        for stones in cases:
            f.write('{}\n'.format(len(stones)))
            for stone in stones:
                f.write('{} {} {}\n'.format(stone.s, stone.e, stone.l))

def gen_stone(s):
    e = random.randrange(1, 100001)
    l = random.randrange(0, 100001)
    return Stone(s, e, l)

n = 6
cases = []
for _ in range(1000):
    s = random.randrange(1, 100)
    stones = [gen_stone(s) for _ in range(n)]
    cases.append(stones)

gen_input(cases)
