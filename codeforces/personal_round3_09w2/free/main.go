package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var (
		n int
		k int64
	)
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	a := make([]int64, n)
	aSet := make(map[int64]struct{})
	for i := range a {
		fmt.Fscan(in, &a[i])
		aSet[a[i]] = struct{}{}
	}

	if k == 1 {
		fmt.Println(len(a))
		return
	}

	result := 0
	for _, ai := range a {
		if _, preOk := aSet[ai/k]; ai%k == 0 && preOk {
			continue
		}
		chain := 1
		for next := ai * k; next <= 1e9; next *= k {
			_, nextOk := aSet[next]
			if !nextOk {
				break
			}
			chain++
		}
		result += (chain + 1) / 2
	}
	fmt.Println(result)
}
