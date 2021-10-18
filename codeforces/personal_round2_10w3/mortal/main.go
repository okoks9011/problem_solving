package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func calMinHard(cur, player int, a []int, dp [][2]int) int {
	n := len(a)
	if cur >= n {
		return 0
	}
	if dp[cur][player] != -1 {
		return dp[cur][player]
	}

	point := 0
	result := 0
	if a[cur] == 1 && player == 1 {
		point++
	}
	result = point + calMinHard(cur+1, 1-player, a, dp)

	if cur < n-1 {
		result2 := 0
		if a[cur+1] == 1 && player == 1 {
			point++
		}
		result2 = point + calMinHard(cur+2, 1-player, a, dp)
		result = min(result, result2)
	}

	dp[cur][player] = result
	return dp[cur][player]
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	dp := make([][2]int, n)
	for i := 0; i < n; i++ {
		dp[i][0] = -1
		dp[i][1] = -1
	}
	fmt.Println(calMinHard(0, 1, a, dp))
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
