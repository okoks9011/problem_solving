package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func minWithin(c [6]int) int {
	result := c[0]
	for i := 1; i < 6; i++ {
		if result > c[i] {
			result = c[i]
		}
	}
	return result
}

func main() {
	defer out.Flush()

	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	var s string
	fmt.Fscan(in, &s)

	seeds := []string{
		"abc",
		"acb",
		"bac",
		"bca",
		"cab",
		"cba",
	}

	costs := make([][6]int, n)
	for i, seed := range seeds {
		acc := 0
		for j := 0; j < n; j++ {
			if seed[j%3] != s[j] {
				acc++
			}
			costs[j][i] = acc
		}
	}

	for i := 0; i < m; i++ {
		var l, r int
		fmt.Fscan(in, &l)
		fmt.Fscan(in, &r)
		l--
		r--

		var candi [6]int
		for j := 0; j < 6; j++ {
			left := 0
			if l > 0 {
				left = costs[l-1][j]
			}
			candi[j] = costs[r][j] - left
		}
		fmt.Fprintln(out, minWithin(candi))
	}
}
