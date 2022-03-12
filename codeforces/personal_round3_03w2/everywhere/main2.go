package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
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

	var s string
	fmt.Fscan(in, &s)

	last := make(map[rune]int)
	for _, si := range s {
		last[si] = -1
	}

	result := n
	for i, si := range s {
		last[si] = i

		curResult := -1
		for _, li := range last {
			if li == -1 {
				curResult = n
				break
			}
			curResult = max(curResult, i-li+1)
		}
		result = min(result, curResult)
	}
	fmt.Println(result)
}
