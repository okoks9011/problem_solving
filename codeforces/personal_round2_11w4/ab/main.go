package main

import "fmt"

func solve() {
	var a, b int
	fmt.Scan(&a)
	fmt.Scan(&b)

	cur := 1
	for ; a != b; cur++ {
		if a < b {
			a += cur
		} else if b < a {
			b += cur
		} else {
			panic("invalid")
		}
		fmt.Println(a, b)
	}
	fmt.Println(cur - 1)
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		solve()
	}
}
