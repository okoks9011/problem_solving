import sys

def multiply(a, b):
    result = [0] * (len(a) + len(b))
    for i in range(len(a)):
        for j in range(len(b)):
            result[i+j] += a[i] * b[j]
    return result

def addition(a, b):
    if len(a) > len(b):
        a, b = b, a
    result = b.copy()
    for i in range(len(a)):
        result[i] += a[i]
    return result

def subtract(a, b):
    l = max(len(a), len(b))
    result = [0] * l
    for i in range(len(a)):
        result[i] += a[i]
    for j in range(len(b)):
        result[j] -= b[j]
    return result

def karatsuba(a, b):
    if not a or not b:
        return []
    if len(a) > len(b):
        a, b = b, a
    if len(b) <= 10:
        return multiply(a, b)

    half = len(b) // 2
    a0, a1 = a[:half], a[half:]
    b0, b1 = b[:half], b[half:]
    a1b1 = karatsuba(a1, b1)
    a0b0 = karatsuba(a0, b0)

    result = [0] * (len(a) + len(b))
    z = subtract(karatsuba(addition(a0, a1), addition(b0, b1)),
                 addition(a1b1, a0b0))
    a1b1 = [0] * half * 2 + a1b1
    z = [0] * half + z
    return addition(addition(a1b1, z), a0b0)


def fanmeeting_multiply(h, f):
    result = multiply(h, f)
    return sum(1 for r in result[len(h)-1:len(f)] if not r)

def main():
    c = int(input().strip())
    for _ in range(c):
        h = []
        for s in reversed(input()):
            if s == 'M':
                h.append(1)
            else:
                h.append(0)
        f = []
        for s in input():
            if s == 'M':
                f.append(1)
            else:
                f.append(0)
        print(fanmeeting_multiply(h, f))

with open('input_file_2') as f:
    sys.stdin = f
    main()
