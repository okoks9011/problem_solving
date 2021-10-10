package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader

func solve() {
	var n int
	fmt.Fscan(in, &n)

	xs := make([]int, n)
	ys := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &xs[i])
		fmt.Fscan(in, &ys[i])
	}

	if n%2 == 1 {
		fmt.Println(1)
		return
	}

	mid := n / 2
	sort.Ints(xs)
	width := int64(xs[mid] - xs[mid-1] + 1)

	sort.Ints(ys)
	height := int64(ys[mid] - ys[mid-1] + 1)

	fmt.Println(width * height)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
