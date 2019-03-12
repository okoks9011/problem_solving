from collections import Counter

def exist(counter, clen, b):
    b_counter = Counter(b[:clen-1])
    for k in range(clen-1, len(b)):
        if b[k] not in b_counter:
            b_counter[b[k]] = 0
        b_counter[b[k]] += 1
        if counter == b_counter:
            return True
        b_counter[b[k-clen+1]] -=1
        if b_counter[b[k-clen+1]] == 0:
            b_counter.pop(b[k-clen+1], None)
    return False

def common_anagram(a, b):
    result = 0
    for i in range(len(a)):
        counter = Counter({})
        for j in range(i, len(a)):
            if a[j] not in counter:
                counter[a[j]] = 0
            counter[a[j]] += 1
            if exist(counter, j-i+1, b):
                result += 1
    return result

def main():
    t = int(input().strip())
    for ti in range(t):
        l = int(input().strip())
        a = input().strip()
        b = input().strip()
        r = common_anagram(a, b)
        print('Case #{}: {}'.format(ti+1, r))

main()
