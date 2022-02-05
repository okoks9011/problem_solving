package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n int
	fmt.Fscan(in, &n)

	cnt := make(map[int]int64)
	for i := 0; i < n; i++ {
		var ai int
		fmt.Fscan(in, &ai)
		cnt[ai]++
	}

	result := int64(0)
	for k, vi := range cnt {
		result += vi * (vi - 1) * (vi - 2) / 6
		vt := cnt[k+1] + cnt[k+2]
		result += (vi * (vi - 1) / 2) * vt
		result += (vt * (vt - 1) / 2) * vi
	}
	fmt.Println(result)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
