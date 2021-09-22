package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

	result := make([]int, n+1)
	maxIdx := 1
	for i := 2; i <= n; i++ {
		var ir, mr int
		fmt.Printf("? %d %d\n", i, maxIdx)
		fmt.Scanln(&ir)
		fmt.Printf("? %d %d\n", maxIdx, i)
		fmt.Scanln(&mr)

		if mr > ir {
			result[maxIdx] = mr
			maxIdx = i
		} else if ir > mr {
			result[i] = ir
		} else {
			// Impossible
			return
		}
	}
	result[maxIdx] = n

	fmt.Print("!")
	for i := 1; i <= n; i++ {
		fmt.Printf(" %d", result[i])
	}
	fmt.Println()
}
