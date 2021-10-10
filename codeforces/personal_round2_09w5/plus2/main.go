package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n, a, b int64
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &a)
	fmt.Fscan(in, &b)

	var x int64 = 1
	for x <= n {
		if x%b == n%b {
			fmt.Println("Yes")
			return
		}
		if a == 1 {
			break
		}
		x *= a
	}
	fmt.Println("No")
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
