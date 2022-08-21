package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var n, x int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &x)

	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	cnt := make(map[int]int64)

	var result int64 = 0
	for i := 0; i < n; i++ {
		other := a[i] ^ x
		if v, ok := cnt[other]; ok {
			result += v
		}
		cnt[a[i]]++
	}
	fmt.Println(result)
}
