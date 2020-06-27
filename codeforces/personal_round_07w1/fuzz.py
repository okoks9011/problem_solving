#!/usr/bin/env python3
import subprocess
import random

MAX_NUM = 10
AI_WIDTH = 10 ** 2
MIN_AI = - AI_WIDTH
MAX_AI = AI_WIDTH


def read_input(input_file):
    with open(input_file, 'r') as f:
        return f.read()

def write_input(input_data):
    h = random.getrandbits(32)
    file_name = f'earray_input_gen_{h:08x}'
    with open(file_name, 'w') as f:
        f.write(input_data)
    print(f'write to {file_name}')


def launch(input_data, target_exec):
    p = subprocess.Popen(target_exec, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    raw_result, _ = p.communicate(input_data.encode('utf-8'))
    return raw_result.decode().strip()


def gen_input():
    result = ''
    n = random.randrange(1, MAX_NUM+1)
    numbers = []
    for _ in range(n):
        numbers.append(random.randrange(MIN_AI, MAX_AI+1))

    result += f'{n}\n'
    result += ' '.join(str(ni) for ni in numbers)
    result += '\n'
    return result


input_file = 'earray_input_1'
input_data = read_input(input_file)

my_exec = './earray'
sol_exec = './earray_sol'
i = 1
while True:
    cur_input = gen_input()
    my_ans = launch(cur_input, my_exec)
    sol_ans = launch(cur_input, sol_exec)
    print(f'Try {i}: =>', end=' ')
    if my_ans == sol_ans:
        print('Ans same')
    else:
        print('Ans diff')
        print(f'{sol_ans} is expected, got {my_ans}')
        write_input(cur_input)
        break
    i += 1
