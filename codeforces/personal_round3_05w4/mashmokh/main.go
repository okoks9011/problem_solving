package main

import (
	"bufio"
	"fmt"
	"os"
)

var out = bufio.NewWriter(os.Stdout)

func main() {
	defer out.Flush()

	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)

	if n == 1 && k == 0 {
		fmt.Fprintln(out, "1")
		return
	}

	count := n / 2
	if count == 0 || k < count {
		fmt.Fprintln(out, "-1")
		return
	}

	k -= count - 1
	fmt.Fprintf(out, "%d %d ", k, k*2)

	cur := 1_000_000_000
	for i := 2; i < n; i++ {
		fmt.Fprintf(out, "%d ", cur)
		cur--
	}
	fmt.Fprintln(out)
}
