import random

ELEM_MAX=1000000

def main():
    with open('input_file_2', 'w') as f:
        f.write('1\n')
        n = random.randrange(70, 100)
        n_list = []
        for _ in range(n):
            n_list.append(random.randrange(-ELEM_MAX, ELEM_MAX))
        m = random.randrange(70, 100)
        m_list = []
        for _ in range(m):
            m_list.append(random.randrange(-ELEM_MAX, ELEM_MAX))
        f.write('{} {}\n'.format(n, m))
        f.write(' '.join(map(str, n_list)) + '\n')
        f.write(' '.join(map(str, m_list)) + '\n')

main()
