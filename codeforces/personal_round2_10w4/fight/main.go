package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	var a, b, k int64
	fmt.Fscan(in, &a)
	fmt.Fscan(in, &b)
	fmt.Fscan(in, &k)

	health := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &health[i])
	}

	s := a + b
	skips := make([]int64, n)
	for i, hi := range health {
		remain := hi % s
		if remain == 0 {
			remain += s
		}
		hits := (remain + (a - 1)) / a
		skips[i] = hits - 1
	}
	sort.Slice(skips, func(i, j int) bool { return skips[i] < skips[j] })

	acc := int64(0)
	point := 0
	for i := 0; i < n; i++ {
		if acc+skips[i] > k {
			break
		}
		acc += skips[i]
		point++
	}
	fmt.Println(point)
}
