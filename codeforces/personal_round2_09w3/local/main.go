package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

	left := 1
	right := n
	for left < right {
		mid := left + (right-left)/2
		var midLeft, midRight int
		fmt.Printf("? %d\n", mid)
		fmt.Scanln(&midLeft)
		fmt.Printf("? %d\n", mid+1)
		fmt.Scanln(&midRight)

		if midLeft < midRight {
			right = mid
		} else if midLeft > midRight {
			left = mid + 1
		} else {
			panic("impossible")
		}
	}
	fmt.Printf("! %d\n", left)
}
