package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader
var out *bufio.Writer

func diffAbs(a, b int) int {
	if a > b {
		return a - b
	} else {
		return b - a
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)

	sumA, sumG := 0, 0
	for i := 0; i < n; i++ {
		var ai, gi int
		fmt.Fscan(in, &ai)
		fmt.Fscan(in, &gi)

		if diffAbs(sumA+ai, sumG) <= 500 {
			sumA += ai
			fmt.Fprint(out, "A")
		} else {
			sumG += gi
			fmt.Fprint(out, "G")
		}
	}
	fmt.Fprintln(out)
}
