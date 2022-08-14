package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func min(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n int64
	fmt.Fscan(in, &n)

	a := make([]int64, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	diff := make([]int64, n-1)
	for i := range diff {
		diff[i] = abs(a[i+1] - a[i])
	}

	var (
		curMaxDiffer int64 = 0
		curMin       int64 = 0
		acc          int64 = 0
		flip         int64 = 1
	)
	for i := 0; i < len(diff); i++ {
		acc += diff[i] * flip
		curMaxDiffer = max(curMaxDiffer, acc-curMin)
		curMin = min(curMin, acc)
		flip *= -1
	}

	curMin = 0
	acc = 0
	flip = 1
	for i := 1; i < len(diff); i++ {
		acc += diff[i] * flip
		curMaxDiffer = max(curMaxDiffer, acc-curMin)
		curMin = min(curMin, acc)
		flip *= -1
	}

	fmt.Println(curMaxDiffer)
}
