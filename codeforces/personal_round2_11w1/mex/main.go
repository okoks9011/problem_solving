package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	edges := make([][2]int, n-1)
	cnt := make([]int, n+1)
	for i := 0; i < n-1; i++ {
		var u, v int
		fmt.Fscan(in, &u)
		fmt.Fscan(in, &v)

		cnt[u]++
		cnt[v]++
		edges[i][0] = u
		edges[i][1] = v
	}

	triNode := -1
	for i := 1; i <= n; i++ {
		if cnt[i] >= 3 {
			triNode = i
			break
		}
	}
	if triNode == -1 {
		for i := 0; i < n-1; i++ {
			fmt.Println(i)
		}
		return
	}

	result := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		result[i] = -1
	}
	prePut := 0
	for i := 0; i < n-1; i++ {
		if edges[i][0] == triNode || edges[i][1] == triNode {
			result[i] = prePut
			prePut++
			if prePut >= 3 {
				break
			}
		}
	}
	curPut := 3
	for i := 0; i < n-1; i++ {
		if result[i] == -1 {
			result[i] = curPut
			curPut++
		}
	}
	for _, ri := range result {
		fmt.Println(ri)
	}
}
