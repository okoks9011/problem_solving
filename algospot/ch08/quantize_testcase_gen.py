import random

def main():
    n = random.randrange(1, 51)
    s = random.randrange(1, 5)
    with open('quantize_input_gen2', 'w') as fout:
        fout.write('1\n')
        fout.write('{} {}\n'.format(n, s))
        for _ in range(n):
            c = random.randrange(1, 1001)
            fout.write('{} '.format(c))
        fout.write('\n')

main()
