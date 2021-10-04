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

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	total := 0
	for _, ai := range a {
		total ^= ai
	}

	if total == 0 {
		fmt.Println("YES")
		return
	}

	cur := 0
	cnt := 0
	for _, ai := range a {
		cur ^= ai
		if cur == total {
			cnt++
			cur = 0
		}
	}
	if cnt > 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
