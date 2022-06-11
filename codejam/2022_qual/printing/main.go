package main

import "fmt"

const inkMax = 1000000

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func solve() {
	var (
		c = inkMax
		m = inkMax
		y = inkMax
		k = inkMax
	)

	for i := 0; i < 3; i++ {
		var ci, mi, yi, ki int
		fmt.Scan(&ci)
		fmt.Scan(&mi)
		fmt.Scan(&yi)
		fmt.Scan(&ki)

		c = min(c, ci)
		m = min(m, mi)
		y = min(y, yi)
		k = min(k, ki)
	}

	if c+m+y+k < 1000000 {
		fmt.Println("IMPOSSIBLE")
		return
	}

	remain := 1000000
	cOut := min(remain, c)
	remain -= cOut
	mOut := min(remain, m)
	remain -= mOut
	yOut := min(remain, y)
	remain -= yOut
	fmt.Printf("%d %d %d %d\n", cOut, mOut, yOut, remain)
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		fmt.Printf("Case #%d: ", i+1)
		solve()
	}
}
