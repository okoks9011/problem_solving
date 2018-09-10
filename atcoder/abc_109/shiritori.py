#! -*- coding: utf-8 -*-

def shiritori(words):
    history = set()
    pre = None
    for cur in words:
        if cur in history:
            return False
        if pre and pre[-1] != cur[0]:
            return False
        history.add(cur)
        pre = cur
    return True

def main():
    n = int(input())
    words = []
    for _ in range(n):
        words.append(input().strip())
    if shiritori(words):
        print('Yes')
    else:
        print('No')

main()
