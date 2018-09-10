# -*- coding: utf-8 -*-

import math

def main():
    n, m, a = [int(s) for s in input().split()]
    r = math.ceil(n / a)
    c = math.ceil(m / a)
    print(r * c)


main()
