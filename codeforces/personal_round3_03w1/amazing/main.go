package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  *bufio.Reader
	out *bufio.Writer
)

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

	loc := make(map[int][]int)
	for i := 0; i < n; i++ {
		var ai int
		fmt.Fscan(in, &ai)

		aiLoc, ok := loc[ai]
		if !ok {
			aiLoc = make([]int, 0)
		}
		loc[ai] = append(aiLoc, i)
	}

	minK := make([]int, n+1)
	for i := 1; i <= n; i++ {
		iLoc, ok := loc[i]
		if !ok {
			continue
		}
		iLoc = append(iLoc, n)

		prev := -1
		k := 0
		for _, cur := range iLoc {
			k = max(k, cur-prev)
			prev = cur
		}
		minK[i] = k
	}

	minX := make([]int, n+1)
	for i := 1; i <= n; i++ {
		minX[i] = -1
	}
	for i := 1; i <= n; i++ {
		if minK[i] == 0 {
			continue
		}
		for curK := minK[i]; curK <= n && minX[curK] == -1; curK++ {
			minX[curK] = i
		}
	}

	for i := 1; i <= n; i++ {
		fmt.Fprintf(out, "%d ", minX[i])
	}
	fmt.Fprintln(out)
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
