package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in     = bufio.NewReader(os.Stdin)
	dpCost []int
)

func calMaxCoin(cur, k int, dp [][]int, coins, costs []int) int {
	if cur >= len(dp) {
		return 0
	}
	if dp[cur][k] != -1 {
		return dp[cur][k]
	}

	result := 0
	if k >= costs[cur] {
		result = calMaxCoin(cur+1, k-costs[cur], dp, coins, costs) + coins[cur]
	}
	if notUse := calMaxCoin(cur+1, k, dp, coins, costs); notUse > result {
		result = notUse
	}

	dp[cur][k] = result
	return result
}

func solve() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	b := make([]int, n)
	for i := range b {
		fmt.Fscan(in, &b[i])
	}
	coins := make([]int, n)
	for i := range coins {
		fmt.Fscan(in, &coins[i])
	}

	costs := make([]int, n)
	costMax := 0
	for i, bi := range b {
		costs[i] = dpCost[bi]
		costMax += costs[i]
	}
	if costMax < k {
		k = costMax
	}

	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, k+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	fmt.Println(calMaxCoin(0, k, dp, coins, costs))
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	dpCost = make([]int, 1001)
	for i := range dpCost {
		dpCost[i] = 1001
	}
	dpCost[1] = 0
	for i := 1; i < len(dpCost); i++ {
		for x := i; x >= 1; x-- {
			j := i + i/x
			if j >= len(dpCost) {
				continue
			}
			dpCost[j] = min(dpCost[j], dpCost[i]+1)
		}
	}

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
