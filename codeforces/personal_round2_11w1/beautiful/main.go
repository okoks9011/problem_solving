package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	minV := n
	if minV > m {
		minV = m
	}
	fmt.Println(minV + 1)
	for i := 0; i <= minV; i++ {
		fmt.Println(i, minV-i)
	}
}
