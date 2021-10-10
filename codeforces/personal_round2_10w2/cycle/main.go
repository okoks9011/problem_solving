package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func dfs(cur int, adjs [][]int, comp []int, compCnt int) {
	if comp[cur] != -1 {
		return
	}
	comp[cur] = compCnt

	for _, adj := range adjs[cur] {
		dfs(adj, adjs, comp, compCnt)
	}
}

func checkCycle(group, edgeCnt []int) bool {
	for _, node := range group {
		if edgeCnt[node] != 2 {
			return false
		}
	}
	return true
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	adjs := make([][]int, n)
	edgeCnt := make([]int, n)
	for i := 0; i < m; i++ {
		var v, u int
		fmt.Fscan(in, &v)
		fmt.Fscan(in, &u)
		v--
		u--

		adjs[v] = append(adjs[v], u)
		adjs[u] = append(adjs[u], v)
		edgeCnt[v]++
		edgeCnt[u]++
	}

	comp := make([]int, n)
	for i := range comp {
		comp[i] = -1
	}

	compCnt := 0
	for i := 0; i < n; i++ {
		if comp[i] == -1 {
			dfs(i, adjs, comp, compCnt)
			compCnt++
		}
	}

	compGroup := make(map[int][]int)
	for i, g := range comp {
		compGroup[g] = append(compGroup[g], i)
	}

	result := 0
	for _, group := range compGroup {
		if checkCycle(group, edgeCnt) {
			result++
		}
	}
	fmt.Println(result)
}
