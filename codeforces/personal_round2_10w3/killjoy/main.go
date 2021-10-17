package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n, x int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &x)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	sum := 0
	allEqual := true
	for _, ai := range a {
		if ai != x {
			allEqual = false
		}
		sum += ai
	}

	if allEqual {
		fmt.Println(0)
	} else if x*n == sum {
		fmt.Println(1)
	} else {
		fmt.Println(2)
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
