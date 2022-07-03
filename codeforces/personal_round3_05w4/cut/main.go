package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

// dfs returns the number of nodes, the number of cuts in this subtree.
func dfs(cur, parent int, adjs [][]int) (int, int) {
	nodes, cuts := 1, 0
	for _, adj := range adjs[cur] {
		if adj == parent {
			continue
		}
		adjNodes, adjCuts := dfs(adj, cur, adjs)
		nodes += adjNodes
		cuts += adjCuts
		if adjNodes%2 == 0 {
			cuts++
		}
	}
	return nodes, cuts
}

func main() {
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

	if n%2 == 1 {
		fmt.Println("-1")
		return
	}
	_, cuts := dfs(0, -1, adjs)
	fmt.Println(cuts)
}
