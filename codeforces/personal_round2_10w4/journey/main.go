package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func dfs(cur int, adjs [][]int, visited []bool) float64 {
	visited[cur] = true
	childCnt := 0
	distSum := float64(0)
	for _, adj := range adjs[cur] {
		if !visited[adj] {
			childCnt++
			distSum += dfs(adj, adjs, visited)
		}
	}
	visited[cur] = false

	if childCnt == 0 {
		return 0.0
	}
	return 1.0 + (distSum / float64(childCnt))
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	adjs := make([][]int, n)
	for i := 0; i < n-1; i++ {
		var u, v int
		fmt.Fscan(in, &u)
		fmt.Fscan(in, &v)

		u--
		v--
		adjs[u] = append(adjs[u], v)
		adjs[v] = append(adjs[v], u)
	}

	visited := make([]bool, n)
	fmt.Printf("%f\n", dfs(0, adjs, visited))
}
