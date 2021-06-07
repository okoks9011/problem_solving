package main

import (
	"fmt"
)

func Solve() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)

	freq := [2][]int{}
	result, cnt := make([]int, 0, n), 0
	for _, v := range s {
		si := v - '0'
		other := 1 - si
		var cur int
		if len(freq[other]) == 0 {
			cnt++
			cur = cnt
		} else {
			cur = freq[other][len(freq[other])-1]
			freq[other] = freq[other][:len(freq[other])-1]
		}
		result = append(result, cur)
		freq[si] = append(freq[si], cur)
	}
	fmt.Println(cnt)
	fmt.Println(result...)
	for _, v := range result {
		fmt.Printf("%d ", v)
	}
	fmt.Println()
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		Solve()
	}
}
