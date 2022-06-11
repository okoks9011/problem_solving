import string
from functools import lru_cache

_DEBUG = True


@lru_cache(None)
def is_mono_tower(tower: str):
    return all(tower[0] == e for e in tower[1:])


def has_edge(a: str, b: str):
    return a[-1] == b[0]


def proc(n, towers):
    for ch in string.ascii_uppercase:
        pre = []
        suf = []
        mid = []
        etc = []
        for e in towers:
            if e[0] == ch and e[-1] == ch:
                mid.append(e)
            elif e[0] == ch:
                pre.append(e)
            elif e[-1] == ch:
                suf.append(e)
            else:
                etc.append(e)

        if len(pre) > 1:
            return None
        if len(suf) > 1:
            return None

        new_str = (suf[0] if suf else '') + (''.join(mid) if mid else '') + (pre[0] if pre else '')
        print('{} {}'.format(ch, new_str))
        if len(new_str) > 0:
            etc.append(new_str)
        towers = etc

    ans = ''.join(towers)

    acc_set = set(ans[0])
    for i in range(1, len(ans)):
        if ans[i] in acc_set:
            if ans[i] != ans[i - 1]:
                return None
        else:
            acc_set.add(ans[i])
    return ans


assert proc(2, 'OY YO'.split()) == None
if _DEBUG:
    assert proc(6, 'A AA BB A BA BB'.split()) == 'BBBBBAAAAA'

assert proc(5, ['CODE', 'JAM', 'MIC', 'EEL', 'ZZZZZ']) == 'ZZZZZJAMMICCODEEEL'

for t in range(1, int(input()) + 1):
    n = int(input())
    towers = input().split()
    ans = proc(n, towers)

    if ans:
        print('Case #{}: {}'.format(t, ans))
    else:
        print('Case #{}: {}'.format(t, 'IMPOSSIBLE'))
