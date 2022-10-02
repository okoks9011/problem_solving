package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}

func findMinDiffIdx(x int, ys []int) int {
	minDiff := abs(x - ys[0])
	minDiffIdx := 0
	for i, y := range ys {
		if abs(x-y) < minDiff {
			minDiff = abs(x - y)
			minDiffIdx = i
		}
	}
	return minDiffIdx
}

type line struct {
	ai, bi int
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	b := make([]int, n)
	for i := range b {
		fmt.Fscan(in, &b[i])
	}

	aLefts := []line{
		{0, 0},
		{0, n - 1},
		{0, findMinDiffIdx(a[0], b)},
	}
	aRights := []line{
		{n - 1, 0},
		{n - 1, n - 1},
		{n - 1, findMinDiffIdx(a[n-1], b)},
	}
	bLefts := []line{
		{0, 0},
		{n - 1, 0},
		{findMinDiffIdx(b[0], a), 0},
	}
	bRights := []line{
		{0, n - 1},
		{n - 1, n - 1},
		{findMinDiffIdx(b[n-1], a), n - 1},
	}

	var minSum int64 = 4_000_000_000
	for _, aL := range aLefts {
		for _, aR := range aRights {
			for _, bL := range bLefts {
				for _, bR := range bRights {
					lines := make(map[line]struct{})
					lines[aL] = struct{}{}
					lines[aR] = struct{}{}
					lines[bL] = struct{}{}
					lines[bR] = struct{}{}

					var sum int64 = 0
					for line := range lines {
						sum += int64(abs(a[line.ai] - b[line.bi]))
					}
					if sum < minSum {
						minSum = sum
					}
				}
			}
		}
	}
	fmt.Println(minSum)
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
