package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func solve() {
	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	i := n - 1
	for ; i >= 0; i-- {
		if a[i] != i+1 {
			break
		}
	}
	prob := 1.0
	for j := 0; j < m; j++ {
		var rj int
		var pj float64
		fmt.Fscan(in, &rj)
		fmt.Fscan(in, &pj)

		if rj < i+1 {
			continue
		}
		prob *= (1.0 - pj)
	}
	if i < 0 {
		fmt.Println(1.0)
	} else {
		fmt.Println(1.0 - prob)
	}
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
