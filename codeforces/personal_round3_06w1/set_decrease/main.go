package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in = bufio.NewReader(os.Stdin)

func solve() {
	var n int
	var k int64
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	a := make([]int64, n)
	var aSum int64 = 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		aSum += a[i]
	}
	if aSum <= k {
		fmt.Println(0)
		return
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	result := aSum - k
	for i := 1; i < n; i++ {
		aSum -= a[n-i] - a[0]

		var decCnt int64 = 0
		if aSum > k {
			minCnt := int64(i + 1)
			decCnt = (aSum - k + minCnt - 1) / minCnt
		}

		cost := decCnt + int64(i)
		if cost < result {
			result = cost
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
