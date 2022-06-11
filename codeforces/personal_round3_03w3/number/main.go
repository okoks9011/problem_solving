package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  *bufio.Reader
	out *bufio.Writer
)

const kMax = 5_000_000

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	factors := make([]int, kMax+1)
	for i := 2; i < len(factors); i++ {
		if factors[i] != 0 {
			continue
		}
		for j := i; j < len(factors); j += i {
			factors[j] = i
		}
	}

	dp := make([]int, kMax+1)
	for i := 2; i < len(dp); i++ {
		dp[i] = dp[i/factors[i]] + 1
	}
	for i := 1; i < len(dp); i++ {
		dp[i] += dp[i-1]
	}

	var t int
	fmt.Fscan(in, &t)
	for i := 0; i < t; i++ {
		var ai, bi int
		fmt.Fscan(in, &ai)
		fmt.Fscan(in, &bi)

		fmt.Fprintln(out, dp[ai]-dp[bi])
	}
}
