package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

type point struct {
	x, y int
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	var s string
	fmt.Fscan(in, &s)

	history := make(map[point]int)
	curX, curY := 0, 0
	history[point{curX, curY}] = -1

	start, end := 0, n+2
	for i, c := range s {
		switch c {
		case 'U':
			curY++
		case 'R':
			curX++
		case 'D':
			curY--
		case 'L':
			curX--
		default:
			panic("invalid string")
		}
		last, ok := history[point{curX, curY}]
		if ok && i-last < end-start {
			start = last
			end = i
		}
		history[point{curX, curY}] = i
	}
	if start == 0 && end == n+2 {
		fmt.Println(-1)
	} else {
		fmt.Println(start+2, end+1)
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
