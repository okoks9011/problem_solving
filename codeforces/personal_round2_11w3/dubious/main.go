package main

import "fmt"

func solve() {
	var l, r, m int64
	fmt.Scan(&l)
	fmt.Scan(&r)
	fmt.Scan(&m)

	diff := r - l
	for x := l; x <= r; x++ {
		if m/x >= 1 && m%x <= diff {
			fmt.Println(x, m%x+l, l)
			return
		} else if x-m%x <= diff {
			fmt.Println(x, l, l+x-m%x)
			return
		}
	}
	fmt.Println("wrong")
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		solve()
	}
}
