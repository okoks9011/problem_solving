import random

r, c = 300, 300

with open('rabbit_input_gen', 'w') as f:
    f.write('1\n')
    f.write(f'{r} {c}\n')
    for _ in range(r):
        row = [str(random.randrange(1000)) for _ in range(c)]
        f.write(' '.join(row) + '\n')
