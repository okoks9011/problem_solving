package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func solve() {
	var n, l, r int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &l)
	fmt.Fscan(in, &r)

	lefts := make(map[int]int)
	for i := 0; i < l; i++ {
		var t int
		fmt.Fscan(in, &t)
		lefts[t]++
	}

	rights := make(map[int]int)
	for i := 0; i < r; i++ {
		var t int
		fmt.Fscan(in, &t)
		rights[t]++
	}

	// Assume that lefts >= rights
	if l < r {
		l, r = r, l
		lefts, rights = rights, lefts
	}

	// Matched without change
	for color, leftCount := range lefts {
		rightCount, ok := rights[color]
		if !ok {
			continue
		}
		remove := min(leftCount, rightCount)
		lefts[color] -= remove
		l -= remove
		r -= remove
	}

	// Matched with one change
	result := 0
	for _, leftCount := range lefts {
		extras := l - r
		move := min(leftCount/2, extras/2)
		leftCount -= move * 2
		l -= move * 2
		result += move
	}

	// Change direction and change color
	result += (l-r)/2 + (l+r)/2

	fmt.Println(result)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
