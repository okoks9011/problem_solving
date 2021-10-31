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

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	dp0, dp1 := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		dp0[i], dp1[i] = 1, 1
		if i >= 1 && a[i-1] < a[i] {
			dp0[i] = dp0[i-1] + 1
			dp1[i] = dp1[i-1] + 1
		}

		if i >= 2 && a[i-2] < a[i] && dp0[i-2]+1 > dp1[i] {
			dp1[i] = dp0[i-2] + 1
		}
	}

	maxV := 0
	for _, dp1i := range dp1 {
		if maxV < dp1i {
			maxV = dp1i
		}
	}
	fmt.Println(maxV)
}
