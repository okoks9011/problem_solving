# https://codeforces.com/contest/427/problem/C
import sys
import threading
from collections import defaultdict
 
input = sys.stdin.buffer.readline

n = int(input())
costs = [None] + [int(x) for x in input().strip().split()]
m = int(input())
 
g = defaultdict(set)
for _ in range(m):
    u, v = map(int, input().split())
    g[u].add(v)
 
num = [None] * (n + 1)
low = [float('inf')] * (n + 1)
visited = [False] * (n + 1)
 
visit_counter = 0
stack = []
 
scc_set = []
 
 
def dfs(node: int):
    global visit_counter
    visited[node] = True
    visit_counter += 1
    num[node] = low[node] = visit_counter
    stack.append(node)
    for next in g[node]:
        if num[next] is None:
            dfs(next)
            low[node] = min(low[node], low[next])
        elif visited[next]:
            low[node] = min(low[node], num[next])
 
    if num[node] == low[node]:
        scc = []
        while stack:
            popped = stack.pop()
            scc.append(popped)
            visited[popped] = False
            if popped == node:
                break
        scc_set.append(scc)
 
def main():
    for i in range(1, n + 1):
        if num[i] is not None:
            continue
        dfs(i)

    total_cost = 0
    total_count = 1
    _MOD = 1000000007

    # print(scc_set)
    for scc in scc_set:
        min_cost = min(costs[x] for x in scc)
        min_count = sum(1 if costs[x] == min_cost else 0 for x in scc)

        total_cost += min_cost
        total_count *= min_count
        total_count %= _MOD

    print(total_cost, total_count)



sys.setrecursionlimit(300_000)
threading.stack_size(20_000_000)
thread = threading.Thread(target=main)
thread.start()
thread.join()
