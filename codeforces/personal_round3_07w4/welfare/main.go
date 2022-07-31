package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	lastIdx := make([]int, n)
	for i := range lastIdx {
		lastIdx[i] = -1
	}

	var q int
	fmt.Fscan(in, &q)

	events := make([]int, q)
	payouts := make([]int, q)
	for i := range events {
		var op int
		fmt.Fscan(in, &op)
		if op == 1 {
			var p, x int
			fmt.Fscan(in, &p)
			fmt.Fscan(in, &x)
			p--
			lastIdx[p] = i
			a[p] = x
		} else if op == 2 {
			fmt.Fscan(in, &payouts[i])
		} else {
			panic("impossible")
		}
	}

	accPayouts := make([]int, q+1)
	for i := q - 1; i >= 0; i-- {
		accPayouts[i] = max(accPayouts[i+1], payouts[i])
	}

	for i := 0; i < n; i++ {
		li := lastIdx[i]
		fmt.Printf("%d ", max(a[i], accPayouts[li+1]))
	}
	fmt.Println()
}
