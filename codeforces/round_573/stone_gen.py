import random

CNT = 10**5
MAX = 10**9

with open('stone_input_gen', 'w') as f:
    f.write(str(CNT) + '\n')
    for i, v in enumerate(random.sample(range(MAX+1), k=CNT)):
        f.write(str(v))
        if i == CNT-1:
            continue
        f.write(' ')
    f.write('\n')
