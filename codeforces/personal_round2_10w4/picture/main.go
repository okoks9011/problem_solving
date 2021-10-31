package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	fmt.Println(4 + 3*n)

	fmt.Println(0, 0)
	for i := 0; i <= n; i++ {
		fmt.Println(1+i, i)
		fmt.Println(i, 1+i)
		fmt.Println(1+i, 1+i)
	}
}
