import random

def main():
    h = random.randrange(100000, 100001)
    f = random.randrange(h)
    print('f: {}, h: {}'.format(f, h))
    with open('fanmeeting_input_gen', 'w') as fin:
        fin.write('1\n')
        for _ in range(f):
            c = random.choice(['M', 'F'])
            fin.write(c)
        fin.write('\n')
        for _ in range(h):
            c = random.choice(['M', 'F'])
            fin.write(c)
        fin.write('\n')
main()
