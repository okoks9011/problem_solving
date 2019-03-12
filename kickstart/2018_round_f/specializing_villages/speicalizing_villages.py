from collections import namedtuple

Pair = namedtuple('Pair', ['to', 'length'])

def find_shortest(v, v_list, v_color, vs, target):
    paths = [-1] * (v+1)
    paths[vs] = 0
    chosen = {vs}
    while True:
        min_len = float('inf')
        min_to = None
        min_from = None
        for vi in chosen:
            for to, length in v_list[vi]:
                if to not in chosen and length < min_len:
                    min_len = length
                    min_to = to
                    min_from = vi
        if min_to is None:
            return None
        paths[min_to] = paths[min_from] + min_len
        chosen.add(min_to)
        if v_color[min_to] == target:
            return paths[min_to]

def shortest_path_len_total(v, v_list, v_color):
    result = 0
    for vi in range(1, v+1):
        target = 'V'
        if v_color[vi] == 'V':
            target = 'F'
        vi_path = find_shortest(v, v_list, v_color, vi, target)
        if vi_path is None:
            return None
        result += vi_path
    return result

min_len = None
min_count = None

def special_villages(v, v_list):
    global min_len, min_count
    min_len = float('inf')
    min_count = 0

    def iter_all_cases(chosen, remain):
        global min_len, min_count
        if remain == 0:
            l = shortest_path_len_total(v, v_list, chosen)
            if l is None:
                return
            if l < min_len:
                min_len = l
                min_count = 1
            elif l == min_len:
                min_count += 1
            return

        for c in ['V', 'F']:
            chosen.append(c)
            iter_all_cases(chosen, remain-1)
            chosen.pop()

    iter_all_cases([None], v)
    return min_count

def main():
    t = int(input().strip())
    for ti in range(t):
        v, e = [int(s) for s in input().split()]
        v_list = [set() for _ in range(v+1)]
        for _ in range(e):
            f, t, l = [int(s) for s in input().split()]
            v_list[f].add(Pair(t, l))
            v_list[t].add(Pair(f, l))
        r = special_villages(v, v_list)
        print('Case #{}: {}'.format(ti+1, r))

main()
