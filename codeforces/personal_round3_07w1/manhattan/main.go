package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func isBadTriple(a, b, c int) bool {
	if (a <= b) && (b <= c) {
		return true
	}
	if (a >= b) && (b >= c) {
		return true
	}
	return false
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	var result int64 = int64(n) + int64(n-1)
	for i := 2; i < n; i++ {
		if !isBadTriple(a[i-2], a[i-1], a[i]) {
			result++
		}
	}

	for i := 3; i < n; i++ {
		if isBadTriple(a[i-3], a[i-2], a[i-1]) {
			continue
		}
		if isBadTriple(a[i-3], a[i-2], a[i]) {
			continue
		}
		if isBadTriple(a[i-3], a[i-1], a[i]) {
			continue
		}
		if isBadTriple(a[i-2], a[i-1], a[i]) {
			continue
		}
		result++
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
