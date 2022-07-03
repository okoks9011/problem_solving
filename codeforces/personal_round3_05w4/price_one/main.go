package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in = bufio.NewReader(os.Stdin)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func solve() {
	var n, p, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &p)
	fmt.Fscan(in, &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	sort.Ints(a)

	cost, count := make([]int, k), make([]int, k)
	for i := 0; i < k; i++ {
		cost[i] = p
	}

	acc := 0
	initCount := 0
	for i := 1; i < k; i++ {
		if acc+a[i-1] <= cost[i] {
			acc += a[i-1]
			initCount++
		}
		cost[i] -= acc
		count[i] = initCount
	}
	for i := k - 1; i < n; i++ {
		bucket := (i + 1) % k
		if cost[bucket] >= a[i] {
			cost[bucket] -= a[i]
			count[bucket] += k
		}
	}

	result := 0
	for i := 0; i < k; i++ {
		result = max(result, count[i])
	}
	fmt.Println(result)
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
