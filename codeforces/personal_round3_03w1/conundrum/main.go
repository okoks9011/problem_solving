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

	a, b := 0, 0
	aBase, bBase := 1, 1
	aFlag := true
	for x := n; x > 0; x /= 10 {
		if aFlag {
			a += (x % 10) * aBase
			aBase *= 10
		} else {
			b += (x % 10) * bBase
			bBase *= 10
		}
		aFlag = !aFlag
	}
	fmt.Println(int64(a+1)*int64(b+1) - int64(2))
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
