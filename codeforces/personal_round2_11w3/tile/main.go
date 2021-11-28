package main

import "fmt"

func findSmallestDiv(x int64) int64 {
	for i := int64(2); i*i <= x; i++ {
		if x%i == 0 {
			return i
		}
	}
	return x
}

func main() {
	var n int64
	fmt.Scan(&n)

	v := findSmallestDiv(n)
	if v == n {
		fmt.Println(n)
		return
	}
	for x := n / v; x > 1; x /= v {
		v2 := findSmallestDiv(x)
		if v2 != v {
			fmt.Println(1)
			return
		}
	}
	fmt.Println(v)
}
