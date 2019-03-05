import sys

def max_rectangle(fences, left, right):
    if left > right:
        return 0
    if right == left:
        return fences[left]
    mid = (left + right) // 2
    left_max = max_rectangle(fences, left, mid)
    right_max = max_rectangle(fences, mid+1, right)

    i, j = mid, mid+1
    height = min(fences[i], fences[j])
    middle_max = (j - i + 1) * height
    while True:
        if left < i and j < right:
            if fences[i-1] > fences[j+1]:
                i -= 1
            else:
                j += 1
        elif left < i:
            i -= 1
        elif j < right:
            j += 1
        else:
            break
        height = min(height, fences[i], fences[j])
        middle_max = max(middle_max, (j - i + 1) * height)

    return max(left_max, middle_max, right_max)


def main():
    c = int(input().strip())
    for _ in range(c):
        n = int(input().strip())
        fences = [int(s) for s in input().split()]
        print(max_rectangle(fences, 0, len(fences)-1))


if sys.version_info.major == 2:
    input = raw_input
main()
