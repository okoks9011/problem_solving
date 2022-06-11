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

func main() {
	var n int
	fmt.Fscan(in, &n)

	m := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &m[i])
	}

	var maxV int64 = 0
	var result []int
	for start := 0; start < n; start++ {
		curResult := make([]int, n)
		curResult[start] = m[start]
		curSum := int64(m[start])

		limit := m[start]
		for i := start - 1; i >= 0; i-- {
			limit = min(limit, m[i])
			curResult[i] = limit
			curSum += int64(limit)
		}

		limit = m[start]
		for i := start + 1; i < n; i++ {
			limit = min(limit, m[i])
			curResult[i] = limit
			curSum += int64(limit)
		}

		if curSum > maxV {
			maxV = curSum
			result = curResult
		}
	}

	for _, ri := range result {
		fmt.Printf("%d ", ri)
	}
	fmt.Println()
}
