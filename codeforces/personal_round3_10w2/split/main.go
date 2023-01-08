package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func calCycleLen(cur int, adjs map[int][]int, visited []bool) int {
	adj, ok := adjs[cur]
	if !ok || len(adj) != 2 {
		panic("impossible")
	}

	visited[cur] = true
	result := 1

	first, second := adj[0], adj[1]
	if !visited[first] {
		result += calCycleLen(first, adjs, visited)
	} else if !visited[second] {
		result += calCycleLen(second, adjs, visited)
	} // visited[first] && visited[second], do nothing
	return result
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	adjs := make(map[int][]int)
	for i := 0; i < n; i++ {
		var ai, bi int
		fmt.Fscan(in, &ai)
		ai--
		fmt.Fscan(in, &bi)
		bi--

		adjAi := adjs[ai]
		adjAi = append(adjAi, bi)
		adjs[ai] = adjAi

		adjBi := adjs[bi]
		adjBi = append(adjBi, ai)
		adjs[bi] = adjBi
	}

	if len(adjs) != n {
		fmt.Println("NO")
		return
	}
	for _, v := range adjs {
		if len(v) != 2 {
			fmt.Println("NO")
			return
		}
	}

	visited := make([]bool, n)
	for i := 0; i < n; i++ {
		if visited[i] {
			continue
		}
		if calCycleLen(i, adjs, visited)%2 == 1 {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
