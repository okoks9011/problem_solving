package main

import "fmt"

func Solve() {
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)

	cnt := make(map[int]int)
	cnt[-1] = 1
	acc := 0
	var result int64

	for i, si := range s {
		acc += int(si - '0')
		result += int64(cnt[i-acc])
		cnt[i-acc]++
	}
	fmt.Println(result)
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		Solve()
	}
}
