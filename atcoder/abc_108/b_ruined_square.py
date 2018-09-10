# -*- coding: utf-8 -*-

def next_point(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    return x2 - dy, y2 + dx

def restore(x1, y1, x2, y2):
    x3, y3 = next_point(x1, y1, x2, y2)
    x4, y4 = next_point(x2, y2, x3, y3)
    return x3, y3, x4, y4

def main():
    x1, y1, x2, y2 = map(int, input().split())
    x3, y3, x4, y4 = restore(x1, y1, x2, y2)
    print(x3, y3, x4, y4)

main()
