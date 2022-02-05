package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func normalize(dCnt, kCnt int) int64 {
	if dCnt == 0 {
		kCnt = 1
	}
	if kCnt == 0 {
		dCnt = 1
	}
	if dCnt != 0 && kCnt != 0 {
		g := gcd(dCnt, kCnt)
		dCnt /= g
		kCnt /= g
	}

	return int64(dCnt)*1000000 + int64(kCnt)
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	var a string
	fmt.Fscan(in, &a)

	dCnt, kCnt := 0, 0
	ratio := make(map[int64]int)
	dp := make([]int, n)
	for i := 0; i < n; i++ {
		if a[i] == 'D' {
			dCnt++
		} else if a[i] == 'K' {
			kCnt++
		} else {
			panic("impossible")
		}

		split := 1
		key := normalize(dCnt, kCnt)
		oldIdx, ok := ratio[key]
		if ok {
			split += dp[oldIdx]
		}
		ratio[key] = i
		dp[i] = split
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", dp[i])
	}
	fmt.Println()
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
