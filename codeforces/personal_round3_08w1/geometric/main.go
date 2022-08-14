package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	if n < 3 {
		fmt.Println("0")
		return
	}

	var (
		len1Cnt = make(map[int]int64)
		len2Cnt = make(map[int]int64)
		len3Cnt = make(map[int]int64)
	)
	for i := 2; i < n; i++ {
		len1Cnt[a[i-2]]++
		if a[i-1]%k == 0 {
			last := a[i-1] / k
			len2Cnt[a[i-1]] += len1Cnt[last]
		}
		if a[i]%k == 0 {
			last := a[i] / k
			len3Cnt[a[i]] += len2Cnt[last]
		}
	}

	var result int64 = 0
	for _, v := range len3Cnt {
		result += v
	}
	fmt.Println(result)
}
