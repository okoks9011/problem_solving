package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func solve() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	var s string
	fmt.Fscan(in, &s)

	bases := []string{
		"RGB",
		"GBR",
		"BRG",
	}

	result := n
	for _, base := range bases {
		acc := make([]int, n)
		sum := 0
		for i := 0; i < n; i++ {
			if s[i] != base[i%3] {
				sum++
			}
			acc[i] = sum
		}
		result = min(result, acc[k-1])
		for i := k; i < n; i++ {
			result = min(result, acc[i]-acc[i-k])
		}
	}
	fmt.Println(result)
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	for i := 0; i < n; i++ {
		solve()
	}
}
