package main

import (
	"bufio"
	"fmt"
	"os"
)

func mainA() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	var s string
	fmt.Fscan(in, &s)

	poketSet := make(map[rune]struct{})
	for _, si := range s {
		poketSet[si] = struct{}{}
	}
	allCnt := len(poketSet)

	result := n
	start, end := 0, 0
	poketMap := make(map[byte]int)
	for ; start < n; start++ {
		poketMap[s[start]]++
		for ; end <= start && len(poketMap) == allCnt; end++ {
			result = min(result, start-end+1)
			if poketMap[s[end]] <= 1 {
				delete(poketMap, s[end])
			} else {
				poketMap[s[end]]--
			}
		}
	}
	fmt.Println(result)
}
