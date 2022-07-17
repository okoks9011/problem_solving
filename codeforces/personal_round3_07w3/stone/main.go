package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func canBeSmallest(target int, h []int) bool {
	n := len(h)
	buf := make([]int, n)
	for i := n - 1; i >= 2; i-- {
		necessary := max(0, target-buf[i])
		if h[i] < necessary {
			return false
		}
		passed := (h[i] - necessary) / 3
		buf[i-1] += passed
		buf[i-2] += passed * 2
	}
	return (h[0]+buf[0] >= target) && (h[1]+buf[1] >= target)
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	h := make([]int, n)
	maxV := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &h[i])
		maxV = max(maxV, h[i])
	}

	result := -1
	left, right := 0, maxV
	for left <= right {
		mid := (right-left)/2 + left
		if canBeSmallest(mid, h) {
			result = mid
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	fmt.Println(result)
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
