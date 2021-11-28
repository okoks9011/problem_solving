package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader

func max(a, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	cnt := make(map[int]int)
	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(in, &t)
		cnt[t]++
	}

	var keys []int
	for k := range cnt {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	m := len(keys)
	dp := make([]int64, m+1)
	dp[m-1] = int64(cnt[keys[m-1]]) * int64(keys[m-1])
	for i := m - 2; i >= 0; i-- {
		ki := keys[i]
		dp[i] = int64(cnt[ki]) * int64(ki)
		if keys[i+1]-keys[i] == 1 {
			dp[i] += dp[i+2]
			dp[i] = max(dp[i], dp[i+1])
		} else {
			dp[i] += dp[i+1]
		}
	}
	fmt.Println(dp[0])
}
