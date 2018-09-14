def serial_qt(qt):
    if type(qt) == type([]):
        result = ['x']
        result.extend(serial_qt(q) for q in qt)
        return ''.join(result)
    else:
        return qt

def reverse_qt(qt):
    if type(qt) == type([]):
        return list(map(reverse_qt, [qt[2], qt[3], qt[0], qt[1]]))
    else:
        return qt

def parse_qt(qt_iter):
    c = next(qt_iter, None)
    if c == 'x':
        result = [parse_qt(qt_iter) for _ in range(4)]
    else:
        result = c
    return result

def main():
    c = int(input().strip())
    for _ in range(c):
        qt_raw = input().strip()
        qt = parse_qt(iter(qt_raw))
        print(serial_qt(reverse_qt(qt)))

main()
