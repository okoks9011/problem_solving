package main

import "fmt"

func solve() {
	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)

	m := n - k
	i := 1
	for ; i < k-m; i++ {
		fmt.Printf("%d ", i)
	}
	for j := k; j >= i; j-- {
		fmt.Printf("%d ", j)
	}
	fmt.Println()
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		solve()
	}
}
