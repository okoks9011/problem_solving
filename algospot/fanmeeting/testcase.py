import random

def main():
    h = random.randrange(1000)
    f = random.randrange(h)
    print('f: {}, h: {}'.format(f, h))
    with open('input_file_3', 'w') as fin:
        fin.write('1\n')
        for _ in range(f):
            c = random.choice(['M', 'F'])
            fin.write(c)
            fin.write(' ')
        fin.write('\n')
        for _ in range(h):
            c = random.choice(['M', 'F'])
            fin.write(c)
            fin.write(' ')
        fin.write('\n')
main()
