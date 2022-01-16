package main

import "fmt"

func isValid(cur, n, k int64) bool {
	acc := int64(0)
	x := int64(1)
	for cur/x > 0 {
		acc += cur / x
		x *= k
	}
	return n <= acc
}

func main() {
	var n, k int64
	fmt.Scan(&n)
	fmt.Scan(&k)

	left, right := int64(1), int64(1000000000)
	result := int64(-1)
	for left <= right {
		mid := left + (right-left)/2
		if isValid(mid, n, k) {
			result = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	fmt.Println(result)
}
