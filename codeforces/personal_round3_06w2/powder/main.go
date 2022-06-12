package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func possibleToMake(cnt int, a, b []int, k int) bool {
	remain := int64(k)
	for i, ai := range a {
		need := int64(ai) * int64(cnt)
		if need > int64(b[i]) {
			remain -= need - int64(b[i])
		}
		if remain < 0 {
			return false
		}
	}
	return true
}

func main() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b[i])
	}

	left, right := 0, 2_000_000_001
	result := -1
	for left <= right {
		mid := left + (right-left)/2
		if possibleToMake(mid, a, b, k) {
			result = mid
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	fmt.Println(result)
}
