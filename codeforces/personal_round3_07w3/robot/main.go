package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

type robot struct {
	x, y int
	f    [4]int
}

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	r := make([]robot, n)
	for i := range r {
		fmt.Fscan(in, &r[i].x)
		fmt.Fscan(in, &r[i].y)
		fmt.Fscan(in, &r[i].f[0])
		fmt.Fscan(in, &r[i].f[1])
		fmt.Fscan(in, &r[i].f[2])
		fmt.Fscan(in, &r[i].f[3])
	}

	const limit = 100_001
	maxX, maxY := limit, limit
	minX, minY := -limit, -limit
	for _, ri := range r {
		if ri.f[0] == 0 {
			minX = max(minX, ri.x)
		}
		if ri.f[1] == 0 {
			maxY = min(maxY, ri.y)
		}
		if ri.f[2] == 0 {
			maxX = min(maxX, ri.x)
		}
		if ri.f[3] == 0 {
			minY = max(minY, ri.y)
		}
		if minX > maxX || minY > maxY {
			fmt.Println(0)
			return
		}
	}
	if maxX == limit {
		maxX--
	}
	if maxY == limit {
		maxY--
	}
	fmt.Printf("1 %d %d\n", maxX, maxY)
}

func main() {
	var q int
	fmt.Fscan(in, &q)

	for i := 0; i < q; i++ {
		solve()
	}
}
