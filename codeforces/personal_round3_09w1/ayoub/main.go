package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func CountSubStrings(x int64) int64 {
	// if x == 0, return 0
	return x * (x + 1) / 2
}

func solve() {
	var n, m int64
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	zero, chunks := n-m, m+1
	base, remainder := zero/chunks, zero%chunks
	zeroCount := CountSubStrings(base)*(chunks-remainder) + CountSubStrings(base+1)*remainder
	fmt.Println(CountSubStrings(n) - zeroCount)
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
