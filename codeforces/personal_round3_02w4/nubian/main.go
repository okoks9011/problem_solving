package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader

func possibleToBuy(k int, a []int64, s int64) (bool, int64) {
	b := make([]int64, len(a))
	for i := 0; i < len(a); i++ {
		b[i] = a[i]
		b[i] += int64(i+1) * int64(k)
	}
	sort.Slice(b, func(i, j int) bool {
		return b[i] < b[j]
	})

	var sum int64 = 0
	for i := 0; i < k; i++ {
		sum += b[i]
	}
	return sum <= s, sum
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	var s int64
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &s)

	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	result, minT := -1, s
	left, right := 0, n
	for left <= right {
		mid := left + (right-left)/2
		ok, t := possibleToBuy(mid, a, s)
		if ok {
			result, minT = mid, t
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	fmt.Println(result, minT)
}
