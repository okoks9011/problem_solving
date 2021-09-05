package main

import (
	"fmt"
	"sort"
)

func Solve() {
	var x, n int
	fmt.Scan(&n)
	fmt.Scan(&x)

	a := make([]int, 0, n)
	for i := 0; i < n; i++ {
		var tmp int
		fmt.Scan(&tmp)
		a = append(a, tmp)
	}

	if sort.IntsAreSorted(a) {
		fmt.Println(0)
		return
	}

	cnt := 0
	for i := 0; i < n; i++ {
		if a[i] > x {
			x, a[i] = a[i], x
			cnt++
		}
		if sort.IntsAreSorted(a) {
			fmt.Println(cnt)
			return
		}
	}
	fmt.Println(-1)
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		Solve()
	}
}
