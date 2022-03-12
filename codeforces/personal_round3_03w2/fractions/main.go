package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	if n == 1 {
		fmt.Println(-1)
		return
	}
	fmt.Printf("%d %d %d\n", n, n+1, n*(n+1))
}
