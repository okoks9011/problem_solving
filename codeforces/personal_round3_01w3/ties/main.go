package main

import (
	"bufio"
	"fmt"
	"os"
)

var out *bufio.Writer

func solve() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n-1; i++ {
		for j := 0; j < n-1-i; j++ {
			if n%2 == 0 && n/2-1 == j {
				fmt.Fprint(out, "0 ")
				continue
			}
			if j < n/2 {
				fmt.Fprint(out, "1 ")
			} else {
				fmt.Fprint(out, "-1 ")
			}
		}
	}
	fmt.Fprintln(out)
}

func main() {
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		solve()
	}
}
