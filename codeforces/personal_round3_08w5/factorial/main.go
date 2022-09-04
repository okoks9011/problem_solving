package main

import "fmt"

var factorials []int64

func countBits(x int64) int {
	result := 0
	for x != 0 {
		result++
		x &= (x - 1)
	}
	return result
}

func findMinElem(curIdx, spent int, remain int64) int {
	if curIdx >= len(factorials) {
		return spent + countBits(remain)
	}

	result := findMinElem(curIdx+1, spent, remain)
	if remain >= factorials[curIdx] {
		candi := findMinElem(curIdx+1, spent+1, remain-factorials[curIdx])
		if candi < result {
			result = candi
		}
	}
	return result
}

func solve() {
	var n int64
	fmt.Scan(&n)

	fmt.Println(findMinElem(0, 0, n))
}

func main() {
	var t int
	fmt.Scan(&t)

	var cur int64 = 2
	for i := int64(3); i <= 14; i++ {
		cur *= i
		factorials = append(factorials, cur)
	}
	for i := 0; i < t; i++ {
		solve()
	}
}
