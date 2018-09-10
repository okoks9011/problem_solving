# -*- coding: utf-8 -*-

def gcd(a, b):
    while a % b:
        a, b = b, a % b
    return b

def maximum_d(cities, x):
    distances = set()
    for city in cities:
        distances.add(abs(x - city))
    if 0 in distances:
        distances.remove(0)

    result = None
    for distance in distances:
        if result:
            result = gcd(result, distance)
        else:
            result = distance
    return result

def main():
    n, x = [int(s) for s in input().split()]
    cities = [int(s) for s in input().split()]

    print(maximum_d(cities, x))

main()
