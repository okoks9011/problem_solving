package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n int
	fmt.Fscan(in, &n)

	var s string
	fmt.Fscan(in, &s)

	for i := (n + 1) / 2; i < n; i++ {
		if s[i] == '0' {
			fmt.Printf("%d %d %d %d\n", 1, i+1, 1, i)
			return
		}
	}
	for i := n/2 - 1; i >= 0; i-- {
		if s[i] == '0' {
			fmt.Printf("%d %d %d %d\n", i+1, n, i+2, n)
			return
		}
	}
	fmt.Printf("%d %d %d %d\n", 1, (n+1)/2, n/2+1, n)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
