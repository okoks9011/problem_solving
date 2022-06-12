package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func solve() {
	var n int
	var a, b int64
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &a)
	fmt.Fscan(in, &b)

	var s string
	fmt.Fscan(in, &s)

	result := int64(n)*a + int64(n+1)*b

	p := make([]int, n+1)
	p[0] = 1
	for i := 1; i < n; i++ {
		if s[i-1] == '1' || s[i] == '1' {
			p[i] = 2
			result += b
		} else {
			p[i] = 1
		}
	}
	p[n] = 1

	i := 1
	for i < len(p) {
		for ; i < len(p) && !(p[i-1] == 2 && p[i] == 1); i++ {
		}
		sIdx := i
		for ; i < len(p) && !(p[i-1] == 1 && p[i] == 2); i++ {
		}
		if i >= len(p) {
			break
		}
		eIdx := i
		cnt := int64(eIdx - sIdx)

		if 2*a >= cnt*b {
			result += cnt * b
		} else {
			result += 2 * a
		}
	}
	for i := 0; i < len(p); i++ {
		if p[i] == 2 {
			// For the first and the last zig-zag.
			result += 2 * a
			break
		}
	}
	fmt.Println(result)
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
