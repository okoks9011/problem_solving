package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func solve() {
	var (
		n int
		k int64
	)
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	a := make([]int64, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	var price int64 = 0
	remainCnt := make(map[int64]int)
	for _, ai := range a {
		price += ai / k
		remainCnt[ai%k]++
	}

	for x := int64(0); x < k; x++ {
		for i := k - 1; i >= 0; i-- {
			j := k + x - i
			if j < 0 {
				break
			}
			var v int
			if i != j {
				v = min(remainCnt[i], remainCnt[j])
			} else {
				v = remainCnt[i] / 2
			}
			price += int64(v)
			remainCnt[i] -= v
			remainCnt[j] -= v
		}
	}
	fmt.Println(price)
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
