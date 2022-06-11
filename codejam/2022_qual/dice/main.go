package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func solve() {
	var n int
	fmt.Fscan(in, &n)

	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &s[i])
	}

	sort.Ints(s)

	cur := 0
	for i := 0; i < n; i++ {
		if cur+1 <= s[i] {
			cur++
		}
	}
	fmt.Fprintln(out, cur)
}

func main() {
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		fmt.Fprintf(out, "Case #%d: ", i+1)
		solve()
	}
}
