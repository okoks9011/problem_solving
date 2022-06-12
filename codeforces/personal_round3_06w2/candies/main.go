package main

import "fmt"

func canEatHalf(x, n int64) bool {
	remain := n
	var eat int64 = 0
	for remain > 0 {
		if remain >= x {
			eat += x
			remain -= x
		} else {
			eat += remain
			remain = 0
		}

		remain -= remain / 10
	}
	return eat*2 >= n
}

func main() {
	var n int64
	fmt.Scan(&n)

	left, right := int64(1), n
	var result int64 = -1
	for left <= right {
		mid := left + (right-left)/2
		if canEatHalf(mid, n) {
			result = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	fmt.Println(result)
}
