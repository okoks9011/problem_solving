package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	loc := make(map[int64]int)
	loc[0] = -1
	acc := int64(0)
	lastIdx := -1
	result := 0
	for i, ai := range a {
		acc += int64(ai)
		v, ok := loc[acc]
		if ok {
			if v >= lastIdx {
				result++
				lastIdx = i - 1
			}
		}
		loc[acc] = i
	}
	fmt.Println(result)
}
