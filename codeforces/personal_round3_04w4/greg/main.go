package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func reverse(s []int) []int {
	n := len(s)
	for i := 0; i < n/2; i++ {
		s[i], s[n-1-i] = s[n-1-i], s[i]
	}
	return s
}

func min(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	dp := make([][]int64, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int64, n)
		for j := 0; j < n; j++ {
			fmt.Fscan(in, &dp[i][j])
		}
	}

	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x[i])
		x[i]--
	}

	result := make([]int64, n)
	x = reverse(x)
	for k := 0; k < n; k++ {
		xk := x[k]
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				dp[i][j] = min(dp[i][j], dp[i][xk]+dp[xk][j])
			}
		}

		var cur int64 = 0
		for i := 0; i <= k; i++ {
			xi := x[i]
			for j := 0; j <= k; j++ {
				xj := x[j]
				cur += dp[xi][xj]
			}
		}
		result[k] = cur
	}

	for i := len(result) - 1; i >= 0; i-- {
		fmt.Printf("%d ", result[i])
	}
	fmt.Println()
}
