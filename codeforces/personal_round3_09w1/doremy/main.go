package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func canSkip(k, q int, a []int) bool {
	skipLeft := k
	for _, ai := range a {
		if ai > q {
			if skipLeft > 0 {
				skipLeft--
			} else if q > 0 {
				q--
			} else {
				return false
			}
		}
	}
	return true
}

func solve() {
	var n, q int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &q)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	result := -1
	left, right := 0, n
	for left <= right {
		mid := left + (right-left)/2
		if canSkip(mid, q, a) {
			result = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	trials := make([]byte, n)
	skipLeft := result
	curQ := q
	for i, ai := range a {
		if ai > curQ && skipLeft > 0 {
			trials[i] = '0'
			skipLeft--
		} else {
			trials[i] = '1'
		}
	}
	fmt.Println(string(trials))
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
