# -*- coding: utf-8 -*-

def pair(n):
    even = n // 2
    odd = n // 2 + n % 2
    return even * odd

def main():
    n = int(input())
    print(pair(n))


main()
