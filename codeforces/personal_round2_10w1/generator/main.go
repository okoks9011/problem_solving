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

	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p[i])
	}

	loc := make([]int, n+1)
	for i, pi := range p {
		loc[pi] = i
	}

	var curEnd int
	nextEnd := n
	i := 1
	for nextEnd > 0 {
		curEnd = nextEnd
		nextEnd = loc[i]
		diff := loc[i] - i
		for ; i <= p[curEnd-1]; i++ {
			if loc[i]-i != diff {
				fmt.Println("No")
				return
			}
		}
	}
	fmt.Println("Yes")
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
