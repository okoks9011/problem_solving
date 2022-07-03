package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

type elem struct {
	idx    int
	remain int
}

func calMaxCoin(cur, k int, p, c []int, dp map[elem]int) int {
	n := len(p)
	if cur >= n {
		return 0
	}
	if k <= 0 {
		return 0
	}

	key := elem{cur, k}
	result, ok := dp[key]
	if ok {
		return result
	}
}

func solve() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b[i])
	}
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &c[i])
	}

	p := make([]int, n)
	for i := 0; i < n; i++ {
		ai := 1
		cnt := 0
		for ai > b[i] {
			remain := b[i] - ai
			x := (ai + remain - 1) / remain
			ai += ai / x
			cnt++
		}
		p[i] = cnt
	}

	dp := make(map[elem]int)
	fmt.Println(calMaxCoin(0, k, p, c, dp))
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
