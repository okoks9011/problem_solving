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

	if n%2 == 1 {
		fmt.Println("Bob")
		return
	}

	x := n
	cnt := 0
	for x > 1 {
		x >>= 1
		cnt++
	}
	x <<= cnt
	if x != n {
		fmt.Println("Alice")
	} else {
		if cnt%2 == 0 {
			fmt.Println("Alice")
		} else {
			fmt.Println("Bob")
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
