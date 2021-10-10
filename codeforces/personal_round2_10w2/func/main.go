package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func count(x int64) int64 {
	result := x
	for x > 0 {
		x /= 10
		result += x
	}
	return result
}

func solve() {
	var l, r int
	fmt.Fscan(in, &l, &r)

	fmt.Println(count(int64(r)) - count(int64(l)))
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
