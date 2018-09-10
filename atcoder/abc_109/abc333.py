#! -*- coding: utf-8 -*-

def main():
    a, b = [int(s) for s in input().split()]
    if (a * b) % 2:
        print('Yes')
    else:
        print('No')

main()
