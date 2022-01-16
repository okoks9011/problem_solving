package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var a, b int64
	fmt.Fscan(in, &a)
	fmt.Fscan(in, &b)

	if a == b {
		fmt.Println(0)
		return
	}

	if b > a {
		a, b = b, a
	}
	for x := int64(1); ; x++ {
		v := x * (x + 1) / 2
		if v >= a-b && (a-b)%2 == v%2 {
			fmt.Println(x)
			return
		}
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
